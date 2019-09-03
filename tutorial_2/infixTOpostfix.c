#include<stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100
 // Declaring the maximum size of the stack 
char stack1[MAXSIZE];
char stack2[MAXSIZE];  
char stack3[MAXSIZE];  
int top1 = -1,top2 = -1,top3=-1;
void ItoP(char in[]);
//----------------------------------------------------STACK 1 ----------------------------------------------------------------


char peek1(){			// peek function to display the top element of the stack
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

char pop1(){			//pop function to delete the top element of the stack 
	if(!isEmpty1()){
		char value;
		value = stack1[top1];
		top1 =  top1 -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push1(char value){		// push function to insert elements into the stack 
	if(!isFull1()){
		top1 = top1 + 1;
		stack1[top1] = value;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}


//----------------------------------------------------STACK 2 ----------------------------------------------------------------

char peek2(){			// peek function to display the top element of the stack
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

char pop2(){			//pop function to delete the top element of the stack 
	if(!isEmpty2()){
		char value;
		value = stack2[top2];
		top2 =  top2 -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push2(char value){		// push function to insert elements into the stack 
	if(!isFull2()){
		top2 = top2 + 1;
		stack2[top2] = value;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}




// ..................................Start of the main function.................................................................
int main(){
	char s[50];
	printf("Enter infix Expression : ");
	scanf("%s",&s);
    ItoP(s);

	while(!isEmpty2()){
		printf("%c",pop2());
	}
	
	
	return 0;
	
}
//-------------------------------------fuction for the convertion --------------------------------------------------------------------
void ItoP(char in[]){
	int i,len = strlen(in);
	for( i = 0; i < len; i++)
	{
		char s =  in[i];
		
		if (s == '(') { ////    check for  (
			push1(s);

		}else if (s == '+' || s == '-' || s == '*' || s == '/' || s == '%') // check operater
		{	
			int loop = 1;
			while(loop){
	
				if (s == '+' || s == '-') { 
					char p = peek1();
					if (p == '*' || p == '/' || p == '%') {
						push2(pop1());
					}else
					{
						loop = 0;
						push1(s);
					}
					
					
				}else
				{
					loop = 0;
					push1(s);
				}
				
			}
			
		}else if (s == ')')
		{
			char p1 = peek1();
			while(p1 != '('){
				push2(pop1());
				p1 = peek1();
			}
			if (p1 == '(') {
				pop1();
			}
			
			
		}else
		{
			push2(s);
		}
		
		


	}

	while(!isEmpty1()){
		push2(pop1());

	}
	
	
}