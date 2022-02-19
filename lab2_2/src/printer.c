#include "printer.h"
#include <stdio.h>
#include <stdbool.h>

void tick(struct printer *p) {
    printf("\n%u seconds to complete the current task.", p->time_remaining);
    p->time_remaining -= 1;
}

int is_busy(struct printer *p) {
    if (p->current_task == NULL)
    {
        return false;
    }
    return true;
}

void start_next(struct printer *p, struct task *t) {
    p->current_task = t;
}

void printer_status(struct printer *p) {
    if (is_busy(p))
    {
        printf("\nTHE PRINTER IS BUSY");
    }
    else
    {
        printf("\nTHE PRINTER IS NO LONGER BUSY");
    }
    
}