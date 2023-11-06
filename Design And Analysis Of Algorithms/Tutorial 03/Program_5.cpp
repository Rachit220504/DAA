

#include <iostream>
#define SIZE 10
using namespace std;

class stack
{
    private:
    int stack[SIZE], top = -1;
    public:
    int isEmpty()
    {
        return (top == -1);
    }
    int isFull()
    {
        return (top == SIZE - 1);
    }
    void push(int data)
    {
        if (!(isFull()))
        {
            top++;
            stack[top] = data;
        }
    }
    void pop()
    {
        if (!(isEmpty()))
        {
            top--;
        }
    }
    int peek()
    {
        if (!(isEmpty()))
        {
            return stack[top];
        } else
        {
            return -1;
        }
    }
};

int peek(stack Stack)
{
    return Stack.peek();
}

stack dequeue(stack Stack)
{
    Stack.pop();
    return Stack;
}

stack enqueue(int data, stack Stack)
{
    stack Stack2;
    while (!(Stack.isEmpty()))
    {
        Stack2.push(Stack.peek());
        Stack.pop();
    }
    Stack.push(data);
    while (!(Stack2.isEmpty()))
    {
        Stack.push(Stack2.peek());
        Stack2.pop();
    }
    return Stack;
}

int main()
{
    int option;
    stack Stack;
    while (1)
    {
        cout<<"\nQUEUE IMPLEMENTATION USING STACK\n";
        cout<<"Press '1' to peek at the front element.\n";
        cout<<"Press '2' to dequeue an element.\n";
        cout<<"Press '3' to enqueue an element.\n";
        cout<<"Press '0' to exit the program.\n";
        cin>>option;
        cout<<"\n";
        if (option == 1)
        {
            int x = peek(Stack);
            if (x == -1)
            {
                cout<<"The queue is empty.\n";
            } else
            {
                cout<<"The front element is "<<x<<".\n";
            }
        } else if (option == 2)
        {
            int x = peek(Stack);
            if (x == -1)
            {
                cout<<"The queue is empty.\n";
            } else
            {
                Stack = dequeue(Stack);
                cout<<"The front element has been removed.\n";
            }
        } else if (option == 3)
        {
            int x;
            cout<<"Enter the element.\n";
            cin>>x;
            Stack = enqueue(x, Stack);
            cout<<"The element has been inserted.\n";
        } else if (option == 0)
        {
            break;
        } else
        {
            cout<<"Please enter one of the above mentioned choices only.\n";
        }
    }
    return 0;
}