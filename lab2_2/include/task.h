
//the interface for the task ADT
//Written by He Tan, Feb 2022
#ifndef TASK_H_ /* Include guard */

#define TASK_H_

//declare task
struct task{
    //the timestamp when the printing task arrives 
    int time_stamp;
    //the number of pages to be printed in the task
    int pages;
};

//create a printing task with the number of pages. 
//parameters:
//  ct, the current time (in second) when the task is created.
//return:
//  the pointer that points to the task
struct task* create_task(int ct);

//compute the waiting time for the task
//parameters:
//  *t, the pointer that points to the printing task
//  ct, the current time (in second)
//return:
//  the waiting time (in seconds)
int wait_time(struct task *t, int ct);

#endif