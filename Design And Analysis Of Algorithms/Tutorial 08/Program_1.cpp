#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &s)
{
    if (i == j) {
        cout<<s++;
        return;
    }
    cout<<"(";
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, s);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, s);
    cout<<")";
}

void matrixChainOrder(int arr[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char s = 'A';
    cout<<"Optimal Parenthesization: ";
    printParenthesis(1, n - 1, n, (int *) bracket, s);
    cout<<endl;
    cout<<"Minimum number of multiplications: "<<m[1][n - 1]<<endl;
}

int main()
{
    int size;
    cout<<"Enter the size of the array."<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array."<<endl;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    matrixChainOrder(arr, size);
    return 0;
}