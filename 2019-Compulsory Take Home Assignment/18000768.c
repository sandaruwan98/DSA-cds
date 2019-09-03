#include <stdio.h>
#include <stdlib.h>
// Creating the linked list
struct linkedlist{
	int data;
	struct linkedlist* next;
};

typedef struct linkedlist node;
node *start = NULL;

//--------------------------Insert data to the linked list -------------------------------
void insert(int data){
	node* newnode;
	node* ptr;
	newnode = (node*) malloc(sizeof(node));
	newnode -> data = data;
	newnode -> next = NULL;
	if(start == NULL){
		start = newnode;
	}else{
		ptr = start;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		ptr -> next = newnode;
	}
}

//--------------------------Update data in the linked list -------------------------------
void Update(int x,int k){
	
	node* ptr;
	
	if(start != NULL){
		ptr = start;
		int i=1;
		while( i<x && ptr -> next != NULL){
			ptr = ptr -> next;
            i++;
		}

        ptr -> data = k;
	}
}


//--------------------------Check data in the linked list -------------------------------
// int Check(int x,int k){
	
// 	node* ptr;
	
// 	if(start != NULL){
// 		ptr = start;
// 		int i=1;
// 		while( i<x && ptr -> next != NULL){
// 			ptr = ptr -> next;
//             i++;
// 		}

//         return ptr -> data;
// 	}
// }

//swap two elements(use for sorting)
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 


//-------------------------- Sort the elements in given array ------------------------------
int SortData(int arr[],int k,int size){
	int i,j;
	
	for ( i = 0; i < size; i++)
		for ( j = 0; j < (size-i); j++)
			if (arr[i] > arr[j+i])
				swap(&arr[i],&arr[j+i]);
		
	return arr[k-1];
	
}

// Find the number of books on the shelf between the shelves x and y (both inclusive) with the kth rank
int Find(int x,int y,int k){
	
	node* ptr;
	
	if(start != NULL){
		ptr = start;
		int i=1;
		while( i<x && ptr -> next != NULL){
			ptr = ptr -> next;
            i++;
		}
		i =0;
		int arr[100];
		while( i<(y-x+1)){
			arr[i] = ptr ->data;
			ptr = ptr -> next;
            i++;
		}
		
	
		
		return SortData(arr,k,y-x+1);
        
	}
    return 0;
}
// ----------- Delete all data in the linked list ----------------
void DeleteData(){
	if(start != NULL){
		
		node* ptr;
		node* preptr;
        if (start -> next != NULL)
            ptr = start ->next;
		start = NULL;
		while(ptr -> next != NULL){
            preptr = ptr;
			ptr = ptr -> next;
            free(preptr);
		}
    }
}




int main(){
	int testcases,shelf,query;
	printf("Input number of testcases : \n");
    scanf("%d",&testcases);
    int j;
    for ( j = 0; j < testcases ; j++) // loop for each test case
    {
		printf("------------------ Test Case %d ------------------- \n",j+1);
		printf("Input number of shelves : \n");
        scanf("%d",&shelf);
        int i;
	    printf("Input number of books in each shelf : \n");
        for ( i = 0; i < shelf ; i++) //// loop for get number of books in each shelf
        {
            int book;
            scanf("%d",&book);
            insert(book);
        }

	    printf("Input number of queries : \n");
        scanf("%d",&query);
		printf("Enter queries : \n");

        for ( i = 0; i < query ; i++) // loop for each query
        {
			int Qtype;
			scanf("%d",&Qtype);

            if (Qtype == 1) //For update Query
			{
				int x,k;
				scanf("%d %d",&x,&k);
				if (x >= 1 && x <= shelf)
				{
					Update(x,k);
				}else
                {
                    printf("Cannot update because you have entered incorrect shelf number\n");
                }
                
			}

			if (Qtype == 0) // For sort & find Query
			{
				int x,y,k;
				scanf("%d %d %d",&x,&y,&k);
				if (1 <= x &&  x <= y && y <= shelf && 1 <= k && k <= (y-x+1))
				{
					printf("The number of books on shelf : %d\n",Find(x,y,k));
				}else
                {
                    printf("Cannot find the number of books because inputs that you have entered are incorrect\n");
                }
               
				
			}
			
        }
		// Clear the linked list for new test cases
        DeleteData();
    }

	return 0;
}
