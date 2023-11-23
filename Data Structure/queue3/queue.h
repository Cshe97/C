#ifndef QUEUE_H
#define QUEUE_H
#define ARRAYSIZE 100

typedef struct queue{
	int queue[ARRAYSIZE];
	int front;
	int rear;
}Queue;


void initQueue(Queue *pQ);

void push(Queue *pQ, int data);
int pop(Queue *pQ);

#endif
