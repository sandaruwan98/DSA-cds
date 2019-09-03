#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 


void SortData(int arr[],int k,int size){
	int i,j;
	// int size =sizeof(arr)/sizeof(arr[0]);

	
	
	for ( i = 0; i < size; i++)
		for ( j = 0; j < (size-i); j++)
			if (arr[i] > arr[j+i])
				swap(&arr[i],&arr[j+i]);
			
		
	

	
	
}

int main(){
	int b[3],i=0;
   
        int a[5] = {1,5,4,2,9};
        SortData(a,3,5);
        
        for ( i = 0; i < 5; i++)
        {
            printf("%d  ",a[i]);
        }
        
           
        
   
    
    
	
	
	return 0;
}
