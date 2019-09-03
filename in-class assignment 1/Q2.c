// paper 02
//Q2

#include <stdio.h>


int main(){
	int n,i,j,unique = 1;
	
	
	printf("Input the number of elements to be stored in the array : ");
	scanf("%d",&n);
	int arr[n];
	
	
	for(i=0;i<n;i++){
		printf("element - %d : ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("The unique elements found in the array are : ");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((arr[i] == arr[j]) && (i!=j))
				unique = 0;
		
		}
		if(unique == 1)
				printf("%d ",arr[i]);
				
		unique = 1;	
	}
	
	
	return 0;
}



