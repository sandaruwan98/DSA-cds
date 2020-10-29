#include<stdio.h>
#include "mymalloc.h"

int main()
{
	int *p,*q,*r,*s;
	p = (int *)MyMalloc(sizeof(int)*100);
	q = (int *)MyMalloc(sizeof(int)*200);
	r = (int *)MyMalloc(sizeof(int)*300);
	MyFree(q);
	s = (int *)MyMalloc(800);
	
	return 0;
}
