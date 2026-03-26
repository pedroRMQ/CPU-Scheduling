#ifndef TASK_H
#define TASK_H

typedef struct {
    char name[50];
    int period;
    int burst;
    
    int remainingBurst;
    int nextDeadline;

    int lost_deadlines;
    int complete_execution;
    int killed;
    
} Task;

#endif 