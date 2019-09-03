#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int q1[CAPACITY];
int q2[CAPACITY];
unsigned int size1  = 0;
unsigned int rear1  = CAPACITY - 1;  
unsigned int front1 = 0;

unsigned int size2  = 0;
unsigned int rear2  = CAPACITY - 1;   
unsigned int front2 = 0;


/* Function declaration for various operations on queue */
int enqueue1(int data);
int dequeue1();
int isFull1();
int isEmpty1();
int enqueue2(int data);
int dequeue2();
int isFull2();
int isEmpty2();


/**
 *------------------------------------------------------------------------ For The STACK      ----------------------------------------------------- 
 */
int pop(){
    if (isEmpty1()) {
        int i = size2-1;
        while(i>0){
            enqueue1(dequeue2());
            i--;
        }
        return dequeue2();
    }else if (isEmpty2()) {
        int i = size1-1;
        while(i>0){
            enqueue2(dequeue1());
            i--;
        }
        return dequeue1();
    }
    
    
}

void push(int value){
    if (isEmpty1()) {
        enqueue2(value);
    }else
    {
        enqueue1(value);
    }
}


/**
 *------------------------------------------------------------------------      MAIN          ----------------------------------------------------- 
 */
int main()
{
     int ch, data;

    /* Run indefinitely until user manually terminates */
    while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  Stack IMPLEMENTATION from Queues PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &ch);

        
        /* Menu control switch */
        switch (ch)
        {
            case 1:
                printf("\nEnter data to push: ");
                scanf("%d", &data);
                push(data);
                printf("Element added to Stack.");
                break;

            case 2:
                data = pop();
                printf("Data => %d", data);
                break;

            case 0:
                printf("Exiting from app.\n");
                exit(0);
        
            default:
                printf("Invalid choice, please input number between (0-2).");
                break;
        }

        printf("\n\n");
    }



    return 0;
}



/**
 *------------------------------------------------------------------------ For Queue 2      ----------------------------------------------------- 
 */
int enqueue2(int data)
{
    if (isFull2()) 
    {
        printf("Q2 is full\n");
        return 0;
    }

    rear2 = (rear2 + 1) % CAPACITY;

    size2++;

    q2[rear2] = data;

    return 1;
}


int dequeue2()
{
    int data = INT_MIN;

    if (isEmpty2())
    {
        printf("Q2 is empty\n");
        return INT_MIN;
    }

    data = q2[front2];

    front2 = (front2 + 1) % CAPACITY;

    size2--;

    return data;
}


int isFull2()
{
    return (size2 == CAPACITY);
}

int isEmpty2()
{
    return (size2 == 0);
}

/**
 *------------------------------------------------------------------------ For Queue 1      ----------------------------------------------------- 
 */
int enqueue1(int data)
{
    if (isFull1()) 
    {   
        printf("Q1 is full\n");
        return 0;
    }

    rear1 = (rear1 + 1) % CAPACITY;

    size1++;

    q1[rear1] = data;

    return 1;
}


int dequeue1()
{
    int data = INT_MIN;

    if (isEmpty1())
    {
        printf("Q1 is empty\n");
        return 0;
    }

    data = q1[front1];

    front1 = (front1 + 1) % CAPACITY;

    size1--;

    return data;
}


int isFull1()
{
    return (size1 == CAPACITY);
}


int isEmpty1()
{
    return (size1 == 0);
}


