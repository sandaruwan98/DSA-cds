#include<stdio.h>
int main(){
    int num;
    printf("Input any number to find sum of digits : ");
    scanf("%d",&num);
    printf("%d",sumOfdigits(num));

}

int sumOfdigits(int x){

    if(x>0){
        return (x%10 + sumOfdigits(x/10));
    }
}

