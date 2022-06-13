#include <stdio.h>
#include <stdlib.h>

int partition(float *, int, int, int *, int *, int *);
void quickSort(float *, int, int, int *, int *, int *);
void swap(int *, int *);
void swapfloat(float *, float *);

int main()
{
    int n, total, *p, *w, *used, *item;
    float *rate, *x, *y;
    printf("Enter the number of total elements:- ");
    scanf("%d", &n);
    printf("Enter the total Weight capacity of knapsack:- ");
    scanf("%d", &total);

    p = (int *)malloc(sizeof(int) * n);
    w = (int *)malloc(sizeof(int) * n);
    rate = (float *)malloc(sizeof(float) * n);
    x = (float *)malloc(sizeof(float) * n);
    y = (float *)malloc(sizeof(float) * n);
    used = (int *)malloc(sizeof(int) * n);
    item = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Weight of the %d element:- ", i + 1);
        scanf("%d", &w[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Price of the %d element:- ", i + 1);
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++)
    {
        float pri = p[i];
        float wei = w[i];
        rate[i] = pri / wei;
        // for calculating the item number
        item[i] = i;
    }

    printf("\n\n\t--------------------------:Problem:--------------------------\n\n\tItem no\t\tWeight\t\tPrice\t\tPrice/weight\n");

    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%f\n", item[i] + 1, w[i], p[i], rate[i]);
    }

    // knapsack Logic

    quickSort(rate, 0, n - 1, p, w, item);

    int wt = 0, i = 0;
    float finalprice = 0;

    while ((i <= n) && (wt <= total))
    {
        if (wt + w[i] <= total)
        {
            x[i] = 1;
            used[i] = w[i];
            y[i] = p[i];
            wt = wt + w[i];
            finalprice += p[i];
            i++;
        }
        else
        {
            float tempwt = w[i];
            x[i] = ((float)total - wt) / w[i];
            used[i] = total - wt;
            wt = wt + x[i] * w[i];
            y[i] = x[i] * p[i];
            finalprice = finalprice + x[i] * p[i];
            i++;
        }
    }

    // Output

    printf("\n\n\t--------------------------:Solution:--------------------------");

    printf("\n\n\tItem no\t\tWeight\t\tPrice\t\tUsed\n");

    for (int j = 0; j < n; j++)
    {
        printf("\t%d\t\t%.3f\t\t%.3f\t\t%d/%d\n", item[j] + 1, x[j], y[j], used[j], w[j]);
    }
    printf("\t--------------------------------------------------------------");
    printf("\n\n\t\t\t  Total Price:- %.3f\tweight:- %d\n", finalprice, wt);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swapfloat(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

int partition(float *arr, int low, int high, int *p, int *w, int *item)
{
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] > pivot)
        {
            i++;
            swapfloat(&arr[i], &arr[j]);
            swap(&p[i], &p[j]);
            swap(&w[i], &w[j]);
            swap(&item[i], &item[j]);
        }
    }
    swapfloat(&arr[i + 1], &arr[high]);
    swap(&p[i + 1], &p[high]);
    swap(&w[i + 1], &w[high]);
    swap(&item[i + 1], &item[high]);
    return (i + 1);
}

void quickSort(float *arr, int low, int high, int *p, int *w, int *item)
{
    if (low < high)
    {

        int pi = partition(arr, low, high, p, w, item);

        quickSort(arr, low, pi - 1, p, w, item);
        quickSort(arr, pi + 1, high, p, w, item);
    }
}
