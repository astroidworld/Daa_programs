// Solution

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int mergesort(int *, int, int, int);
int merge(int *a, int lb, int mid, int ub, int n);

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
    mergesort(a, 0, n - 1, n);
    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nYour array after Sorting is:- ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nMerge Sort EXE time = %lf", cputime);
    return 0;
}

int mergesort(int *a, int lb, int ub, int n)
{
    int mid;
    if (lb < ub)
    {
        mid = (ub + lb) / 2;
        mergesort(a, lb, mid, n);
        mergesort(a, mid + 1, ub, n);
        merge(a, lb, mid, ub, n);
    }
}

int merge(int *a, int lb, int mid, int ub, int n)
{
    int *temp;
    temp = (int *)malloc(n * sizeof(int));
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])

            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= ub)
    {
        temp[k++] = a[j++];
    }
    for (i = lb; i <= ub; i++)
        a[i] = temp[i];
}
