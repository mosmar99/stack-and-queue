//the interface for the FIFO queue ADT
//Written by He Tan, Feb 2022
#include "task.h"

#ifndef QUEUE_H_ /* Include guard */
#define QUEUE_H_

// declare node
struct node {
	struct node *ptrNodeNext;
	struct task *ptrTaskNext;
};

//declare queue
struct queue {
	struct node *front, *rear;
};

//create a queue
//return the pointer that points to the queue 
struct queue* create_queue();

//add a task into the queue 
//parameters:
//  *q, the pointer that points to queue 
//  *t, the pointer that points to the printing task
void enqueue(struct queue *q, struct task *t);

//delete a task from the queue 
//parameters:
//  *q, the pointer that points to the queue 
//return the dequeued task
struct task* dequeue(struct queue *q);

//display all the tasks in the queue 
//parameters:
//  *q, the pointer that points to the queue 
void display_queue(struct queue *q);

//check whether the queue is empty
//parameters:
//  *q, the pointer that points to the queue 
int is_empty(struct queue *q);


#endif