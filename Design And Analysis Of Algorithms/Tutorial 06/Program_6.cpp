
#include <bits/stdc++.h>
using namespace std;

int survivor(int n, int i)
{
    int distance = (int) (n - pow(2, floor(log2(n))));
    return ((i + distance * 2 - 1) % n) + 1;
}

int main()
{
    int n, i;
    cout<<"Enter the number of people.\n";
    cin>>n;
    cout<<"Enter the position of the person with the sword.\n";
    cin>>i;
    cout<<"The position of the person remaining at the end is: "<<survivor(n, i)<<"\n";
    return 0;
}