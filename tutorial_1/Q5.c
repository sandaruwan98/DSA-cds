#include<stdio.h>
int main(){
    int count=0;
    int n[100];
    char c[100];
    ////////for input
    printf("input the array element : ");
    scanf("%s",&c);
	char *s = strtok(c, ",");
     while (s != NULL) 
    { 
       
        s = strtok(NULL, ","); 
        n[count] = atoi(s);
        count++;
    } 
	////////////////	
	
	
    
    printf("largest element : %d ", largestElement(n,0,0));

}

int largestElement(int num[],int i,int max){
	
    if(num[i] > max)
	{
    	max = num[i];
    	
    }
    
    if(num[i] != NULL )
	{
		largestElement(num,i+1,max);
    }else{
    	 return max;
	}
    
   
}

