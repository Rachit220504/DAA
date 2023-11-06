#include <bits/stdc++.h>
using namespace std;

int sum(int frequency[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += frequency[k];
    }
    return s;
}

int optimalSearchTree(int keys[], int frequency[], int n) {
    int cost[n][n];
    for (int i = 0; i < n; i++)
    {
        cost[i][i] = frequency[i];
    }
    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
            {
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(frequency, i, j);
                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n - 1];
}

int main()
{
    int a;
    int keys[a];
    cout<<"Enter the number of keys."<<endl;
    cin>>a;
    cout<<"Enter the values of the keys."<<endl;
    for(int i = 0; i < a; i++)
    {
        cin>>keys[i];
    }
    int b;
    cout<<"Enter the number of frequencies."<<endl;
    cin>>b;
    int frequency[b];
    cout<<"Enter the values of the frequencies."<<endl;
    for(int j = 0; j < b; j++)
    {
        cin>>frequency[j];
    }
    int n = sizeof(keys) / sizeof(keys[0]);
    cout<<"Cost of Optimal BST is "<<optimalSearchTree(keys, frequency, n)<<"."<<endl;
    return 0;
}