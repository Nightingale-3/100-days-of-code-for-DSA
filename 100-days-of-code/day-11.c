#include <stdio.h>
int main()
{
    int rows, column;
    scanf("%d %d", &rows, &column);

    int a[rows][column], b[rows][column], sum[rows][column];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < column; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < column; j++)
            scanf("%d", &b[i][j]);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < column; j++)
            sum[i][j] = a[i][j] + b[i][j];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < column; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}
