#include <stdio.h>
#include <stdlib.h>


// Creating the linked list
struct que{
    int data;
    struct que *next;
};

typedef struct que node;

node* top = NULL;

int dq(){

}

void enq(){
    
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
			enq(y);
			break;
		
		case 2:
			printf("%d",dq());
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