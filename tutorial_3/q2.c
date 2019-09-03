#include<stdio.h>
#define max 100


int f1 =-1,r1=-1,itemcount =0;
int f2 =-1,r2=-1;

void Enqueue(int queue[] ,int front,int rear,int value){
	if(front ==-1 && rear==-1){
		front = 0;
		rear = 0;
	}
	else if(rear >= max-1){
		printf("OverFlow");
	}
	else{
		rear++;
	}
	
	queue[rear] = value;
	itemcount++;
}

int Dequeue(int queue[],int front,int rear){
	if(front == -1 || front>rear){
	
		printf("Queue is Empty");
	}
	front++;	
	itemcount--;
	return queue[front-1];

}

int Front(int queue[]){
	return queue[front];
}



void Display(int queue[],int front,int rear ){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d  ",queue[i]);
	}
}


int main(){
	int n;
	printf("Enter numbers count : ")
	scanf("%d",&n);
	int q1[n],q2[n];
	
	
	
	
	
	return 0;
}


