#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> a(amount + 1, 0);
    if (amount <= 0)
    {
        return 0;
    } else
    {
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] < amount)
            {
                a[coins[i]] = 1;
            }
            else if(coins[i] == amount)
            {
                return 1;
            } else {}
        }
        int j = 1;
        while (j < a.size())
        {
            vector<int> b;
            for (int i = 0; i < coins.size() && i < 14; i++)
            {
                if (j - coins[i] > 0)
                {
                    if (a[j - coins[i]] != 0)
                    {
                        b.push_back(a[j - coins[i]]);
                    }
                } else if (j - coins[i] == 0)
                {
                    b.push_back(0);
                    break;
                }
                else{}
            }
            if (b.size() != 0)
            {
                sort(b.begin(), b.end());
                a[j] = 1 + b[0];
            }
            j++;
        }
        if (a[amount] == 0)
        {
            return -1;
        } else
        {
            return a[amount];
        }
    }
}

int main()
{
    int n;
    vector<int> coins;
    cout<<"Enter the number of denominations.\n";
    cin>>n;
    cout<<"Enter the values of the denominations.\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        coins.push_back(x);
    }
    int amount;
    cout<<"Enter the amount.\n";
    cin>>amount;
    cout<<"Minimum coins required for the amount: ";
    cout<<coinChange(coins, amount)<<endl;
    return 0;
}