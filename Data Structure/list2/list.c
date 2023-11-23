#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void initList(List *pList)
{
	pList->ptr = malloc(sizeof(Node));	//dummy
	assert(pList->ptr);
	//pList->ptr->data = ??;
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

void insertFirstNode(List *pList, int data)
{
	Node *tmp = malloc(sizeof(Node));
	assert(tmp );
	
	tmp->data = data;
	tmp->next = pList->ptr->next;
	pList->ptr->next = tmp;
}

void insertNode(List *pList, int prevData, int data)
{
	Node *p = pList->ptr->next;
	
	while(p ){
		
		if(prevData == p->data){
			break;
		}
		p = p->next;
	}
	//if find (p != 0)
	if(p ){
		Node *tmp = malloc(sizeof(Node));
		tmp->data = data;
		tmp->next = p->next;
		p->next = tmp;
	} else{
		//do not
	}
}

void deleteNode(List *pList, int data)
{
	Node *p = pList->ptr->next;
	Node *p2 = pList->ptr;
	
	while(p ){
		if(data == p->data){
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

void printList(const List *pList)
{
	Node *p = pList->ptr->next;
	printf("[");
	while(p ){
		printf("%d", p->data);
		printf(( p->next ) ? ", " : " ");
		p = p->next;
	}
	printf("]\n");
}
