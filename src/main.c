#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

#define MAX_TASKS 100

int main(int argc, char *argv[]) {
    // 1. Checagem do número de argumentos 
    if (argc != 2) {
        fprintf(stderr, "Erro: Numero incorreto de argumentos.\n");
        fprintf(stderr, "Uso: %s [arquivo_entrada]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 2. Abertura do arquivo 
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Erro: O arquivo de entrada '%s' nao existe ou nao pode ser aberto.\n", argv[1]);
        return EXIT_FAILURE;
    }

    int total_time;
    
    // 3. Leitura do tempo total de simulação [cite: 16]
    if (fscanf(file, "%d", &total_time) != 1) {
        fprintf(stderr, "Erro: Formatacao incorreta. Nao foi possivel ler o [TOTAL TIME].\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    // 4. Leitura das tarefas (Nome, Período, Burst) [cite: 17]
    // O loop continua enquanto conseguir ler exatamente 3 elementos por linha
    while (fscanf(file, "%49s %d %d", tasks[num_tasks].name, &tasks[num_tasks].period, &tasks[num_tasks].burst) == 3) {
        
        // Inicializa os parâmetros dinâmicos da tarefa para o tempo 0
        tasks[num_tasks].remaining_burst = 0; // A tarefa só "chega" nos múltiplos do período
        tasks[num_tasks].next_deadline = tasks[num_tasks].period; 
        
        num_tasks++;
        
        // Evita estouro de buffer caso o arquivo tenha mais tarefas do que o suportado
        if (num_tasks >= MAX_TASKS) {
            fprintf(stderr, "Aviso: Limite maximo de tarefas atingido (%d).\n", MAX_TASKS);
            break; 
        }
    }

    // 5. Verificação de erros de formatação no meio das tarefas 
    // Se o loop parou antes do fim do arquivo, significa que encontrou uma linha mal formatada
    if (!feof(file)) {
        fprintf(stderr, "Erro: Formatacao diferente da indicada encontrada nas tarefas.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

    // --- Apenas para teste: imprimindo para confirmar se leu tudo certo ---
    printf("Tempo total: %d\n", total_time);
    printf("Tarefas carregadas: %d\n", num_tasks);
    for (int i = 0; i < num_tasks; i++) {
        printf("Tarefa: %s | Periodo: %d | Burst: %d\n", tasks[i].name, tasks[i].period, tasks[i].burst);
    }
    // ----------------------------------------------------------------------

    // A partir daqui, você chamará a função que executa a lógica do Rate-Monotonic ou EDF
    // ...

    return EXIT_SUCCESS;
}