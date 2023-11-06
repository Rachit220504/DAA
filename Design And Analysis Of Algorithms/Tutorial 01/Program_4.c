
#include <stdio.h>

int top = -1;
int stack[100];

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int x = stack[top];
    top--;
    return x;
}

void getDigits(int n)
{
    int digits = 0;
    for (int i = 0; n != 0; i++)
    {
        int x = n % 10;
        push(x);
        n = (n - x) / 10;
        digits++;
    }
    if (digits % 2 == 1)
    {
        push(0);
    }
}

double squareRoot(int n)
{
    getDigits(n);
    int k = 0;
    double ans = 0;
    while (top != -1)
    {
        k = 100 * k + 10 * pop() + pop();
        for (int i = 0; i <= 9; i++)
        {
            int d1 = (ans * 20 + i) * i;
            int d2 = (ans * 20 + (i + 1)) * (i + 1);
            if (d1 <= k && d2 > k)
            {
                k = k - d1;
                ans = ans * 10 + i;
                break;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        k = k * 100;
        for (int i = 0; i <= 9; i++)
        {
            int d1 = (ans * 20 + i) * i;
            int d2 = (ans * 20 + (i + 1)) * (i + 1);
            if (d1 <= k && d2 > k)
            {
                k = k - d1;
                ans = ans * 10 + i;
                break;
            }
        }
    }
    return ans / 100000;
}

void main()
{
    int n;
    printf("\nEnter the number.\n");
    scanf("%d", &n);
    printf("\nThe square root of the number is: %f\n\n", squareRoot(n));
}