#include<stdio.h>

int main()
{
	/*This program decodes an encoded message: letter A is encoded to Z, Z is encoded to A, B is encoded to Y,Y is encoded to B likewise. */
	
	int n,i,d,p;
	printf(" Enter the number of letters in the word : ");
	scanf("%d",&n);
	char exp[n];
	printf(" Enter the word (in Block captal) : ");
	scanf("%s",exp);
	printf(" The original word : ");	
		
	for ( i=0; i<n; i++ )
	{
		d = (int)exp[i];
		//printf("%d ",d);
		p = 155 - d;
		printf("%c",p);
	}
	
	return 0;
}
