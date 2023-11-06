

#include <iostream>
using namespace std;

int getMissingElement(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum2 = n * (n + 1) / 2;
    return (sum2 - sum);
}

int main()
{
    int n, arr[100];
    cout<<"Enter the number of elements.\n";
    cin>>n;
    cout<<"\nEnter the elements of the array.\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element "<<(i + 1)<<".\n";
        cin>>arr[i];
    }
    cout<<"\nThe missing element is: "<<getMissingElement(n, arr);
    return 0;
}