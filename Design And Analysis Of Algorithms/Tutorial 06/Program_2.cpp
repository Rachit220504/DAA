

#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& pots)
{
    int n = pots.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = pots[i];
        if (i < n - 1) {
            dp[i][i + 1] = max(pots[i], pots[i + 1]);
        }
    }
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = max(pots[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), pots[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    vector<int> coins;
    cout<<"Enter the number of pots.\n";
    cin>>n;
    cout<<"Enter the gold coins in each pot.\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        coins.push_back(x);
    }
    int maximumCoins = maxCoins(coins);
    cout<<"Maximum number of coins you can collect: "<<maximumCoins<<"\n";
    return 0;
}