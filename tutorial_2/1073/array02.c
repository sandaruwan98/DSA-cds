#include <stdio.h>

int main(){
	//for input
	int n,m,i,j;
	printf("Enter arr1 numbers count : ");
	scanf("%d",&n);
	int arr1[n];
	printf("Enter arr1 numbers\n");
	for(i = 0;i<n;i++)
	{	
		scanf("%d",&arr1[i]);
	}

	printf("\nEnter arr2 numbers count : ");
	scanf("%d",&m);
	int arr2[m];
	printf("Enter arr2 numbers\n");
	for(i = 0;i<m;i++)
	{	
		scanf("%d",&arr2[i]);
	}
	/////////////////////////////////////////////////
	
	
	int arr3[m+n];
	
	for(i = 0;i<(m+n);i++)
	{	
		if(i<n)
		{
			arr3[i] = arr1[i];
		}else{
			arr3[i]= arr2[i-n];
		}
		
	}
	
	
	printf("The numbers in merged array : ");
	for(j = 0;j<(m+n);j++)
	{	
		printf("%d ",arr3[j]);
	}
	return 0;
}
