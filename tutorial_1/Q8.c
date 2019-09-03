#include<stdio.h>
int main(){
    int n1,n2;
    printf("Input the range to print starting from ");
    scanf("%d",&n1);
   // printf(": ");
    scanf("%d",&n2);
    
    printf("All even numbers from %d to %d are : ",n1,n2);
    OddEvenNums(n1,n2,n1,0);
    
	printf("\nAll odd numbers from %d to %d are : ",n1,n2);
	OddEvenNums(n1,n2,n1,1);
}

void OddEvenNums(int n1,int n2,int x,int odd_even){

    if(x%2 == odd_even)
    	printf("%d ",x);
       
    if(x<n2)
    	OddEvenNums(n1,n2,x+1,odd_even);
}

