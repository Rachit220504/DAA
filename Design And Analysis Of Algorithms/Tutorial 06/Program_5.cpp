#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A;
    vector<int> B;
    long long sumA = 0;
    long long sumB = 0;
    int m, n;
    cout<<"Enter the number of elements in A.\n";
    cin>>n;
    cout<<"Enter the number of elements in B.\n";
    cin>>m;
    if (n <= 0 || m <= 0)
    {
        cout<<"Invalid input. Array sizes should be greater than 0.\n";
    }
    cout<<"Enter the elements of A.\n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
        sumA += a;
    }
    cout<<"Enter the elements of B.\n";
    for (int i = 0; i < m; i++)
    {
        int a;
        cin>>a;
        B.push_back(a);
        sumB += a;
    }
    long long diff = abs(sumA - sumB) / 2;
    unordered_map<int, int> elements;
    for (int i = 0; i < n; i++)
    {
        elements[A[i]] = i;
    }
    if (sumA < sumB)
    {
        for (int i = 0; i < m; i++)
        {
            int target = B[i] - diff;
            if (elements.find(target) != elements.end())
            {
                cout<<"Two possible indices are as follows: ";
                int index1 = elements[target];
                int index2 = i;
                cout<<index1<< ", "<<index2<<"\n";
                break;
            }
        }
    } else if (sumA > sumB)
    {
        for (int i = 0; i < n; i++) {
            int target = A[i] - diff;
            if (elements.find(target) != elements.end()) {
                cout<<"Two possible indices are as follows: ";
                int index1 = i;
                int index2 = elements[target];
                cout<<index1<<", "<<index2<<"\n";
                break;
            }
        }
    } else
    {
        cout<<"Sum of the two arrays is already equal.\n";
        return 0;
    }
    cout<<"No such indices exist.\n";
    return 0;
}