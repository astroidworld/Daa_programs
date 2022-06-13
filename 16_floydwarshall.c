#include <stdio.h>

void FW(int adj[][10], int);

int main()
{
    int i, j, adj[10][10], n;
    printf("Enter the size of graph\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("\n");
    FW(adj, n);

    return 0;
}

void FW(int adj[][10], int n)
{

    int a[n][n], i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = adj[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((a[i][k] + a[k][j]) < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
