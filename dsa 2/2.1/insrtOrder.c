#include<stdio.h>
#include<conio.h>

void insert(int value);
int arr[50]= {1,2,4,6,8,9,13,21,34,37};
int val,pos=0,n = 10,i=0;

int main(){
	clrscr ();

	printf("Enter VALUE : ");
	scanf("%d",&val);
    
    
    while(val> arr[i]){
        pos++;
        i++;
    }
    
	
	
	printf("Number entered\n");
    insert(val);

	for(i = 0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	
	

	
	return 0;
}

void insert(int value){
    int i = n;
    while(i>=pos){
        arr[i+1] = arr[i];
        i--;
    }
    n++;
    arr[pos] = value;
}

