#include <stdio.h>

int main(){
	int n,i,j,min,sum = 0,pos;
	printf("Enter numbers count : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter numbers\n");
	for(i = 0;i<n;i++)
	{	
		scanf("%d",&arr[i]);
	}
	printf("The numbers entered are : ");
	min = arr[0];
	for(j = 0;j<n;j++)
	{	
		printf("%d ",arr[j]);  
		sum += arr[j];
		if(min > arr[j])
		{
			min = arr[j];
			pos = j+1;	
		}
	}
	printf("\nThe Average of numbers : %d",(sum/n));
	printf("\nThe position of the smallest number is: %d",pos);
	return 0;
}
