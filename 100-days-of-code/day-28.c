#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
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
        
        newnode->next = NULL;
        
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    
    if(temp != NULL)
        temp->next = head;
    
    temp = head;
    
    if(head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != head);
    }
}