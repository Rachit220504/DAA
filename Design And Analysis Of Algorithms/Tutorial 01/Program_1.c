
#include <stdio.h>

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int x = n % 10;
    int y = (n - x) / 10;
    int sum = x + sumOfDigits(y);
    return sum;
}

int sumOfDistinctDigits(int n)
{
    int arr[10] = {0, 0 ,0 ,0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; n != 0; i++)
    {
        int x = n % 10;
        arr[x]++;
        n = (n - x) / 10;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > 0)
        {
            sum += i;
        }
    }
    return sum;
}

void main()
{
    int n;
    printf("Enter the number.\n");
    scanf("%d", &n);
    printf("\nThe sum of digits of the number = %d\n", sumOfDigits(n));
    printf("\nThe sum of distinct digits of the number = %d\n", sumOfDistinctDigits(n));
}