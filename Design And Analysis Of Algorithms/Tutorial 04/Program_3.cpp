
#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacciSequence(int n)
{
    vector<int> fibonacci;
    int a = 0, b = 1, i = 0;
    while (i < n)
    {
        fibonacci.push_back(a);
        i++;
        if (i == n)
        {
            break;
        }
        fibonacci.push_back(b);
        i++;
        a += b;
        b += a;
    }
    return fibonacci;
}

int fibonacciSequenceRecursive(int n, int a, int b)
{
    static int i = 0;
    cout<<a<<" ";
    i++;
    if (i >= n)
    {
        return a;
    }
    a += b;
    cout<<b<<" ";
    i++;
    if (i >= n)
    {
        return b;
    }
    b += a;
    return fibonacciSequenceRecursive(n, a , b);
}

int main()
{
    int n;
    cout<<"FIBONACCI SEQUENCER\n";
    cout<<"Enter the number of the term you want to print.\n";
    cin>>n;
    if (n > 0)
    {
        int x;
        cout<<"Enter '1' to print the fibonacci sequence through iteration\n";
        cout<<"Enter '2' to print the fibonacci sequeunce through recursion.\n";
        cin>>x;
        if (x == 1)
        {
            vector<int> fibonacci = fibonacciSequence(n);
            cout<<"\nThe Fibonacci Sequence is as follows:\n";
            for (int i = 0; i < fibonacci.size(); i++)
            {
                cout<<fibonacci[i]<<" ";
            }
            cout<<"\n";
            cout<<"\nTerm number "<<n<<" of the Fibonacci Sequence is "<<fibonacci[n - 1]<<".\n";
        } else if (x == 2)
        {
            cout<<"\nThe Fibonacci Sequence is as follows:\n";
            int num = fibonacciSequenceRecursive(n, 0, 1);
            cout<<"\n";
            cout<<"\nTerm number "<<n<<" of the Fibonacci Sequence is "<<num<<".\n";
        } else
        {
            cout<<"Please enter one of the above mentioned choices only.\n";
        }
    } else
    {
        cout<<"Please enter a number greater than 0 only.\n";
    }
    return 0;
}