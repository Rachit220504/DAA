
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> height)
{
    int answer = 0;
    int max = 0;
    for (int i = 0; i < height.size(); i++)
    {
        if (height[max] < height[i])
        {
            max = i;
        }
    }
    int m = height[0];
    for (int i = 1; i <= max; i++)
    {
        if (m < height[i])
        {
            m = height[i];
        }
        answer += m - height[i];
    }
    m = height[height.size() - 1];
    for (int i = height.size() - 2; i >= max; i--)
    {
        if (m < height[i])
        {
            m = height[i];
        }
        answer += m - height[i];
    }
    return answer;
}

int main()
{
    int n;
    vector<int> height;
    cout<<"Enter the horizontal span of the map.\n";
    cin>>n;
    cout<<"Enter the vertical height corresponding to each bar.\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        height.push_back(x);
    }
    cout<<"The amount of water stored = "<<trap(height)<<"\n";
    return 0;
}