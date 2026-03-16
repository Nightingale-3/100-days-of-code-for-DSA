#include <stdio.h>

int heap[1000];
int size=0;

void insert(int x)
{
    heap[size]=x;
    int i=size;
    size++;

    while(i>0 && heap[(i-1)/2] > heap[i])
    {
        int t=heap[i];
        heap[i]=heap[(i-1)/2];
        heap[(i-1)/2]=t;
        i=(i-1)/2;
    }
}

void heapify(int i)
{
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<size && heap[l]<heap[smallest])
        smallest=l;

    if(r<size && heap[r]<heap[smallest])
        smallest=r;

    if(smallest!=i)
    {
        int t=heap[i];
        heap[i]=heap[smallest];
        heap[smallest]=t;
        heapify(smallest);
    }
}

int extractMin()
{
    if(size==0)
        return -1;

    int min=heap[0];
    heap[0]=heap[size-1];
    size--;

    heapify(0);

    return min;
}

int peek()
{
    if(size==0)
        return -1;
    return heap[0];
}

int main()
{
    int n;
    char op[20];
    int x;

    printf("Enter number of operations: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter operation: ");
        scanf("%s",op);

        if(op[0]=='i')
        {
            printf("Enter value: ");
            scanf("%d",&x);
            insert(x);
        }
        else if(op[0]=='p')
        {
            printf("%d\n",peek());
        }
        else
        {
            printf("%d\n",extractMin());
        }
    }
}