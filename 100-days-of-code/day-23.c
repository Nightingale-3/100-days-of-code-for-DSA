#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    int n,m,i,x;
    struct Node *head1=NULL,*head2=NULL,*temp=NULL,*newnode=NULL;
    struct Node *p1,*p2,*merged=NULL,*tail=NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d",&n);
    printf("Enter elements of first list: ");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=NULL;
        if(head1==NULL){
            head1=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    printf("Enter number of elements in second list: ");
    scanf("%d",&m);
    printf("Enter elements of second list: ");
    for(i=0;i<m;i++){
        scanf("%d",&x);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=NULL;
        if(head2==NULL){
            head2=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    p1=head1;
    p2=head2;

    if(p1==NULL)
        merged=p2;
    else if(p2==NULL)
        merged=p1;
    else{
        if(p1->data <= p2->data){
            merged=p1;
            p1=p1->next;
        }
        else{
            merged=p2;
            p2=p2->next;
        }
        tail=merged;

        while(p1!=NULL && p2!=NULL){
            if(p1->data <= p2->data){
                tail->next=p1;
                p1=p1->next;
            }
            else{
                tail->next=p2;
                p2=p2->next;
            }
            tail=tail->next;
        }

        if(p1!=NULL)
            tail->next=p1;
        else
            tail->next=p2;
    }

    printf("Merged List: ");
    temp=merged;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}