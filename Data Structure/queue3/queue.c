#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


void initQueue(Queue *pQ)
{
	pQ->front = 0;
	pQ->rear = 0;
}

void push(Queue *pQ, int data)
{
	if(pQ->rear == ARRAYSIZE){
		fprintf(stderr, "Queue is full\n");
		exit(1);
	}
	pQ->queue[pQ->rear] = data;
	++pQ->rear;
}

int pop(Queue *pQ)
{
	if(pQ->rear == pQ->front){
		fprintf(stderr, "Queue is empty\n");
		exit(2);
	}
	
	int result = pQ->queue[pQ->front];
	++pQ->front;
	return result;
}
