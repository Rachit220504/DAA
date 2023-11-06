
#include <stdio.h>

void getFactors(int n, int arr[])
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[count] = i;
            count++;
        }
    }
    if (count % 2 == 0)
    {
        for (int i = 0; i < count; i++)
        {
            arr[count + i] = n / arr[count - i - 1];
        }
        arr[2 * count] = -1;
    } else
    {
        for (int i = 0; i < count; i++)
        {
            arr[count + i - 1] = n / arr[count - i - 1];
        }
        arr[2 * count - 1] = -1;
    }
}

int getSumOfFactors(int n)
{
    int sum = 0;
    int arr[100];
    getFactors(n, arr);
    for (int i = 0; arr[i] != -1; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void getPrimeFactors(int n, int arr[])
{
    int k = 0, count = 0;
    int arr2[100];
    getFactors(n, arr2);
    for (int i = 1; arr2[i] != -1; i++)
    {
        for (int j = 2; j <= arr2[i]; j++)
        {
            if (j == arr2[i])
            {
                count++;
            }
            if (arr2[i] % j == 0)
            {
                break;
            }
        }
        if (count > 0)
        {
            arr[k] = arr2[i];
            k++;
        }
        count = 0;
    }
    arr[k] = -1;
}

void getPrimeFactorization(int n, int arr[])
{
    int arr2[100], count = 0;
    getPrimeFactors(n, arr2);
    for (int i = 0; arr2[i] != -1; i++)
    {
        int c = 0;
        while (n % arr2[i] == 0)
        {
            c++;
            n = n / arr2[i];
        }
        arr[2 * i] = arr2[i];
        arr[2 * i + 1] = c;
        c = 0;
        if (arr2[i + 1] == -1)
        {
            arr[2 * i + 2] = -1;
        }
    }
}

void printFactors(int arr[])
{
    for (int i = 0; arr[i] != -1; i++)
    {
        printf ("%d ", arr[i]);
    }
    printf("\n");
}

void printFactorization(int arr[])
{
    printf ("%d ^ %d", arr[0] , arr[1]);
    for (int i = 1; arr[2 * i] != -1; i++)
    {
        printf (" x %d ^ %d", arr[2 * i], arr[2 * i + 1]);
    }
    printf("\n");
}

void main()
{
    int number = -1, choice;
    while (1)
    {
        printf("\nPress \'1\' to enter a new number.\n");
        printf("Press \'2\' to get its factors.\n");
        printf("Press \'3\' to get the sum of its factors.\n");
        printf("Press \'4\' to get its prime factors.\n");
        printf("Press \'5\' to get its prime factorization.\n");
        printf("Press \'0\' to exit the program.\n");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 1)
        {
            printf("Enter the number.\n");
            scanf("%d", &number);
            printf("The number has been successfully entered.\n");
        } else if (choice == 2)
        {
            if (number == -1)
            {
                printf("Enter a number first.\n");
            } else
            {
                int arr[100];
                getFactors(number, arr);
                printf("The factors of the number are as follows:\n");
                printFactors(arr);
            }
        } else if (choice == 3)
        {
            if (number == -1)
            {
                printf("Enter a number first.\n");
            } else
            {
                int sum = getSumOfFactors(number);
                printf("The sum of the factors of the number is as follows:\n");
                printf("%d\n", sum);
            }
        } else if (choice == 4)
        {
            if (number == -1)
            {
                printf("Enter a number first.\n");
            } else
            {
                int arr[100];
                getPrimeFactors(number, arr);
                printf("The prime factors of the number are as follows:\n");
                printFactors(arr);
            }
        } else if (choice == 5)
        {
            if (number == -1)
            {
                printf("Enter a number first.\n");
            } else
            {
                int arr[100];
                getPrimeFactorization(number, arr);
                printf("The prime factorization of the number is as follows:\n");
                printFactorization(arr);
            }
        } else if (choice == 0)
        {
            break;
        }
    }
}