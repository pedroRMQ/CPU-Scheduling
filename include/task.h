#ifndef TASK_H
#define TASK_H

typedef struct {
    char name[50];
    int period;
    int burst;
    
    
    int remainingBurst;
    int nextDeadline;
    int arrivalTime;
    
} Task;

#endif 