#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* right;
};

struct node *start;



struct node *newNode(int val){
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	
	
	return newnode;
}

struct node *InsertNode(int val){
	struct node *ptr;
	if(start == NULL){
		start = newNode(val);
		
	}
	else{
		ptr = start;
		if(ptr->next == NULL)
			ptr =	ptr->next ;
		else
		{
			
		
			while(ptr->	next != start){
				ptr = ptr->next;
			}
		}
		
		ptr = newNode(val);
		ptr->next = start;
	
		
		
	}
	
	

}


struct node *delete(int val){
	struct node *ptr,*preptr;
	
		ptr = start;
		if(start->data == val)
			start = start->next;
		preptr = ptr;
	while(ptr->data != val){
			preptr = ptr;
			ptr = ptr->next;
		}
	preptr->next = ptr->next;
	free(ptr);
}


int main(){
	int n,k,i;
	scanf("%d",&n);
	
	scanf("%d",&k);
	
	for(i=,i<=n,i++){
		InsertNode(i);
		
	}
	
	struct node *ptr;
	
	ptr = start;
	
	while(ptr->data != k){
			ptr = ptr->next;
		}
	
	
	return 0;
}
