
#include <stdio.h>
#include <stdlib.h>

int GCD1(int a, int b)
{
    if (a == 0 && b != 0)
    {
        return b;
    } else if (a != 0 && b == 0)
    {
        return a;
    } else if (a == 0 && b == 0)
    {
        printf("Two of the numbers are zero.\n");
        exit(1);
    } else
    {
        int q, r;
        if (a > b)
        {
            q = (a - a % b) / b;
            int r = a - b * q;
            if (r == 0)
            {
                return b;
            } else
            {
                return GCD1(b, r);
            }
        } else
        {
            q = b / a;
            int r = b - a * q;
            if (r == 0)
            {
                return a;
            } else
            {
                return GCD1(a, r);
            }
        }
    }
}

int GCD2(int a, int b)
{
    if (a == 0 && b != 0)
    {
        return b;
    } else if (a != 0 && b == 0)
    {
        return a;
    } else if (a == 0 && b == 0)
    {
        printf("Two of the numbers are zero.\n");
        exit(1);
    } else
    {
        int n;
        if (a < b)
        {
            for (int i = 1; i <= a; i++)
            {
                if (a % i == 0 && b % i == 0)
                {
                    n = i;
                }
            }
        } else
        {
            for (int i = 1; i <= b; i++)
            {
                if (a % i == 0 && b % i == 0)
                {
                    n = i;
                }
            }
        }
        return n;
    }
}

int GCD3(int a, int b)
{
    if (a == 0 && b != 0)
    {
        return b;
    } else if (a != 0 && b == 0)
    {
        return a;
    } else if (a == 0 && b == 0)
    {
        printf("Two of the numbers are zero.\n");
        exit(1);
    } else
    {
        int x;
        if (a < b)
        {
            for (int i = 1; i <= a; i++)
            {
                if (b * i % a == 0)
                {
                    x = b * i;
                    break;
                }
            }
        } else
        {
            for (int i = 1; i <= b; i++)
            {
                if (a * i % b == 0)
                {
                    x = a * i;
                    break;
                }
            }
        }
        int n = a * b / x;
        return n;
    }
}

int GCDn1(int n, int arr[])
{
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        x = GCD1(x, arr[i]);
    }
    return x;
}

int GCDn2(int n, int arr[])
{
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        x = GCD2(x, arr[i]);
    }
    return x;
}

int GCDn3(int n, int arr[])
{
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        x = GCD3(x, arr[i]);
    }
    return x;
}

void main()
{
    int n;
    printf("Enter the number of integers for which you want to find the GCD.\n");
    scanf("%d", &n);
    int * arr = (int *) malloc(n * sizeof(int));
    printf("\nEnter the integers.\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter integer %d.\n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe GCD of the integers through method 1 = %d\n", GCDn1(n, arr));
    printf("\nThe GCD of the integers through method 2 = %d\n", GCDn2(n, arr));
    printf("\nThe GCD of the integers through method 3 = %d\n", GCDn3(n, arr));
}