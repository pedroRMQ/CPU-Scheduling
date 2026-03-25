#ifndef TASK_H
#define TASK_H

typedef struct {
    char name[50];
    int period;
    int burst;
    
    
    int remaining_burst;
    int next_deadline;
    int arrival_time;
    
} Task;

#endif 