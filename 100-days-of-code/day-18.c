#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the elements of the array: ");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int k;
    printf("Enter the number of positions to rotate the array: ");
    scanf("%d",&k);

    k = k % n;

    for(int i=n-k;i<n;i++)
        printf("%d ",a[i]);
    for(int i=0;i<n-k;i++)
        printf("%d ",a[i]);
}
