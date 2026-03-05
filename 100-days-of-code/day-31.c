#include <stdio.h>
#define MAX 100
int main(){
    int stack[MAX],top=-1,n,i,op,val;
    printf("Enter number of operations: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter operation: ");
        scanf("%d",&op);
    
        if(op==1){
            printf("Enter value: ");
            scanf("%d",&val);
    
            if(top==MAX-1)
                printf("Stack Overflow\n");
            else{
                top++;
                stack[top]=val;
            }
        }
    
        else if(op==2){
            if(top==-1)
                printf("Stack Underflow\n");
            else{
                printf("%d\n",stack[top]);
                top--;
            }
        }
    
        else if(op==3){
            if(top==-1)
                printf("Stack Underflow\n");
            else{
                int j;
                for(j=top;j>=0;j--)
                    printf("%d ",stack[j]);
                printf("\n");
            }
        }
    }
}