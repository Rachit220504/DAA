
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

class Relation
{
    private:
    vector<vector<int>> Elements;
    public:
    int searchElement(vector<int> x)
    {
        for (int i = 0; i < Elements.size(); i++)
        {
            if (x == Elements[i])
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

int checkReflexive(Set domain, Set coDomain, Relation relation)
{
    for (int i = 0; i < domain.size(); i++)
    {
        vector<int> x;
        x.push_back(domain.getElement(i));
        x.push_back(domain.getElement(i));
        int search = relation.searchElement(x);
        if (search == 0)
        {
            return 0;
        }
    }
    return 1;
}

int checkSymmetric(Set domain, Set coDomain, Relation relation)
{
    for (int i = 0; i < domain.size(); i++)
    {
        for (int j = 0; j < coDomain.size(); j++)
        {
            vector<int> x, y;
            x.push_back(domain.getElement(i));
            x.push_back(coDomain.getElement(j));
            y.push_back(coDomain.getElement(j));
            y.push_back(domain.getElement(i));
            int search1 = relation.searchElement(x);
            int search2 = relation.searchElement(y);
            if ((search1 == 0 && search2 == 1) || (search1 == 1 && search2 == 0))
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkTransitive(Set domain, Set coDomain, Relation relation)
{
}

int main()
{
    int option;
    Set domain, coDomain;
    Relation relation;
    while (1)
    {
        cout<<"\nRELATION CHECKER\n";
        cout<<"Press '1' to enter the domain and co-domain.\n";
        cout<<"Press '2' to enter the relation.\n";
        cout<<"Press '3' to check if the relation is reflexive.\n";
        cout<<"Press '4' to check if the relation is symmetric.\n";
        cout<<"Press '5' to check if the relation is transitive.\n";
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
            relation.clearElements();
            int n, x1, x2;
            cout<<"Enter the number of elements present in the relation.\n";
            cin>>n;
            cout<<"Enter the elements of the relation in the format [a <space> b].\n";
            for (int i = 0; i < n; i++)
            {
                cout<<"Enter element "<<i + 1<<".\n";
                cin>>x1;
                cin>>x2;
                relation.addElement(x1, x2);
            }
        } else if (option == 3)
        {
            int x = checkReflexive(domain, coDomain, relation);
            if (x == 1)
            {
                cout<<"The function is reflexive.\n";
            } else
            {
                cout<<"The function is not reflexive.\n";
            }
        } else if (option == 4)
        {
            int x = checkSymmetric(domain, coDomain, relation);
            if (x == 1)
            {
                cout<<"The function is symmetric.\n";
            } else
            {
                cout<<"The function is not symmetric.\n";
            }
        } else if (option == 5)
        {
            int x = checkTransitive(domain, coDomain, relation);
            if (x == 1)
            {
                cout<<"The function is transitive.\n";
            } else
            {
                cout<<"The function is not transitive.\n";
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