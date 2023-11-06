#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int weights[], int values[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            } else if (weights[i - 1] <= w)
            {
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            } else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

int main()
{
    int a;
    cout<<"Enter the number of values."<<endl;
    cin>>a;
    int values[a];
    cout<<"Enter the values."<<endl;
    for (int i = 0; i < a; i++)
    {
        cin>>values[i];
    }
    int weights[a];
    cout<<"Enter the weights."<<endl;
    for(int j = 0; j < a; j++)
    {
        cin>>weights[j];
    }
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);
    cout<<"Maximum value: "<<knapSack(W, weights, values, n)<<endl;
    return 0;
}