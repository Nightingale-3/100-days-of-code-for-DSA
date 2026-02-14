#include <stdio.h>
int main()
{
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    if(m != n)
    {
        printf("Not a Symmetric Matrix");
    }

    else
    {

    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);

        int symmetric = 1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j] != a[j][i])
                {
                    symmetric = 0;
                    break;
                }
            }
            if(symmetric == 0)
                break;
        }

        if(symmetric == 1)
            printf("The given matrix is a Symmetric Matrix");
        else
            printf("The given matrix is not a Symmetric Matrix");
    }
}
