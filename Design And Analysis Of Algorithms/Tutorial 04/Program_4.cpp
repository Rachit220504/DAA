
#include <bits/stdc++.h>
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
    void clearElements()
    {
        Elements.clear();
    }
    int getElement(int key)
    {
        return Elements[key];
    }
};

class Function
{
    private:
    vector<vector<int>> Elements;
    public:
    int searchOrdinate(int x)
    {
        for (int i = 0; i < Elements.size(); i++)
        {
            if (x == Elements[i][1])
            {
                return 1;
            }
        }
        return 0;
    }
    void addElement(int a, int b)
    {
        vector<int> Pair;
        Pair.push_back(a);
        Pair.push_back(b);
        Elements.push_back(Pair);
    }
    void clearElements()
    {
        Elements.clear();
    }
    vector<int> getNums(int key)
    {
        return Elements[key];
    }
};

int checkOnto(Set domain, Set coDomain, Function function)
{
    for (int i = 0; i < coDomain.size(); i++)
    {
        int search = function.searchOrdinate(coDomain.getElement(i));
        if (search == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int option;
    Set domain, coDomain;
    Function function;
    while (1)
    {
        cout<<"\nONTO CHECKER\n";
        cout<<"Press '1' to enter the domain and co-domain.\n";
        cout<<"Press '2' to enter the function.\n";
        cout<<"Press '3' to check if the function is onto.\n";
        cout<<"Press '0' to exit the program.\n";
        cin>>option;
        cout<<"\n";
        if (option == 1)
        {
            domain.clearElements();
            coDomain.clearElements();
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
        } else if (option == 2)
        {
            function.clearElements();
            int n, x1, x2;
            cout<<"Enter the number of elements present in the function.\n";
            cin>>n;
            cout<<"Enter the elements of the function in the format [a <space> b].\n";
            for (int i = 0; i < n; i++)
            {
                cout<<"Enter element "<<i + 1<<".\n";
                cin>>x1;
                cin>>x2;
                function.addElement(x1, x2);
            }
        } else if (option == 3)
        {
            int x = checkOnto(domain, coDomain, function);
            if (x == 1)
            {
                cout<<"The function is onto.\n";
            } else
            {
                cout<<"The function is into.\n";
            }
        } else if (option == 0)
        {
            break;
        } else{
            cout<<"Please choose one of the above mentioned choices only.\n";
        }
    }
    return 0;
}