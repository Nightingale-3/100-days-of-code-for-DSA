#include <stdio.h>
int main()
{
    int p, q, i, j, k = 0;
    scanf("%d", &p);

    int a[1000], b[1000], c[2000];

    for (i = 0; i < p; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);

    for (i = 0; i < q; i++)
        scanf("%d", &b[i]);

    i = 0;
    j = 0;

    while (i < p && j < q)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < p)
        c[k++] = a[i++];

    while (j < q)
        c[k++] = b[j++];

    for (i = 0; i < k; i++)
        printf("%d ", c[i]);
}
