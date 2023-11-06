
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Set
{
    private:
    vector<int> Elements;
    public:
    int size()
    {
        return Elements.size();
    }
    void addElement(int e)
    {
        Elements.push_back(e);
    }
    int getElement(int key)
    {
        return Elements[key];
    }
};

class Relation
{
    private:
    vector<vector<int>> Elements;
    public:
    int size()
    {
        return Elements.size();
    }
    void addElement(int a, int b)
    {
        vector<int> Pair;
        Pair.push_back(a);
        Pair.push_back(b);
        Elements.push_back(Pair);
    }
    vector<int> getNums(int key)
    {
        return Elements[key];
    }
    void printElement(int key)
    {
        cout<<"["<<Elements[key][0]<<", "<<Elements[key][1]<<"]";
    }
};

void printList(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void printSubsets(Relation identity, Relation extra)
{
    vector<int> nums(extra.size(), 0);
    int sum = 0;
    for (int i = 0; sum <= extra.size(); i++)
    {
        identity.printElement(0);
        for (int j = 1; j < identity.size(); j++)
        {
            cout<<", ";
            identity.printElement(j);
        }
        for (int j = 0; j < extra.size(); j++)
        {
            nums[j] = i % ((int) pow(2, j + 1)) - i % ((int) pow(2, j));
            nums[j] = nums[j] / pow(2, j);
            if (nums[j] > 0)
            {
                cout<<", ";
                extra.printElement(j);
            }
        }
        sum = accumulate(nums.begin(), nums.end(), sum);
        cout<<"\n";
        printList(nums);
    }
}

int main()
{
    Set domain, coDomain;
    Relation identity, extra;
    int n1, n2, x;
    cout<<"Enter the size of the domain.\n";
    cin>>n1;
    cout<<"\nEnter the elements of the domain.\n";
    for (int i = 0; i < n1; i++)
    {
        cout<<"Enter element "<<i + 1<<" of the domain.\n";
        cin>>x;
        domain.addElement(x);
    }
    cout<<"\nEnter the size of the co-domain.\n";
    cin>>n2;
    cout<<"\nEnter the elements of the co-domain.\n";
    for (int i = 0; i < n2; i++)
    {
        cout<<"Enter element "<<i + 1<<" of the co-domain.\n";
        cin>>x;
        coDomain.addElement(x);
    }
    for (int i = 0; i < domain.size(); i++)
    {
        identity.addElement(domain.getElement(i), domain.getElement(i));
    } for (int i = 0; i < domain.size(); i++)
    {
        for (int j = 0; j < coDomain.size(); j++)
        {
            if (domain.getElement(i) == coDomain.getElement(j))
            {
                continue;
            }
            extra.addElement(domain.getElement(i), coDomain.getElement(j));
        }
    }
    printSubsets(identity, extra);
    return 0;
}