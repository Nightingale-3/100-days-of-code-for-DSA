#include <stdio.h>
int main()
{
    int n, k, i, index = -1, comparisons = 0;
    scanf("%d", &n);

    int arr[1000];

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == k)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);
}
