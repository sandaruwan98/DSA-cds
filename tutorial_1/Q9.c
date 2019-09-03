#include<stdio.h>
int main(){
    int num;
    printf("Input a number : ");
    scanf("%d",&num);
    
    printf("The Factorial of %d is : %d",num,Factorial(num) );

}

int Factorial(int x){

    if(x>1){
        return x* Factorial(x-1);
    }
}

