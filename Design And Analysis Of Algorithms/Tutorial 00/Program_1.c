

#include <stdio.h>
#include <stdlib.h>

int findNeitherMinNorMax(int n, int arr[])
{
    int a = arr[0];
    int b = -1, c = -1;
    for (int i = 1; i < n; i++)
    {
        if (b == -1)
        {
            if (arr[i] != a)
            {
                b = arr[i];
            }
        } else
        {
            if (arr[i] != a && arr[i] != b)
            {
                c = arr[i];
                break;
            }
        }
    }
    if (c == -1)
    {
        return -1;
    }
    if (a > b)
    {
        if (b > c)
        {
            return b;
        } else
        {
            if (a > c)
            {
                return c;
            } else
            {
                return a;
            }
        }
    } else
    {
        if (a > c)
        {
            return a;
        } else
        {
            if (b > c)
            {
                return c;
            } else
            {
                return b;
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    int * arr = (int *) malloc(n * sizeof(int));
    printf("\nEnter the array elements.\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d.\n", i + 1);
        scanf("%d", &arr[i]);
    }
    int x = findNeitherMinNorMax(n, arr);
    if (x == -1)
    {
        printf("There is no number that is neither the minimum nor the maximum.\n");
    } else
    {
        printf("The number that is neither the minimum nor the maximum is: %d\n", x);
    }
}