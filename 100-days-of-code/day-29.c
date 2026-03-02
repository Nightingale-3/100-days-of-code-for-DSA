#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    int n,i,k;
    struct Node *head=NULL,*temp=NULL,*newNode=NULL,*tail=NULL;

    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    if(n<=0) 
    return 0;
    
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    
    printf("Enter value of k: ");
    scanf("%d",&k);
    k=k%n;
    if(k==0){
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return 0;
    }
    
    tail=head;
    while(tail->next!=NULL)
        tail=tail->next;
    tail->next=head;
    temp=head;
    
    for(i=1;i<n-k;i++)
        temp=temp->next;
    head=temp->next;
    temp->next=NULL;
    temp=head;
    
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}