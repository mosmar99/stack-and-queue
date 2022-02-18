#include "queue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 2 // 1 print task / N (2) seconds
#define M 5 // length of print tasks ranges between: 1 to M (5) pages
#define P 40 // printer can process P (40) pages / 60 seconds
#define T 10 // simulation runs for 10 seconds

struct queue* create_queue() {
	struct queue* queue = (struct queue*) malloc(sizeof(struct queue));

	return queue;  
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
		fprintf(stderr, "Underflow");
		return;
	}
	
	struct node *ptr = q->front;
	q->front = q->front->ptrNodeNext;
	free(ptr);
	return q;
}

void display_queue(struct queue *q) {
	
}

int is_empty(struct queue *q) {
	if (q->front == NULL && q->rear == NULL)
	{
		return true;
	}
	return false;
}