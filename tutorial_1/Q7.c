#include<stdio.h>
#include<string.h>

int main(){
	
    char string[50];
    
    printf("Input a word to check for palindrome : ");
    scanf("%s",&string);
    
	palindrome_check(string,0,strlen(string));

}

void palindrome_check(char s[],int i,int len){
	 

	    if((len%2 == 1)	&& (s[i] == s[len-i-1])){
	    	if(i < (len-1)/2)
	    		palindrome_check(s,i+1,len);
	    	if(i == (len-1)/2)
	    		printf("The entered word is a palindrome.");
	    	
		}else{
			printf("The entered word is not a palindrome.");
		}
	    
	
	
	
    
}

