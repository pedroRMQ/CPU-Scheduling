#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "file.h"

void givingTasks(Task *tasks, FILE *file, int numTasks) {
    for (int i = 0; i < numTasks; i++) {
        char name[50];
        int period, burst;

        fscanf(file, "%s %d %d", name, &period, &burst);
        defineTask(tasks, name, period, burst, i);
        printf("Task %d: Name=%s, Period=%d, Burst=%d\n", i + 1, tasks[i].name, tasks[i].period, tasks[i].burst);
    }
}

int main(int argc, char *argv[]) { 
    int totalTime;
    FILE *file = checkFileFormat(argc, argv, &totalTime);
    char linha[100];

    Task *tasks = NULL;
    int numTasks = qntdTasks(file);
    tasks = (Task *)malloc(numTasks * sizeof(Task));
    givingTasks(tasks, file, numTasks);

    fgets(linha, sizeof(linha), file);

    printf("tempo total: %d\n", totalTime);
    printf("Primeira task: %s", linha); 
    printf("Numero de tarefas: %d\n", numTasks);

    if(argv[0] == "./rate"){

    }else if(argv[0] == "./edf"){

    }
}