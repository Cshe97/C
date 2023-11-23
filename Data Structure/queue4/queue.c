#include "queue.h"
#include <stdlib.h>
#include <assert.h>

void initQueue(Queue *pQ, int size)
{
	pQ->pArr = malloc(sizeof(int) * size);
	assert(pQ->pArr/*!= NULL*/);
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
	assert(pQ->rear != pQ->size);
	pQ->pArr[pQ->rear] = data;
	++pQ->rear;
}

int pop(Queue *pQ)
{
	int result = pQ->pArr[pQ->front];
	assert(pQ->front != pQ->rear);
	++pQ->front;
	return result;
}


