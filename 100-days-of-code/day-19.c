<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = 2147483647;
    int x = 0, y = 0;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Pair closest to zero: %d %d", x, y);
=======
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = 2147483647;
    int x = 0, y = 0;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Pair closest to zero: %d %d", x, y);
>>>>>>> 81bb7fdcb2d2271c5e10b782a3ddf38974703e78
}