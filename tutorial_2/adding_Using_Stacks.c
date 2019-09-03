#include<stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
 // Declaring the maximum size of the stack 
int stack1[MAXSIZE];
int stack2[MAXSIZE];  
int stack3[MAXSIZE];  
int top1 = -1,top2 = -1,top3=-1;
void add();

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
		return 0;
		//printf("Stack1 is empty, cannot pop elements\n");
}

void push1(int value){		// push function to insert elements into the stack 
	if(!isFull1()){
		top1 = top1 + 1;
		stack1[top1] = value;
	}
	else
		printf("Stack1 is full, cannot insert more...\n");
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
		return 0;
		//printf("Stack2 is empty, cannot pop elements\n");

}

void push2(int value){		// push function to insert elements into the stack 
	if(!isFull2()){
		top2 = top2 + 1;
		stack2[top2] = value;
	}
	else
		printf("Stack2 is full, cannot insert more...\n");
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
		printf("Stack3 is empty, cannot pop elements\n");
}

void push3(int value){		// push function to insert elements into the stack 
	if(!isFull3()){
		top3 = top3 + 1;
		stack3[top3] = value;
	}
	else
		printf("Stack3 is full, cannot insert more...\n");
	}



// ..................................Start of the main function.................................................................
int main(){
	push1(5);
	push1(8);
	push1(2);
	push1(1);
// 5821
	push2(5);
	push2(4);
	push2(7);
	push2(7);
	push2(7);
	
	add();
    // printf("%d", pop1());


	
	return 0;
	
}

void add(){

	int temp = 0,x1,x2,t;

	while(!isEmpty1() || !isEmpty2()){
		x1 = pop1();
		x2 = pop2();
		t = x1+x2+temp;
		printf("x1 = %d x2 = %d t = %d temp = %d\n",x1,x2,t,temp);
		if (t>9) {
			
			push3(t%10);
			temp=t/10;
		}else
		{
			push3(t);
			 temp = 0;
		}
	}
	
	
	while(!isEmpty3() )
		printf("%d",pop3());
	

}