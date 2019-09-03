int main(){
	int n,max1,max;
	
	printf("Enter numbers count : ");
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter numbers\n");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	max = arr[0];
	for(int i = 0;i<n;i++){
		if(max<arr[i])
		{
			max1 = max;
			max = arr[i];
		}
	}
	
	printf("The second largest number is : %d",max1);
	
	return 0;
}
