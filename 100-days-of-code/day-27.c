#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    
    struct node *head1 = NULL, *head2 = NULL, *temp = NULL, *newnode = NULL;
    int n, m, i, len1 = 0, len2 = 0, diff;
    
    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter element: ");
        scanf("%d", &newnode->data);
        
        newnode->next = NULL;
        
        if(head1 == NULL)
        {
            head1 = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    
    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    
    temp = NULL;
    
    for(i = 0; i < m; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter element: ");
        scanf("%d", &newnode->data);
        
        newnode->next = NULL;
        
        if(head2 == NULL)
        {
            head2 = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    
    temp = head1;
    while(temp != NULL)
    {
        len1++;
        temp = temp->next;
    }
    
    temp = head2;
    while(temp != NULL)
    {
        len2++;
        temp = temp->next;
    }
    
    struct node *p1 = head1;
    struct node *p2 = head2;
    
    if(len1 > len2)
    {
        diff = len1 - len2;
        while(diff--)
            p1 = p1->next;
    }
    else
    {
        diff = len2 - len1;
        while(diff--)
            p2 = p2->next;
    }
    
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data == p2->data)
        {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    printf("No Intersection");
}