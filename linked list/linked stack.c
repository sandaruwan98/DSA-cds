#include <stdio.h>
#include <stdlib.h>
// Creating the linked list
struct linkedlist{
	int data;
	struct linkedlist* next;
};

typedef struct linkedlist node;
node *start = NULL;

void enque(){
	node* ptr;
	ptr = start;
	int x = ptr ->data;
	ptr -> next = start;
}




//--------------------------Insert data to the linked list -------------------------------
void push(int data){
	node* newnode;
	node* ptr;
	newnode = (node*) malloc(sizeof(node));
	newnode -> data = data;
	newnode -> next = NULL;
	if(start == NULL){
		start = newnode;
	}else{
		ptr = start;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		ptr -> next = newnode;
	}
}

//--------------------------Update data in the linked list -------------------------------
void Update(int x,int k){
	
	node* ptr;
	
	if(start != NULL){
		ptr = start;
		int i=1;
		while( i<x && ptr -> next != NULL){
			ptr = ptr -> next;
            i++;
		}

        ptr -> data = k;
	}
}



void Pop(){
	if(start != NULL){
		
		node* ptr;
		node* preptr;
		ptr = start;
		preptr = ptr;
		while (ptr ->next != NULL)
		{
			preptr = ptr;
			ptr = ptr ->next;
		}
		printf("Data = %d",ptr->data);
		preptr ->next = NULL;
		if (ptr == start)
			start = NULL;
		else
			free(ptr);

    }
}




//--------------------------Display the data in linked list -------------------------------
void DisplayData(){
	if(start != NULL){
		
		node* ptr;
		ptr = start;
		printf("%d  ",start -> data);
		
		while(ptr -> next != NULL){
			ptr = ptr -> next;
			printf("%d  ",ptr -> data);
		}
    }
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
        printf("3. Display Data\n");
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
			Pop();
			break;

		case 3:
			DisplayData();
			printf("\n");
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