#include <stdio.h>
int main()
{
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);

    int identity = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j)
            {
                if(a[i][j] != 1)
                {
                    identity = 0;
                    break;
                }
            }
            else
            {
                if(a[i][j] != 0)
                {
                    identity = 0;
                    break;
                }
            }
        }
        if(identity == 0)
            break;
    }

    if(identity == 1)
        printf("The given matrix is an Identity Matrix");
    else
        printf("The given matrix is not an Identity Matrix");
}
