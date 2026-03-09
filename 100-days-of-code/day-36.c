#include <stdio.h>

#define MAX 100

int q[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if(front == -1)
    {
        front = rear = 0;
        q[rear] = x;
    }
    else
    {
        rear = (rear + 1) % MAX;
        q[rear] = x;
    }
}

void dequeue()
{
    if(front == -1)
        return;

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i;

    if(front == -1)
        return;

    i = front;

    while(1)
    {
        printf("%d ", q[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int n,m,i,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    printf("Enter number of dequeues: ");
    scanf("%d",&m);

    for(i=0;i<m;i++)
        dequeue();

    display();
}