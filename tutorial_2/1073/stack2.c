#include<stdio.h>
#include<string.h>

int MAXSIZE =20; // Declaring the maximum size of the stack 
char stack[20];   
int top = -1;
char word[20];
char reverse[20];
int palindrome=0;
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

void palindromeCheck(){

		static int j = 0;
		while(!isEmpty())
		{
		if (word[j] != peek()) 
			palindrome = 1;
		
		
		reverse[j] = pop();
		j++;
		}
		printf("Reverse string : %s\n",reverse);
	}

// Start of the main function....
int main(){
	
	
	int i;
	printf("Input a string : ");
	scanf("%s",&word);


	for( i = 0; i < strlen(word); i++)
	{
		push(word[i]);
		
	}
	
	
	palindromeCheck();
	if (palindrome == 1) {
			printf("Output : This string is not a palindrome.");
	}else
	{
		    printf("Output : This string is a palindrome.");
	}
	
	
	
	
	
	
	
	
	return 0;
	
}
