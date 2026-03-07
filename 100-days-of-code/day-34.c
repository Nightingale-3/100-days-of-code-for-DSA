#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push(int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop(){
    int x=top->data;
    struct node* temp=top;
    top=top->next;
    free(temp);
    return x;
}

int main(){
    char exp[100];
    int i=0;

    printf("Enter postfix expression: ");
    gets(exp);

    while(exp[i]!='\0'){
        if(exp[i]>='0' && exp[i]<='9')
            push(exp[i]-'0');

        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int b=pop();
            int a=pop();

            if(exp[i]=='+') push(a+b);
            if(exp[i]=='-') push(a-b);
            if(exp[i]=='*') push(a*b);
            if(exp[i]=='/') push(a/b);
        }

        i++;
    }

    printf("%d",pop());
}