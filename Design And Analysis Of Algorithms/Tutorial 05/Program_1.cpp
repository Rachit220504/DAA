
#include <bits/stdc++.h>
using namespace std;

int checkPosition(int num, vector<int> nums, int start, int end)
{
    if (nums.size() == 0)
    {
        return 0;
    } else
    {
        if (end <= start)
        {
            if (num > nums[start])
            {
                return (start + 1);
            } else
            {
                return start;
            }
        }
        int mid = (start + end - 1) / 2;
        if (num == nums[mid])
        {
            return mid;
        } else if (num < nums[mid])
        {
            return checkPosition(num, nums, start, mid - 1);
        } else
        {
            return checkPosition(num, nums, mid + 1, end);
        }
    }
}

vector<int> insertionSort(int num, vector<int> nums)
{
    nums.push_back(num);
    int position = checkPosition(num, nums, 0, nums.size() - 1);
    for (int i = nums.size() - 1; i > position; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[position] = num;
    return nums;
}

void printList(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int n;
    vector<int> nums;
    cout<<"Enter the number of elements.\n";
    cin>>n;
    cout<<"Enter the elements.\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        nums = insertionSort(x, nums);
    }
    cout<<"The sorted elements are as follows:\n";
    printList(nums);
    return 0;
}