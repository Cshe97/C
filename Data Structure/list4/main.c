#include <stdio.h>
#include "list.h"

void printInt(const void *p)
{
	printf("%d", *(int *)p);
}
void printDouble(const void *p)
{
	printf("%f", *(double *)p);
}

int main(void)
{
	List list, list2;
	initList(&list, sizeof(int));
	initList(&list2, sizeof(double));
	
	int i = 4;
	insertFirstNode(&list, &i);		//[4]
	
	i = 3;
	insertFirstNode(&list, &i);		//[3, 4]
	
	i = 1;
	insertFirstNode(&list, &i);		//[1, 3, 4]	
	
	int j = 1;
	i = 2;
	insertNode(&list, &j, &i);		//[1, 2, 3, 4]
	
	i = 3;
	deleteNode(&list, &i);			//[1, 2, 4]
	
	printList(&list,printInt);
	
	double d = 4.4;
	insertFirstNode(&list2, &d);		//[4.4]
	
	d = 3.3;
	insertFirstNode(&list2, &d);		//[3.3, 4.4]
	
	d = 1.1;
	insertFirstNode(&list2, &d);		//[1.1, 3.3, 4.4]
	
	double f = 1.1;
	d = 2.2;
	insertNode(&list2, &f, &d);	//[1.1, 2.2, 3.3, 4.4]
	
	i = 3.3;
	deleteNode(&list2, &d);			//[1.1, 2.2, 4.4]
	
	printList(&list2, printDouble);

	
	cleanupList(&list);
	cleanupList(&list2);
	return 0;
}
