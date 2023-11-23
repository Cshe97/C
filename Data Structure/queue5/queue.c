#include "queue.h"
//#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void initQueue(Queue *pq, int size, int eleSize)
{
	//pq->pArr = malloc(sizeof(int) * size);
	pq->pArr = malloc(eleSize * size);
	assert(pq->pArr /*!= NULL*/);
	
	pq->eleSize = eleSize;
	pq->size = size;
	pq->rear = 0;
	pq->front = 0;
}

void cleanupQueue(Queue *pq)
 {
 	free(pq->pArr);
 }

//void push(Stack *pq, int data)
void push(Queue *pq, const void *pData)
{
	assert(pq->rear != pq->size);	
		
	//pq->pArr[pq->tos] = data;
	//memcpy(&pq->pArr[pq->tos], pData, pq->eleSize); //??
	memcpy((unsigned char *)pq->pArr + pq->eleSize * pq->rear, pData, pq->eleSize);
	++pq->rear;
}
/*
int pop(Stack *pq)
{
	assert(pq->tos != 0);
	
	--pq->tos;
	return pq->pArr[pq->tos];
}
*/
//void pop(Stack *pq, int *pResult)
void pop(Queue *pq, void *pResult)
{
	assert(pq->front != pq->rear);
	///////////////////////////////////////here///////////////////////
	
	//*pResult = pq->pArr[pq->tos];
	//memcpy(pResult, &pq->pArr[pq->tos], pq->eleSize);
	memcpy(pResult, (unsigned char *)pq->pArr + pq->eleSize * pq->front, pq->eleSize);
	++pq->front;
}

