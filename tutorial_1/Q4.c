#include<stdio.h>
int main(){
    int num;
    printf("Input any decimal number : ");
    scanf("%d",&num);
    printf("The Binary value of decimal no. %d is: %d", num, DecimalToBinary(num,1) );

}

int DecimalToBinary(int num,int i){
	
    if(num > 0)
	{
        return ((num%2)*i) + DecimalToBinary((num/2), (i*10));
    }
    
}

