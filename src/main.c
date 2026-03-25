#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "file.h"


int main(int argc, char *argv[]) { 
    int totalTime;
    FILE *file = checkFileFormat(argc, argv, &totalTime);
    char linha[100];

    Task *tasks = NULL;
    int numTasks = qntdTasks(file);
    tasks = (Task *)malloc(numTasks * sizeof(Task));
    
    fgets(linha, sizeof(linha), file);

    printf("Linha lida: %d\n", totalTime);
    printf("Teste: %s\n", linha); 
    printf("Numero de tarefas: %d\n", numTasks);
}