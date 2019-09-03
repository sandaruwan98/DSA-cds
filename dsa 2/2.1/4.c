#include<stdio.h>
int main(){
	int n,num=0,x=1;
	
	printf("Enter number of digits : ");
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter digits\n");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	
	for(int i = 0;i<n;i++){
			num += (arr[n-i-1]*x);
			x*=10;
	}
	
	printf("The number is : %d",num);
	
	return 0;
}
