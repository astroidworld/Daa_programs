// header files
#include <stdio.h>

// function prototypes
int arraysum(int[], int);

// main function
int main()
{
    int arr[10], n, i, total;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    total = arraysum(arr, n - 1);
    printf("\nThe sum is %d", total);
}

// Arraysum Function
int arraysum(int arr[], int n)
{
    if (n == 0)
    {
        return arr[0];
    }
    else
    {
        return (arraysum(arr, n - 1) + arr[n]);
    }
}