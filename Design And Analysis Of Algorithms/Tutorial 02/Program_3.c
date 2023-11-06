
#include <stdio.h>
#include <stdlib.h>

int findIndex(int n, int arr[])
{
    int k = (n + n % 2) / 2;
    if (n == 1)
    {
        return k;
    }
    int *arr1 = (int *) malloc(k * sizeof(int));
    int *arr2 = (int *) malloc((n - k) * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr2[i] = arr[k + i];
    }
    if (arr[k] == 0)
    {
        if (arr[k - 1] != 0)
        {
            return k;
        } else
        {
            return (findIndex(k, arr1));
        }
    } else
    {
        return (k + findIndex(n - k, arr2));
    }
}

void main()
{
    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    printf("\nEnter the elements of the array.\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d.\n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The index of the first infinity: %d", findIndex(n, arr) + 1);
}