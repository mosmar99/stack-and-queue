#include "task.h"
#include "queue.h"
#include "printer.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    struct printer* p = (struct printer*) malloc(sizeof(struct printer));
    p->page_rate = P;
    p->current_task = NULL;

    struct queue* q = create_queue();

    srand(time(NULL)); // seeds according to current time
    unsigned int t = 1, r;
    struct task* removedTask;
    while (t != T) {
        // a random number between 1 and 2
        r = 1 + rand() % N; 

        printf("\n===== %d =====", t);

        if (t == 1)
        {
            enqueue(q, create_task(t));
        }

        // if printer is busy, print that its busy, time remaining to accompish 
        // task and display the queue
        if(is_busy(p)) {
            printer_status(p);
            tick(p);
            // enqueue half of the time if N = 2
            if (r % N == 0 && t != 1) // check if r % 2, is when r = 2, which it is 50% of t
            {
                enqueue(q, create_task(t));
            }
            display_queue(q);
        } 
        else // printer is not busy and print queue
        {
            printer_status(p);
            // enqueue half of the time if N = 2
            if (r % N == 0 && t != 1) // check if r % 2, is when r = 2, which it is 50% of t
            {
                enqueue(q, create_task(t));
            }
            display_queue(q);
        }
        
        // If the printer is not busy and if a task is waiting, remove the next 
        // task from the print queue and assign it to the printer.
        if(!is_busy(p) && !is_empty(q)) {

            start_next(p, dequeue(q));

            if (p->current_task ==  NULL)
            {
                break;
            }
            

            // set time remaining
            if (p->current_task->pages == 1) {
                p->time_remaining = 2;
            }
            else if (((p->current_task->pages * 15) % 10) == 0) // check if seconds remaining is not a whole number
            {
                p->time_remaining = (p->current_task->pages * 3) / 2;
            } else {  // the answer is a whole number
                p->time_remaining = (((p->current_task->pages * 3) + 1)/2) - 1; // round down if 0.5
            }
            
        }

        if (p->time_remaining - 1 == 0)
        {
            p->current_task = NULL;
        }

        printf("-----------------------------------------\n");
        t++;

    }

    printf("\nSIMULATION ENDS\n");

    system("pause");
    return 0;
}