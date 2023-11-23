#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
	int *pArr;
	int size;
	int front;
	int rear;
}Queue;

void initQueue(Queue *pQ, int size);
void cleanupQueue(Queue *pQ);


void push(Queue *pQ, int data);
int pop(Queue *pQ);

#endif
