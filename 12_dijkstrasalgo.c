// dijkstra's algorithm

// solution by ~Akash

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// function prototype
int **createg(int **, int *);
void dijkstra(int n, int **);
int minkey(int *, int *, int);
void printgraph(int **, int);

// main function
int main()
{

    int **graph;
    int num;
    graph = createg(graph, &num);
    dijkstra(num, graph);
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

// dijkstra algorithm
void dijkstra(int n, int **graph)
{
    int i, j, mincost = 0, *mst, *key, *parent, node = 0, min = INT_MAX, p, u, start;

    printf("\nEnter the strat node:- ");
    scanf("%d", &start);

    key = (int *)malloc(sizeof(int) * n);
    mst = (int *)malloc(sizeof(int) * n);
    parent = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[start] = 0;
    parent[start] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        u = minkey(key, mst, n);

        mst[u] = 1;

        for (int j = 0; j < n; j++)
        {
            if (graph[u][j] && mst[j] == 0 && (graph[u][j] + key[u]) < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j] + key[u];
            }
        }
    }

    printf("\t\t----\t------");
    printf("\n\t\tEdge\tWeight\n\t\t");
    printf("----\t------\n\t\t");
    for (int i = 1; i < n; i++)
    {
        if (parent[i] == -1)
        {
            printf("%d-%d\t%4d\n\t\t", start, i, graph[i][parent[i]]);
            continue;
        }
        printf("%d-%d\t%4d\n\t\t", parent[i], i, graph[i][parent[i]]);
    }

    printf("\nPATH (distance from source):- \n");
    printf("\n\t\tEdge\tWeight\n\t\t");
    printf("----\t------\n\t\t");
    for (int i = 1; i < n; i++)
    {
        printf("%d-%d\t%4d\n\t\t", start, i, key[i]);
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
