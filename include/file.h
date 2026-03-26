#ifndef FILE_H
#define FILE_H

#include "task.h"

FILE *checkFileFormat(int argc, char *argv[], int *total_time);
int qntdTasks(FILE *file);
void defineTask(Task *task, char *name, int period, int burst, int i);

#endif // FILE_H