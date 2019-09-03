#include<stdio.h>
int main(){
    int num;
    printf("Input number of terms for the Series (< 20) : ");
    scanf("%d",&num);
    
    printf("The Series are :\n" );
    Fibonacci(num,0,1,0);

}

void Fibonacci(int n,int a,int b,int c){
	if(a==0)
		printf("1 ");
	
	c = a+b;
	printf("%d ",c);
	a=b;
	b=c;
    
    if(n>2)
    	Fibonacci(n-1,a,b,c);
}

