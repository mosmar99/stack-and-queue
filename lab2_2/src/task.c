#include "task.h"
#include <stdlib.h>

struct task* create_task(int ct) {
    struct task* newTask = (struct task*) malloc(sizeof(struct task));
    newTask->time_stamp = ct;
    newTask->pages = 1 + rand() % M;
    return newTask;
}

int wait_time(struct task *t, int ct) {
    return ct - t->time_stamp;
}