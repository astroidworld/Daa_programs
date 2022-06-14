
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