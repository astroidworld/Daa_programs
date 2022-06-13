#include <stdio.h>
#include <stdlib.h>
#define max 2147483647
int matchain(int *, int);
int main()
{
    int n, *p, c;
    printf("Enter the number of matrices to be multiplied : ");
    scanf("%d", &n);
    n++;
    p = (int *)malloc(sizeof(int) * n);
    printf("Enter the dimensions : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    c = matchain(p, n);
    printf("The minimum number of matrix multiplication needed is : %d", c);
    return 0;
}

int matchain(int *p, int n)
{
    int m[n][n], s[n - 1][n - 1];
    for (int i = 0; i < n; i++)
        m[i][i] = 0;

    int j, min, q;
    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            min = max;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    printf("The position of brakets will be : ");
    for (int i = 3; i < n; i++)
    {
        printf("%d ", s[1][i]);
    }
    printf("\n");
    return m[1][n - 1];
}
