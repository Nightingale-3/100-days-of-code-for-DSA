#include <stdio.h>

#define MAX 100

int pq[MAX];
int n = 0;

void insert(int x)
{
    int i = n - 1;

    while(i >= 0 && pq[i] > x)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    n++;
}

int delete()
{
    if(n == 0)
        return -1;

    int x = pq[0];

    for(int i = 1; i < n; i++)
        pq[i - 1] = pq[i];

    n--;

    return x;
}

int peek()
{
    if(n == 0)
        return -1;

    return pq[0];
}

int main()
{
    int N,i,x;
    char op[10];

    printf("Enter number of operations: ");
    scanf("%d",&N);

    for(i=0;i<N;i++)
    {
        printf("Enter operation: ");
        scanf("%s",op);

        if(op[0]=='i')
        {
            printf("Enter value: ");
            scanf("%d",&x);
            insert(x);
        }
        else if(op[0]=='d')
        {
            printf("%d\n",delete());
        }
        else if(op[0]=='p')
        {
            printf("%d\n",peek());
        }
    }
}