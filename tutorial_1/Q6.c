#include<stdio.h>
int main(){
	char FirstCapital(char s[],int i);
    char string[50];
    
    printf("Input a string to including one or more capital letters : ");
    scanf("%s",&string);
    
    
    printf("The first capital letter appears in the string %s is %c.",string,FirstCapital(string,0) );

}

char FirstCapital(char s[],int i){
	int x = (int) s[i];
	if(x>=65 && x<=90){
		
		return s[i];
	} else if(s[i] != NULL){
		FirstCapital(s,i+1);
	}
    
}

