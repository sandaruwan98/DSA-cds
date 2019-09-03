#include <stdio.h>
#include <stdbool.h>
 
int main(){
	int n;
	
	printf("Enter numbers count : ");
	scanf("%d",&n);
	int arr[n];
	bool duplicate = false;
	printf("Enter numbers\n");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	
	for(int i = 0;i<n;i++){
		
		for(int j = 0;j<n;j++){
			if((arr[i] == arr[j]) && (i != j)  )
			{
				duplicate = true;	
				
				
			}
		}
	}
	
	
	if(duplicate)
		printf("This array of integers contains a duplicate number.\n");
	
	
	return 0;
}
