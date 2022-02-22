#include "task.h"
#include <stdlib.h>

struct task* create_task(int ct) { 
    struct task* newTask = (struct task*) malloc(sizeof(struct task)); // dyn. alloc. memory for a task
    newTask->time_stamp = ct; // timestamp is set to current time
    newTask->pages = 1 + rand() % M; // generate a random set of pages between 1 and M
    return newTask;
}

int wait_time(struct task *t, int ct) {
    return ct - t->time_stamp;
}