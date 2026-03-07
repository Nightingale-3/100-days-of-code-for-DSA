#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    struct node{
        int data;
        struct node *next;
    };
    
    struct node *top=NULL,*temp;
    char exp[100];
    int i,a,b,res;
    
    printf("Enter postfix expression: ");
    fgets(exp,sizeof(exp),stdin);
    
    for(i=0;i<strlen(exp);i++)
    {
        if(isdigit(exp[i]))
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=exp[i]-'0';
            temp->next=top;
            top=temp;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            a=top->data;
            top=top->next;
            
            b=top->data;
            top=top->next;
            
            if(exp[i]=='+') res=b+a;
            else if(exp[i]=='-') res=b-a;
            else if(exp[i]=='*') res=b*a;
            else if(exp[i]=='/') res=b/a;
            
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=res;
            temp->next=top;
            top=temp;
        }
    }
    
    printf("%d",top->data);
}