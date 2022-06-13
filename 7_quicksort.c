// Solution

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int partition(int *, int, int);
void quickSort(int *, int, int);
void swap(int *, int *);

int main()
{
    clock_t start, end;
    double cputime;

    int *a, n, i, cho;
    printf("Enter Your Array Size:- ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    printf("Enter 1 to give your own data\n or, \nEnter 2 to test the program with random:- ");
    scanf("%d", &cho);

    if (cho == 1)
    {
        printf("Enter data:- ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            // a[i] = rand() % 10000;
        }
    }

    else

    {
        for (i = 0; i < n; i++)
        {
            a[i] = rand() % 10000;
        }
    }

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (cho == 1)
    {
        printf("\n\nYour array after Sorting is:- ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }

    printf("\nEXE time for (%d) inputs= %lf", n, cputime);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
