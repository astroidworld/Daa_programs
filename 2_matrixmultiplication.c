// Header File
#include <stdio.h>

// Main Function
int main()
{
    int a[50][50], b[50][50], c[50][50];
    int i, j, k, m, n, p, q;
    printf("Enter the order of matrix a: ");
    scanf("%d%d", &m, &n);
    printf("Enter the order of matrix b: ");
    scanf("%d%d", &p, &q);
    if (n != p)
    {
        printf("Matrix multiplication is not possible");
    }
    else
    {
        printf("\nEnter the elements of a :\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        }
        printf("\nEnter the elements of b :\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
                scanf("%d", &b[i][j]);
        }
        printf("Elements of matrix a:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                printf("%d\t", a[i][j]);
            printf("\n");
        }
        printf("Elements of matrix b:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
                printf("%d\t", b[i][j]);
            printf("\n");
        }
        printf("Elements of resultant matrix c:\n");

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < p; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
                printf("%d\t", c[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
