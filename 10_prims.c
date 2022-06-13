// header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// function prototypes
int **createg(int **, int *);
void printgraph(int **, int);
void prims(int n, int **);
int minkey(int *, int *, int);

// main function
int main()
{
    int **graph;
    int num;
    graph = createg(graph, &num);
    prims(num, graph);
    return 0;
}

// create a graph
int **createg(int **graph, int *num)
{
    int cho;
    printf("\nEnter 1 to use pre defined graph\nor\nEnter any no to create your own graph:- ");
    scanf("%d", &cho);
    // predefined graph
    if (cho == 1)
    {
        int nt = 4;
        *num = nt;
        graph = (int **)malloc(sizeof(int *) * nt);
        for (int i = 0; i < nt; i++)
            graph[i] = (int *)malloc(sizeof(int) * nt);
        int a[4][4] = {
            {0, 15, 11, 0},
            {15, 0, 20, 10},
            {11, 20, 0, 22},
            {0, 10, 22, 0}};
        for (int i = 0; i < nt; i++)
        {
            for (int j = 0; j < nt; j++)
            {
                graph[i][j] = a[i][j];
            }
        }
        printgraph(graph, nt);
        return graph;
    }
    printf("Enter your total nodes of graph:- ");
    int n;
    scanf("%d", &n);
    *num = n;
    graph = (int **)malloc(sizeof(int *) * (*num));
    for (int i = 0; i < *num; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * (*num));
    }
    // create a new graph
    printf("Enter the adjacency matrix \n");
    for (int i = 0; i < *num; i++)
    {
        for (int j = 0; j < *num; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printgraph(graph, *num);
    return graph;
}

// print the graph
void printgraph(int **graph, int num)
{
    printf("\nYour Graph is:-");
    printf("\n\n\t");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%.2d ", graph[i][j]);
        }
        printf("\n\t");
    }
}

// function to find the minimum key

int minkey(int *key, int *mst, int n)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < n; i++)
    {
        if (mst[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// prims algorithm
void prims(int n, int **graph)
{
    int i, j, *mst, *key, *parent, node, min_cost = 0;

    key = (int *)malloc(sizeof(int) * n);
    mst = (int *)malloc(sizeof(int) * n);
    parent = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        node = minkey(key, mst, n);
        mst[node] = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && mst[j] == 0 && graph[node][j] < key[j])
            {
                parent[j] = node;
                key[j] = graph[node][j];
            }
        }
    }

    // print answer
    printf("\n\t\t----\t------");
    printf("\n\t\tEdge\tWeight\n\t\t");
    printf("----\t------\n\t\t");
    for (int i = 1; i < n; i++)
    {
        printf("%d-%d\t%4d\n\t\t", parent[i], i, graph[i][parent[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        min_cost += key[i];
    }

    printf("\nMinimum Cost of the spanning Tree:- %d", min_cost);
}
