#include<stdio.h>
int main(){
    int num1,num2;
    
    printf("Input 1st number: ");
    scanf("%d",&num1);
    printf("Input 2nd number: ");
    scanf("%d",&num2);
    
    printf("The GCD of %d and %d is: %d",num1,num2, gcd(num1,num2) );

}

int gcd(int n1,int n2){
	
    if((n1%n2) == 0)
	{
    	
        return n2;
    }else
	{
    	gcd(n2,(n1%n2));
	}
}

