#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    int n,i,x;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    struct Node *head=NULL,*temp=NULL,*newnode=NULL;
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("Linked List: ");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}