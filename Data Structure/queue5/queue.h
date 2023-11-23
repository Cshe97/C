#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
	//int *pArr;
	void *pArr;
	int eleSize;
	int size;
	int front;
	int rear;
} Queue;

void initQueue(Queue *pq, int size, int eleSize);
void cleanupQueue(Queue *pq);

//void push(Stack *ps, int data);
//int pop(Stack *ps);
//void pop(Stack *ps, int *pResult);

void push(Queue *pq, const void *pData);

void pop(Queue *pq, void *pResult);

#endif
