#include<stdio.h>
int main(){
	int n,pos,min;
	
	printf("Enter numbers count : ");
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter numbers\n");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	min = arr[0];
	for(int i = 0;i<n;i++){
		if(min>arr[i])
		{
			min = arr[i];
			pos = i+1;
		}
	}
	
	printf("The position of the smallest number is : %d",pos);
	
	return 0;
}
