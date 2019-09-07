
#define CAPACITY 100


unsigned int size  = 0;
unsigned int rear  = CAPACITY - 1;  
unsigned int front = 0;

struct tree{
    char data;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
};

typedef struct tree node;

node* queue[CAPACITY];
int isFull()
{
    return (size == CAPACITY);
}

int isEmpty()
{
    return (size == 0);
}



int enqueue(node* data)
{
    if (isFull()) 
    {   
       
        return 0;
    }

    rear = (rear + 1) % CAPACITY;

    size++;

    queue[rear] = data;

    return 1;
}


node *dequeue()
{
    node* data ;

    if (isEmpty())
    {
        
        return 0;
    }

    data = queue[front];

    front = (front + 1) % CAPACITY;

    size--;

    return data;
}





