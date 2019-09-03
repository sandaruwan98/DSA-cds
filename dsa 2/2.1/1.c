#include<stdio.h>
int main(){
	int n;
	float total,mean;
	printf("Enter numbers count : ");
	scanf("%d",&n);
	float arr[n];
	
	printf("Enter numbers\n");
	for(int i = 0;i<n;i++){
		scanf("%f",&arr[i]);
	}
	
	for(int i = 0;i<n;i++){
		total += arr[i];
	}
	mean = total/n;
	//output
	printf("mean of the numbers is %f ",mean);
	return 0;
}
