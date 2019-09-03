#include<stdio.h>
#define max 100

int queue[max];
int front =-1,rear=-1,itemcount =0;

void Enqueue(int value){
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

int Dequeue(){
	if(front == -1 || front>rear){
	
		printf("Queue is Empty");
	}
	front++;	
	itemcount--;
	return queue[front-1];

}

int Front(){
	return queue[front];
}

int Size(){
	return itemcount;
}

int IsEmpty(){
	if(itemcount == 0)
		return 1;
	else
		return 0;
}

void Display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d  ",queue[i]);
	}
}


int main(){
	Enqueue(10);
	Enqueue(11);
	Enqueue(12);
	Enqueue(12);
	 Dequeue();
	Enqueue(103);
	Enqueue(104);
	 Dequeue();
	Enqueue(10);
	Enqueue(10);
	
	Display();
	
	return 0;
}




