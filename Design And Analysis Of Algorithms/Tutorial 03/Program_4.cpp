

#include <iostream>
#define SIZE 10
using namespace std;

class queue
{
    private:
    int queue[SIZE], front = -1, rear = -1;
    public:
    int isEmpty()
    {
        return (front == -1);
    }
    int isFull()
    {
        return (rear == SIZE - 1);
    }
    void enqueue(int data)
    {
        if (!(isFull()))
        {
            if (front == -1)
            {
                front++;
            }
            rear++;
            queue[rear] = data;
        }
    }
    void dequeue()
    {
        if (!(isEmpty()))
        {
            for (int i = front; i < rear; i++)
            {
                queue[i] = queue[i + 1];
            }
            if (rear == 0)
            {
                front--;
            }
            rear--;
        }
    }
    int peek()
    {
        if (!(isEmpty()))
        {
            return queue[front];
        } else
        {
            return -1;
        }
    }
};

int peek(queue Queue)
{
    return Queue.peek();
}

queue pop(queue Queue)
{
    Queue.dequeue();
    return Queue;
}

queue push(int data, queue Queue)
{
    queue Queue2;
    while (!(Queue.isEmpty()))
    {
        Queue2.enqueue(Queue.peek());
        Queue.dequeue();
    }
    Queue.enqueue(data);
    while (!(Queue2.isEmpty()))
    {
        Queue.enqueue(Queue2.peek());
        Queue2.dequeue();
    }
    return Queue;
}

int main()
{
    int option;
    queue Queue;
    while (1)
    {
        cout<<"\nSTACK IMPLEMENTATION USING QUEUE\n";
        cout<<"Press '1' to peek at the top element.\n";
        cout<<"Press '2' to pop an element.\n";
        cout<<"Press '3' to push an element.\n";
        cout<<"Press '0' to exit the program.\n";
        cin>>option;
        cout<<"\n";
        if (option == 1)
        {
            int x = peek(Queue);
            if (x == -1)
            {
                cout<<"The stack is empty.\n";
            } else
            {
                cout<<"The top element is "<<x<<".\n";
            }
        } else if (option == 2)
        {
            int x = peek(Queue);
            if (x == -1)
            {
                cout<<"The stack is empty.\n";
            } else
            {
                Queue = pop(Queue);
                cout<<"The top element has been removed.\n";
            }
        } else if (option == 3)
        {
            int x;
            cout<<"Enter the element.\n";
            cin>>x;
            Queue = push(x, Queue);
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