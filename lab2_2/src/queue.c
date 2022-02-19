#include "queue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue* create_queue() {
	struct queue *q = (struct queue*) malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	return q;  
}

void enqueue(struct queue *q, struct task *t) {
    struct node* newTask = (struct node*) malloc(sizeof(struct node));
    newTask->ptrTaskNext = t;
	if (q->front == NULL)
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
	if (q->front == NULL) // could also check REAR ==  NULL
	{
		fprintf(stderr, "\n UNDERFLOW");
		return q;
	}
	
	struct node *ptr = q->front;
	q->front = q->front->ptrNodeNext;
	free(ptr);
	return q;
}

void display_queue(struct queue *q) {
	struct node *currNode;
	currNode = q->front;
	if (currNode == NULL)
	{
		printf("\n QUEUE IS EMPTY");
	}
	else
	{
		printf("\n");
		while (currNode != q->rear) {
			printf("TASKS IN QUEUE");
			printf("TASK [arrives at %d second, %d pages]", 
			currNode->ptrTaskNext->time_stamp, currNode->ptrTaskNext->pages);
			currNode = currNode->ptrNodeNext;
		}
		printf("TASKS IN QUEUE");
		printf("TASK [arrives at %d second, %d pages]", 
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