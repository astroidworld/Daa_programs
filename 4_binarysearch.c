// binary Search

// Solution

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int binarysearch(int *, int, int, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);

int main()
{
    clock_t start, end;
    double cputime;

    int *a, n, i, key;
    printf("Enter Your Array Size:- ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    printf("Enter data:- ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter The Value of the key:- ");
    scanf("%d", &key);

    merge_sort(a, 0, n - 1);
    printf("Your sorted array is:- \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    start = clock();
    int p = binarysearch(a, 0, n - 1, key);
    end = clock();

    cputime = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (p == -1)
        printf("\n\nyour number is not present.");
    else
        printf("\n\nyour number is present in %d position.", p + 1);

    printf("\n\nBinary Search EXE time = %lf", cputime);
    return 0;
}

int binarysearch(int *a, int low, int high, int key)
{
    int mid;
    if (low == high)
    {
        if (a[low] == key)
            return low;
        else
            return -1;
    }
    else
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            return mid;
        else
        {
            if (key < a[mid])
                binarysearch(a, low, mid - 1, key);
            else
                binarysearch(a, mid + 1, high, key);
        }
    }
}

// For sort the array
void merge(int *a, int lower, int mid, int upper) //
{
    int i, j, k, temp[upper];
    i = lower;
    j = mid + 1;
    k = lower;
    while (i <= mid && j <= upper)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= upper)
        temp[k++] = a[j++];
    for (i = lower; i <= upper; i++)
        a[i] = temp[i];
}

// merge sort Function
void merge_sort(int *a, int lower, int upper)
{
    int mid;
    if (lower < upper)
    {
        mid = (lower + upper) / 2;
        merge_sort(a, lower, mid);
        merge_sort(a, mid + 1, upper);
        merge(a, lower, mid, upper);
    }
}