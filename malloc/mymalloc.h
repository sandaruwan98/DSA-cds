#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>


char var[25000];

struct node
{
	struct node *prev;
	int flag;
	void* AStart;
	void* AEnd;
	struct node *next;
};

struct node *start;

void *MyMalloc( size_t);
void MyFree(void *);
void init();
#include "mymalloc.c"

