#include <stdio.h>

long int Factorial( int ) ;

void main(void)
  {
    int n ;
    printf("Input a number for a factorial value \n");
    scanf("%d", &n);
    printf("%ld \n", Factorial(n) ) ;
}

long int Factorial( int n )
{
  long int Result ;
  if ( n == 0 )
    Result = 1 ;
  else
    Result = n * Factorial( n-1 ) ;
  return( Result ) ;
}
