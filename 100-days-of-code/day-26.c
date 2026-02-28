#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *prev;
        struct node *next;
    };
    
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter element: ");
        scanf("%d", &newnode->data);
        
        newnode->prev = NULL;
        newnode->next = NULL;
        
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    
    temp = head;
    
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}