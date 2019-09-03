#include<stdio.h>

void insert(int pos,int value);
int arr[50]= {1,2,3,4,5,6,7,8,9};
int val,pos,n = 9,i;

int main(){
	
	
	printf("Enter VALUE : ");
	scanf("%d",&val);
    printf("Enter POSITION : ");
	scanf("%d",&pos);
	
	
	printf("Number entered\n");

    insert(pos,val);

	for(i = 0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	
	

	
	return 0;
}

void insert(int pos,int value){
    int i = n;
    while(i>=pos){
        arr[i+1] = arr[i];
        i--;
    }
    n++;
    arr[pos] = value;
}