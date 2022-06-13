// Job Sequencing problem

// demo input:- 4 a 20 4 b 10 1 c 40 1 d 30 1

#include <stdio.h>
#include <stdlib.h>

// job structure

typedef struct jobsequencing
{
    char job_id;
    int profit;
    int deadline;
} job;

// function prototype

int partition(job *, int, int);
void quickSort(job *, int, int);
void swap(job *, job *);
int jobidchecker(job *, int);
void job_sequencing(job *, int);
int min(int a, int b);

// main Function
int main()
{
    job *jobset;
    int n;
    printf("Enter the number of jobs:- ");
    scanf("%d", &n);

    jobset = (job *)malloc(sizeof(job) * n);

    for (int i = 0; i < n; i++)
    {
    here:
        printf("Enter the job id:- ");
        scanf(" %c", &jobset[i].job_id);

        // job id checker(It will not take duplicate job id)
        if (i > 0)
        {
            int check = jobidchecker(jobset, i);
            if (check == 1)
            {
                printf("\nYou can't use same job id...\nPlease enter a different job id\n\n");
                goto here;
            }
        }

        printf("Enter the profit of job %c:- ", jobset[i].job_id);
        scanf(" %d", &jobset[i].profit);
        printf("Enter the deadline of job %c:- ", jobset[i].job_id);
        scanf(" %d", &jobset[i].deadline);
    }

    printf("\n\n\t------------------------------Problem------------------------------\n\n");
    printf("\n\t\tJob id\t\tProfit\t\tDeadline\n");

    for (int i = 0; i < n; i++)
    {
        printf("\t\t%c\t\t%d\t\t%d\n", jobset[i].job_id, jobset[i].profit, jobset[i].deadline);
    }

    quickSort(jobset, 0, n - 1);

    job_sequencing(jobset, n);

    return 0;
}

// min function
int min(int a, int b)
{
    return (a > b) ? b : a;
}

void job_sequencing(job *jobset, int n)
{
    int *result;
    int *slot;
    slot = (int *)malloc(sizeof(int) * n);
    result = (int *)malloc(sizeof(int) * n);
    int totalprofit = 0;

    for (int i = 0; i < n; i++)
        slot[i] = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = min(n, jobset[i].deadline) - 1; j >= 0; j--)
        {

            if (slot[j] == 0)
            {
                result[j] = i;
                slot[j] = 1;
                totalprofit += jobset[i].profit;
                break;
            }
        }
    }

    printf("\n\t------------------------------Solution------------------------------\n\n");
    printf("\n\t\tJob id\t\tProfit\t\tDeadline\n");

    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("\t\t%c\t\t%d\t\t%d\n", jobset[result[i]].job_id, jobset[result[i]].profit, jobset[result[i]].deadline);
    printf("\n\t---------------------------------------------------------------------\n\n");
    printf("\t\tTotal Profit:- %d", totalprofit);
}

// jobidchecker function.............
int jobidchecker(job *jobset, int i)
{
    for (int j = 0; j <= i - 1; j++)
    {
        if (jobset[i].job_id == jobset[j].job_id)
            return 1;
    }
    return 0;
}

// swaping function............
void swap(job *a, job *b)
{
    job t = *a;
    *a = *b;
    *b = t;
}

// quickSort functions................
int partition(job *arr, int low, int high)
{
    float pivot = arr[high].profit;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j].profit > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(job *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
