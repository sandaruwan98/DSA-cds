#include<stdio.h>

int MAXSIZE =10; // Declaring the maximum size of the stack 
int stack[10];   
int top = -1;


int peek(){			// peek function to display the top element of the stack
	return stack[top];
}

int isFull(){		// isFull function to check whether the stack is full or not 
	if(top==MAXSIZE)
		return 1;
	else
		return 0;
}

int isEmpty(){		// isEmpty function to check whether the stack is empty or not 
	if(top==-1)
		return 1;
	else
		return 0;
}

int pop(){			//pop function to delete the top element of the stack 
	if(!isEmpty()){
		int value;
		value = stack[top];
		top =  top -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push(int value){		// push function to insert elements into the stack 
	if(!isFull()){
		top = top + 1;
		stack[top] = value;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}

void outPut(){
		printf("Elements of the stack are shown below...\n");
		while(!isEmpty())
		{
		int data = pop();
		printf("%d\n",data);
		
		}
	}


// Start of the main function....
int main(){
	

	int decimal,i=1,binary = 0;
	printf("Enter a decimal Number : ");
    scanf("%d",&decimal);
     
    while(decimal>0){
        push(decimal%2);
        decimal/=2;
        i*=10;
    }
    //outPut();    
    while(!isEmpty()){
        i/=10;
        binary+=((pop())*i);
        
    }
    
    
    printf("Binary number is %d",binary);
	
	
	return 0;
	
}