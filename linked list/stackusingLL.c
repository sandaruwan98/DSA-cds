#include <stdio.h>
#include <stdlib.h>


// Creating the linked list
struct stack{
    int data;
    struct stack *next;
};

typedef struct stack node;

node* top = NULL;



void push(int val){
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = val;

   if (top == NULL)
   {
       top = newnode;
       top->next = NULL;
   }else
   {
       newnode->next = top;
       top = newnode;
   }
   
    
}

int pop(){
    if (top == NULL)
    {
        return 0;
    }
    
   int val = top->data;
   top = top->next;
   return val;
}








int main(){
    int x,y;
   while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        // printf("4. Get Rear\n");
        // printf("5. Get Front\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &x);

		switch (x)
		{
		case 1:
			printf("Enter element to push : ");
			scanf("%d", &y);
			push(y);
			break;
		
		case 2:
			printf("%d",pop());
			break;

		case 0:
			printf("Exiting from app.\n");
			exit(0);

		default:
			break;
		}
        
       

        printf("\n\n");
    }
    


    return 0;
}