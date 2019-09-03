#include <stdio.h>

int main(){
	int i;
	char AB[8];
	char A[4] = {'A','A','A','A'};
	char B[4] = {'B','B','B','B'};
	
	for(i=0;i<8;i++)
	{
		if(i%2 == 0)
		{
			AB[i] = A[i/2];
		}if(i%2 == 1)
		{
			AB[i] = B[(i-1)/2];
		}
	}
	
	printf("The characters in merged array : ");
	for(i = 0;i<8;i++)
	{	
		printf("%c ",AB[i]);
	}
	return 0;
}
