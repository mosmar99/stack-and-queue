#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "task.h"
#include "queue.h"
#include "printer.h"
#define MIN 60

int main(void) {
    struct printer* p = (struct printer*) malloc(sizeof(struct printer));
    p->page_rate = P;
    p->current_task = NULL;

    struct queue* q = create_queue();

    unsigned int t = 1;
    struct task* removedTask;
    while (t != T) {

        if (t == 1) // enqueue at first second for console output 
        {
            enqueue(q, create_task(t));
        } 
        else        // enqueues ~50% of the time
        {
            if (1 == (rand() % N)) 
            {
                enqueue(q, create_task(t));
            }
        }
        
        // if not(printer is busy) and not(list is empty), remove the next task from
        // the print queue and assign it to the printer
        if (!is_busy(p) && !is_empty(q))
        {
            printer_status(p);
            display_queue(q);
            removedTask = dequeue(q); // removeTask is not necessary but increases readability
            p->current_task = removedTask;
            p->time_remaining = round(((double)p->current_task->pages * ((double)MIN) / p->page_rate) - 1.0);
        }
        else
        {
            printer_status(p);
            tick(p);
            display_queue(q);
            if (p->time_remaining == 0)
            {
                p->current_task = NULL;
            }
            
        }

        t++;

    }

    printf("\nSIMULATION ENDS");

    return 0;
}