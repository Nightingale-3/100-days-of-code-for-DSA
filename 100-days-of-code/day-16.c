#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
    {
        int count = 1;

        if(a[i] == -999999)
            continue;

        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                count++;
                a[j] = -999999;
            }
        }

        printf("%d:%d ", a[i], count);
    }
}
