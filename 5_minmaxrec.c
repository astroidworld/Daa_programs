// Solution

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int maxmin(int *, int, int, int *, int *);

int main()
{
    clock_t start, end;
    double cputime;

    int *a, n, i, min, max;
    printf("Enter Your Array Size:- ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    printf("Enter data:- ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    start = clock();
    maxmin(a, 0, n - 1, &max, &min);
    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nMax= %d & Min = %d", max, min);

    printf("\n\nMAX-MIN EXE time = %lf", cputime);
    return 0;
}

int maxmin(int *a, int i, int j, int *max, int *min)
{
    int min1, max1, mid;
    if (i == j)
    {
        *max = a[i];
        *min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            *max = a[i];
            *min = a[j];
        }
        else
        {
            *max = a[j];
            *min = a[i];
        }
    }
    else
    {
        mid = (i + j) / 2;
        maxmin(a, i, mid, max, min);
        maxmin(a, mid + 1, j, &max1, &min1);
        if (max1 > *max)
            *max = max1;
        if (min1 < *min)
            *min = min1;
    }
}
