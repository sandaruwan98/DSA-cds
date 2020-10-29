#include<stdio.h>

int main()
{
	/*this program clacutes whether a given date is a crime date or not. If the date is an odd number there will be a crime.*/
	
	int date,k;
	printf(" Enter the date : ");
	scanf("%d",&date);
	for ( k=2; k<date/2; k++ )
	{
		if ( date%2==0 )
		{
			printf(" There won't be any crime ");
			break;
		}
		else
		{
			printf(" There will be a crime ");
			break;
		}
	}
	
	return 0;
}
