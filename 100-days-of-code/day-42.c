#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;
struct node *top = NULL;

void enqueue(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue()
{
    if(front == NULL)
        return -1;

    struct node *temp = front;
    int x = temp->data;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return x;
}

void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    if(top == NULL)
        return -1;

    struct node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main()
{
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &x);
        enqueue(x);
    }

    while(front != NULL)
        push(dequeue());

    while(top != NULL)
        enqueue(pop());

    printf("Reversed queue: ");
    while(front != NULL)
        printf("%d ", dequeue());
}