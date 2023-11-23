#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

void initList(List *pList, int eleSize)
{
	pList->ptr = malloc(sizeof(Node));	//dummy  no data space
	assert(pList->ptr);
	pList->eleSize = eleSize;
	pList->ptr->next = NULL;
}

void cleanupList(List *pList)
{
	Node *p = pList->ptr;
	
	while(p){
		Node *p2 = p;
		p = p->next;
		free(p2);
	}
}

void insertFirstNode(List *pList, const void *pData)
{
	Node *tmp = malloc(sizeof(Node) + pList->eleSize);
	assert(tmp );
	
	//tmp->data = data;
	memcpy( tmp + 1 , pData, pList->eleSize);
	tmp->next = pList->ptr->next;
	pList->ptr->next = tmp;
}

void insertNode(List *pList, const void *pPrevData, const void *pData)
{
	Node *p = pList->ptr->next;
	
	while(p ){
		
		//if(prevData == p->data){
		if( memcmp(pPrevData, p + 1, pList->eleSize) == 0 ){
			break;
		}
		p = p->next;
	}
	//if find (p != 0)
	if(p ){
		Node *tmp = malloc(sizeof(Node) + pList->eleSize);
		//tmp->data = data;
		memcpy(tmp + 1, pData, pList->eleSize);
		tmp->next = p->next;
		p->next = tmp;
	} else{
		//do not
	}
}

void deleteNode(List *pList, const void *pData)
{
	Node *p = pList->ptr->next;
	Node *p2 = pList->ptr;
	
	while(p ){
		//if(data == p->data){
		if(memcmp(pData, p + 1, pList->eleSize) == 0){
			break;
		}
		p = p->next;
		p2 = p2->next;
	}
	//if find (p != 0)
	if(p ){
		p2->next = p->next;
		free(p);
	} else{
		//do not
	}
}

void printList(const List *pList, void (*print)(const void *))
{
	Node *p = pList->ptr->next;
	printf("[");
	while(p ){
		//printf("%d", p->data);
		(*print)(p + 1);				//print(p + 1);
		printf(( p->next ) ? ", " : " ");
		p = p->next;
	}
	printf("]\n");
}
