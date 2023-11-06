
#include <stdio.h>
#include <stdlib.h>

int n;

int getSize()
{
    int a = n;
    int size = a;
    while (a != 1)
    {
        a = (a + a % 2) / 2;
        size += a;
    }
    return size;
}

int findSecondMin(int size, int arr[])
{
    int k = n, l = 0, m = n;
    while (k != 1)
    {
        for (int i = 0; i < (k + k % 2) / 2; i++)
        {
            if (n % 2 != 0 && i == (n - 1) / 2)
            {
                arr[m + i] = arr[l + 2 * i];
            }
            if (arr[l + 2 * i] > arr[l + 2 * i + 1])
            {
                arr[m + i] = arr[l + 2 * i + 1];
            } else
            {
                arr[m + i] = arr[l + 2 * i];
            }
        }
        l = m;
        k = (k + k % 2) / 2;
        m += k;
    }
    int x = arr[size - 1];
    int secondMin;
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == x)
        {
            if (i % 2 == 0)
            {
                if (n & 2 != 0 && i == (n - 1) / 2)
                {
                    continue;
                }
                if (count == 0)
                {
                    secondMin = arr[i + 1];
                    count++;
                } else
                {
                    if (secondMin > arr[i + 1])
                    {
                        secondMin = arr[i + 1];
                    }
                }
            } else
            {
                if (count == 0)
                {
                    secondMin = arr[i - 1];
                    count++;
                } else
                {
                    if (secondMin > arr[i - 1])
                    {
                        secondMin = arr[i - 1];
                    }
                }
            }
        }
    }
    return secondMin;
}

void main()
{
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    int size = getSize();
    int *arr = (int *) malloc(size * sizeof(int));
    printf("\nEnter the elements of the array.\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d.\n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The second minimum element is: %d\n", findSecondMin(size, arr));
    printf("The minimum element is: %d\n", arr[size - 1]);
}