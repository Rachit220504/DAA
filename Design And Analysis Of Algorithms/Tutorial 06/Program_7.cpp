#include<bits/stdc++.h>
using namespace std;

int Count = 0;  

int findThirdMax(vector<int> &nums, int n)
{
    int a = INT_MIN;
    int b = INT_MIN;
    int c = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > a)
        {
            c = b;
            b = a;
            a = nums[i];
            Count += 1;  
        } else if (nums[i] > b && nums[i] != a)
        {
            c = b;
            b = nums[i];
            Count += 2; 
        } else if (nums[i] > c && nums[i] != b)
        {
            c = nums[i];
            Count += 3;  
        } else
        {
            Count += 3;  
        }
    }
    if (c == INT_MIN || c == b)
    {
        return a;
    }
    return c;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array.\n";
    cin>>n;
    if (n < 3)
    {
        cout<<"Size of the array is less than 3, therefore no third maximum exists for the array.\n";
    } else {
        vector<int> nums;
        cout<<"Enter the elements.\n";
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;
            nums.push_back(a);
        }
        int ans = findThirdMax(nums, n);
        cout<<"Third maximum = "<<ans<<endl;
        cout<<"Number of comparisons: "<<Count<<endl;
    }
    return 0;
}