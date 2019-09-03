// paper 02
//Q1

#include <stdio.h>
#include <string.h>
char maxOcc(char s[],int i,int j);


int main(){
	char s[50];
	
	printf("Input string : ");
	gets(s);
	
	//printf("Maximum occurring character : %c");
	return 0;
}

char maxOcc(char s[],int i,int j){
	static int count = 0;
	if(i<strlen(s)){
	
	
	if(j<strlen(s)){
		if((s[i] == s[j]) && (i!=j)){
			count++;
			maxOcc(s,i,j+1);
		}
	}
	
	count=0;
	maxOcc(s,i+1,0);
	
}
}

