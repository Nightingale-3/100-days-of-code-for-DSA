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
    int n, i, key, count = 0;
    
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
    
    printf("Enter key to count: ");
    scanf("%d", &key);
    
    temp = head;
    
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }
    
    printf("%d", count);
}