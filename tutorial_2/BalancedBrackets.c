#include<stdio.h>
#include<conio.h>
#include<string.h>

int MAXSIZE =50; // Declaring the maximum size of the stack
char stack[50];
int top = -1;
char input[50];
//char reverse[50];

char peek();
char pop();
void push(char item);




char peek(){			// peek function to display the top element of the stack
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

char pop(){			//pop function to delete the top element of the stack 
	if(!isEmpty()){
		char value;
		value = stack[top];
		top =  top -1;
		return value;
	}
	else
		printf("Stack is empty, cannot pop elements\n");
}

void push(char item)
{ // push function to insert elements into the stack
	if(!isFull()){
		top = top + 1;
		stack[top] = item;
	}
	else
		printf("Stack is full, cannot insert more...\n");
	}



//        Start of the main function....
int main(){
	
	
	int i,valid = 1;
    char temp;
   // clrscr();
	printf("Input the expression : ");
	gets(input);


	for( i = 0; i < strlen(input); i++)
	{
		if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
            push(input[i]);
        }
        if ((input[i] == '}' || input[i] == ']' || input[i] == ')')) {

                if (peek() == '{') {
                    temp = '}';
                }
                if (peek() == '[') {
                    temp = ']';
                }
                if (peek() == '(') {
                    temp = ')';
                }
                pop();
               
            if (temp != input[i]) {
                valid = 0;
                break;
            }
             
        }
      
	}

    
	
    if (valid && isEmpty()) {
        printf("Valid Expression");

    }else
    {
        printf("Invalid Expression");
       
    }
    
    
	
	return 0;
	
}
