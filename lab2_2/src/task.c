#include "task.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MIN 60

struct task* create_task(int ct) {
    srand(time(0));
    struct task* newTask = (struct task*) malloc(sizeof(struct task));
    newTask->time_stamp = ct;
    newTask->pages = 1 + rand() % M;
    return newTask;
}

int wait_time(struct task *t, int ct) {
    return ct - t->time_stamp;
}