#include<stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
 // Declaring the maximum size of the stack 
int stack1[MAXSIZE];
int stack2[MAXSIZE];  
int top1 = -1,top2 = -1;

//----------------------------------------------------STACK 1 ----------------------------------------------------------------


int peek1(){			// peek function to display the top element of the stack
	return stack1[top1];
}

int isFull1(){		// isFull function to check whether the stack is full or not 
	if(top1==MAXSIZE)
		return 1;
	else
		return 0;
}

int isEmpty1(){		// isEmpty function to check whether the stack is empty or not 
	if(top1==-1)
		return 1;
	else
		return 0;
}

int pop1(){			//pop function to delete the top element of the stack 
	if(!isEmpty1()){
		int value;
		value = stack1[top1];
		top1 =  top1 -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push1(int value){		// push function to insert elements into the stack 
	if(!isFull1()){
		top1 = top1 + 1;
		stack1[top1] = value;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}


//----------------------------------------------------STACK 2 ----------------------------------------------------------------

int peek2(){			// peek function to display the top element of the stack
	return stack2[top2];
}

int isFull2(){		// isFull function to check whether the stack is full or not 
	if(top2==MAXSIZE)
		return 1;
	else
		return 0;
}

int isEmpty2(){		// isEmpty function to check whether the stack is empty or not 
	if(top2==-1)
		return 1;
	else
		return 0;
}

int pop2(){			//pop function to delete the top element of the stack 
	if(!isEmpty2()){
		int value;
		value = stack2[top2];
		top2 =  top2 -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push2(int value){		// push function to insert elements into the stack 
	if(!isFull2()){
		top2 = top2 + 1;
		stack2[top2] = value;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}

//---------------------------------------------------- QUEUE ------------------------------------------------------------------

void Enqueue(int val){
    if (isEmpty1()) {
        if (!isEmpty2()) {
            while(!isEmpty2()){
                push1(pop2());
            }

        }
        push2(val);
         while(!isEmpty1()){
                push2(pop1());
            }
    } 
}


int Dequeue(){
    if (isEmpty1()) 
        return pop2();
    else
        return pop1();
      
}


// ..................................Start of the main function.................................................................
int main(){
	
	int ch, data;

    /* Run indefinitely until user manually terminates */
    while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  Queue IMPLEMENTATION from Stacks PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &ch);

        
        /* Menu control switch */
        switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                Enqueue(data);
                printf("Element added to Queue.");
                break;

            case 2:
                data = Dequeue();
                printf("Data => %d", data);
                break;

            case 0:
                printf("Exiting from app.\n");
                exit(0);
        
            default:
                printf("Invalid choice, please input number between (0-2).");
                break;
        }

        printf("\n\n");
    }
	
	
    


	
	return 0;
	
}