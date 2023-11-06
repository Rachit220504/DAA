
#include <stdio.h>

int a, b, top = -1, stack[2];

void swap1()
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2()
{
    a = a + b;
    b = a - b;
    a = a - b;
}

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

void swap3()
{
    push(a);
    push(b);
    a = pop();
    b = pop();
}

void main()
{
    int choice;
    printf("Enter number 1.\n");
    scanf("%d", &a);
    printf("Enter number 2.\n");
    scanf("%d", &b);
    while (1)
    {
        printf("Choose the method of swapping. [1, 2 or 3]\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            swap1();
            break;
        } else if (choice == 2)
        {
            swap2();
            break;
        } else if (choice == 3)
        {
            swap3();
            break;
        } else
        {
            printf("Please enter one of the above mentioned choices only.\n");
        }
    }
    printf("\nNew value of a = %d\n", a);
    printf("New value of b = %d\n", b);
}