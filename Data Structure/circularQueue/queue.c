#include "queue.h"
#include <stdlib.h>
#include <assert.h>

void initQueue(Queue *pQ, int size)
{
	pQ->pArr = malloc(sizeof(int) * size);
	assert(pQ->pArr);
	pQ->size = size;
	pQ->front = 0;
	pQ->rear = 0;
}

void cleanupQueue(Queue *pQ)
{
	free(pQ->pArr);
}

void push(Queue *pQ, int data)
{
	//assert(pQ->rear != pQ->size);
	assert((pQ->rear + 1) % pQ->size != pQ->front);
	
	pQ->pArr[pQ->rear] = data;
	//++pQ->rear;
	pQ->rear = (pQ->rear + 1) % pQ->size;
}

int pop(Queue *pQ)
{
	assert(pQ->front != pQ->rear);
	
	int result = pQ->pArr[pQ->front];
	//++pQ->front;
	pQ->front = (pQ->front + 1) % pQ->size;
	
	return result;
}


