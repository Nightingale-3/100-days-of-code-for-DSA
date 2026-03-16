#include <stdio.h>
#include <stdlib.h>
int main(){
    int *stack,top=-1,n,i,m;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    stack=(int*)malloc(n*sizeof(int));
    printf("Enter elements to push: ");
    
    for(i=0;i<n;i++){
        scanf("%d",&stack[++top]);
    }
    printf("Enter number of pops: ");
    scanf("%d",&m);
    
    for(i=0;i<m;i++){
        if(top==-1)
            break;
        top--;
    }
    for(i=top;i>=0;i--)
        printf("%d ",stack[i]);
}