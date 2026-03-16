#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *front=NULL,*rear=NULL;

void push_front(int x)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=front;

    if(front!=NULL)
        front->prev=temp;
    else
        rear=temp;

    front=temp;
}

void push_back(int x)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=rear;

    if(rear!=NULL)
        rear->next=temp;
    else
        front=temp;

    rear=temp;
}

void pop_front()
{
    if(front==NULL){
        printf("Deque empty\n");
        return;
    }

    struct node *temp=front;
    printf("Removed %d\n",front->data);

    front=front->next;

    if(front!=NULL)
        front->prev=NULL;
    else
        rear=NULL;

    free(temp);
}

void pop_back()
{
    if(rear==NULL){
        printf("Deque empty\n");
        return;
    }

    struct node *temp=rear;
    printf("Removed %d\n",rear->data);

    rear=rear->prev;

    if(rear!=NULL)
        rear->next=NULL;
    else
        front=NULL;

    free(temp);
}

void display()
{
    struct node *temp=front;

    if(temp==NULL){
        printf("Deque empty\n");
        return;
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int ch,x;

    while(1)
    {
        printf("\n1 push_front\n2 push_back\n3 pop_front\n4 pop_back\n5 display\n6 exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        if(ch==6)
            break;

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                push_front(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                push_back(x);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                display();
                break;
        }
    }
}