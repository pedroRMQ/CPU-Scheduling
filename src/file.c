#include <stdio.h>
#include <stdlib.h>
#include "file.h"

FILE *checkFileFormat(int argc, char *argv[], int *total_time) {
    if (argc != 2) {
        fprintf(stderr, "Erro: Numero incorreto de argumentos.\n");
        fprintf(stderr, "Uso: %s [arquivo_entrada]\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "O arquivo de entrada '%s' nao pode ser aberto.\n", argv[1]);
        exit(1);
    }

    if (fscanf(file, "%d", total_time) != 1) {
        fprintf(stderr, "Erro: Formatacao incorreta. Nao foi possivel ler o [TOTAL TIME].\n");
        fclose(file);
        exit(1);
    }
    return file;
}

int qntdTasks(FILE *file) {
    int numTasks = 0;
    char buffer[256];
    
    while (fgets(buffer, sizeof(buffer), file)) {
        if(buffer[0] == '\n') {
            continue;
        }
        numTasks += 1;
    }
    rewind(file);
    fgets(buffer, sizeof(buffer), file);
    
    return numTasks;
}