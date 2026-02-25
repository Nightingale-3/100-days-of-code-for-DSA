<<<<<<< HEAD
#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    int sum = 0;

    printf("Enter the elements of the matrix: ");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int limit = m < n ? m : n;

    for(int i = 0; i < limit; i++)
        sum += a[i][i];

    printf("%d", sum);
}
=======
#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    int sum = 0;

    printf("Enter the elements of the matrix: ");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int limit = m < n ? m : n;

    for(int i = 0; i < limit; i++)
        sum += a[i][i];

    printf("%d", sum);
}
>>>>>>> 81bb7fdcb2d2271c5e10b782a3ddf38974703e78
