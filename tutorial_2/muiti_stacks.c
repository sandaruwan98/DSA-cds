#include<stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
 // Declaring the maximum size of the stack 
int stack1[MAXSIZE];
int stack2[MAXSIZE];  
int stack3[MAXSIZE];  
int top1 = -1,top2 = -1,top3=-1;

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

//----------------------------------------------------STACK 3 ----------------------------------------------------------------


int peek3(){			// peek function to display the top element of the stack
	return stack3[top3];
}

int isFull3(){		// isFull function to check whether the stack is full or not 
	if(top3==MAXSIZE)
		return 1;
	else
		return 0;
}

int isEmpty3(){		// isEmpty function to check whether the stack is empty or not 
	if(top3==-1)
		return 1;
	else
		return 0;
}

int pop3(){			//pop function to delete the top element of the stack 
	if(!isEmpty3()){
		int value;
		value = stack3[top3];
		top3 =  top3 -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push3(int value){		// push function to insert elements into the stack 
	if(!isFull3()){
		top3 = top3 + 1;
		stack3[top3] = value;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}



// ..................................Start of the main function.................................................................
int main(){
	
	
    


	
	return 0;
	
}