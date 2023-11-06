
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int start, int end, string input)
{
    for (int i = start; i <= (start + end) / 2; i++)
    {
        if (input.at(i) != input.at(start + end - i))
        {
            return false;
        }
    }
    return true;
}

int minPartitions(string input) {
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        int f = i;
        for (int j = i; j < input.size(); j++)
        {
            if (checkPalindrome(i, j, input))
            {
                f = j;
            }
        }
        i = f;
        count++;
    }
    return count;
}

int main()
{
    string input;
    cout<<"Enter the string.\n";
    cin>>input;
    int minimumPartitions = minPartitions(input);
    cout<<"The minimum number of palindrome substrings = "<<minimumPartitions<<"\n";
    return 0;
}