void init()
{
	start = (struct node*)malloc(sizeof(struct node));
	start->prev = NULL;
	start->flag = 0;
	start->AStart = &var[0];
	start->AEnd = &var[24999];
	start->next = NULL;
}

void *MyMalloc( size_t val)
{
	int allocated=0;
	struct node *ptr,*newNode;
	if (!(start))
	{
		init();	
		newNode = (struct node*)malloc(sizeof(struct node));
		start->flag = 1;
		newNode->flag = 0;
		newNode->next = start->next;
		newNode->prev = start;
		newNode->AStart = start->AStart+val;
		newNode->AEnd = start->AEnd;
		start->next = newNode;
		start->AEnd = start->AStart + val-1;
		printf(" Memory has been allocated \n");
		allocated=1;
		return (void*)(start->AStart);
	}
	ptr = start;
	while ( ptr!=NULL )
	{
		if ( !(ptr->flag) )
		{
			if ( ptr->AEnd - ptr->AStart + 1 == val )
			{
				ptr->flag = 1;
				printf(" Exact fitting memory has been found and allocated \n");
				allocated=1;
				return (void*)(ptr->AStart);
			}
			else if( (ptr->AEnd)- (ptr->AStart)+ 1 > val )
			{
				newNode = (struct node*)malloc(sizeof(struct node));
				ptr->flag = 1;
				newNode->flag = 0;
				newNode->next = ptr->next;
				newNode->prev = ptr;
				newNode->AStart = ptr->AStart+val;
				newNode->AEnd = ptr->AEnd;
				ptr->next = newNode;
				ptr->AEnd = ptr->AStart + val-1;
				allocated=1;
				printf(" Memory has been allocated successfully \n");
				return (void*)(ptr->AStart);
			}
		}
		ptr = ptr->next;
	}
	if(allocated==0){
		printf(" The memory cannot be allocated \n");
	}
	
}

void MyFree(void *adr)
{
	int deallocated;
	struct node *ptr,*preptr;
	ptr = start;
	while ( ptr!=NULL )
	{
		if( ptr->AStart==adr )
		{
		if(ptr==start)
		{
			ptr->flag = 0;
			deallocated=1;
				break;
		}
		else if ( (ptr->prev->flag) && (ptr->next->flag)) 
			{
				ptr->flag = 0;
				deallocated=1;
				break;	
			}
			
			else if ( !(ptr->prev->flag) && (ptr->next->flag) )
			{
				ptr->prev->AEnd = ptr->AEnd;
				ptr->prev->next  = ptr->next;
				ptr->next->prev = ptr->prev;
				free(ptr);
				deallocated=1;
				break;
			}
			
			else if ( (ptr->prev->flag) && !(ptr->next->flag) )
			{
				ptr->next->AStart = ptr->AStart;
				ptr->next->prev = ptr->prev;
				ptr->prev->next = ptr->next;
				free(ptr);
				deallocated=1;
				break;
			}
			
			else if ( !(ptr->prev->flag) && !(ptr->next->flag))
			{
				preptr = ptr;
				ptr = ptr->next;
				preptr->prev->AEnd = ptr->AEnd;
				preptr->prev->next = ptr->next;
				ptr->next->prev = preptr->prev;
				free(ptr);
				free(preptr);
				deallocated=1;
				return;
			}
		}
		else
		{
			ptr = ptr->next;
		}
		
	}
	if(deallocated==0)
	{
		printf(" Enter a valid address \n");
	}
	
}


