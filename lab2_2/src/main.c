#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "task.h"
#include "queue.h"
#include "printer.h"

int main(void) {
    struct printer* p = (struct printer*) malloc(sizeof(struct printer));
    p->page_rate = P;
    p->current_task = NULL;
    p->time_remaining = 0;

    struct queue* q = create_queue();

    unsigned int t = T;
    struct task* removedTask;
    while (t) {
        printer_status(p);
        display_queue(q);
        enqueue(q, t);
        if (!is_busy(p) && !is_empty(q))
        {
            removedTask = dequeue(q); // removeTask is not necessary but increases readability
            p->current_task = removedTask;
        }
        printer_status(p);
        display_queue(q);
        tick(p);
        t--;

    }

    return 0;
}