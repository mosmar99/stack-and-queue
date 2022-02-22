#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// declare node
struct node {
	struct node *ptrNodeNext;
	struct task *ptrTaskNext;
};

struct queue* create_queue() {
	struct queue *q = (struct queue*) malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	return q;  
}

void enqueue(struct queue *q, struct task *t) {
    struct node* newTask = (struct node*) malloc(sizeof(struct node)); // dyn. alloc. memory for new task
    newTask->ptrTaskNext = t;
	if (q->front == NULL) // if queue is prev. empty
	{
		q->front = q->rear = newTask;
		q->front->ptrNodeNext = q->rear->ptrNodeNext = NULL;
	}
	else 
	{
		q->rear->ptrNodeNext = newTask;
		q->rear = newTask;
		q->rear->ptrNodeNext = NULL;
	}
}

struct task* dequeue(struct queue *q) {
	if (q->front == NULL) // could also check REAR ==  NULL, means list is empty
	{
		fprintf(stderr, "UNDERFLOW\n");
		return NULL; // there is no task to return since the list is empty
	}
	
	struct node *firstFront = q->front; // save pointer to initial front
	q->front = q->front->ptrNodeNext; // update front, move one step closer to rear
	firstFront->ptrNodeNext = NULL; // detaching it completely from queue
	return firstFront->ptrTaskNext; // return the task to the node pointed by "firstFront" in qeueue
}

void display_queue(struct queue *q) {
	struct node *currNode;
	currNode = q->front;
	if (currNode == NULL) // there is no queue to print
	{
		printf("\nQUEUE IS EMPTY\n");
	}
	else
	{
		printf("\n");
		printf("TASKS IN QUEUE:");
		while (currNode != q->rear) { // loop from front until rear is hit, print all members of the queue
			printf("\nTASK [arrives at %d second, %d pages]", currNode->ptrTaskNext->time_stamp, currNode->ptrTaskNext->pages);
			currNode = currNode->ptrNodeNext;
		}
		printf("\nTASK [arrives at %d second, %d pages]\n", 
		currNode->ptrTaskNext->time_stamp, currNode->ptrTaskNext->pages);
	}
}

int is_empty(struct queue *q) {
	if (q->front == NULL && q->rear == NULL)
	{
		return true;
	}
	return false;
}