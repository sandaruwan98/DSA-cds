#include<stdio.h>
int main(){
    int y;

    printf("%d",natuaral_num(1));

}

void natuaral_num(int x ){

    if(x<50){
     printf("%d ",x);
     natuaral_num(x+1);
    }
}

