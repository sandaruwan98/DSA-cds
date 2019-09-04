#include <stdio.h>



void swap(int *a,int *b ){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partion(int *a,int start,int end){
    int pivot = a[end];
    int pindex = start;

    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot )
        {
            swap(&a[pindex],&a[i]);
            pindex++;
        }
        
    }
    swap(&a[pindex],&a[end]);
    return pindex;

}




void quicksort(int *a,int start,int end){
    if(start>=end) return;
    int pindex = partion(a,start,end);
    quicksort(a,start,pindex-1);
    quicksort(a,pindex+1,end);
  
}



int main(){
    int x[6] = {2,6,7,1,5,4};
    quicksort(x,0,6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d  ",x[i]);
    }
    

    return 0;
}