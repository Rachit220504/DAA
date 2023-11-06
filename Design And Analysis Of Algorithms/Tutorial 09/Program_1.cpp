
#include <bits/stdc++.h>
using namespace std;

class node
{
    private:
    char value;
    bool visited;
    public:
    vector<node *> adjacentNodes;
    node(char value)
    {
        this->visited = false;
        this->value = value;
        this->adjacentNodes.clear();
    }
    char getValue()
    {
        return this->value;
    }
    bool checkVisit()
    {
        return this->visited;
    }
    void visit()
    {
        this->visited = true;
    }
    void unvisit()
    {
        this->visited = false;
    }
};

class graph
{
    public:
    vector<node *> nodes;
    void BFS()
    {
        vector<node *> list;
        node *visitor = nodes[0];
        while (1)
        {
            visitor->visit();
            cout<<visitor->getValue()<<" ";
            for (auto i : visitor->adjacentNodes)
            {
                if (!(i->checkVisit()))
                {
                    list.push_back(i);
                }
            }
            while (!(list.empty()) && list[0]->checkVisit())
            {
                for (int i = 0; i < list.size() - 1; i++)
                {
                    list[i] = list[i + 1];
                }
                list.pop_back();
            }
            if (list.empty())
            {
                break;
            }
            visitor = list[0];
            for (int i = 0; i < list.size() - 1; i++)
            {
                list[i] = list[i + 1];
            }
            list.pop_back();
        }
        for (auto i : this->nodes)
        {
            i->unvisit();
        }
        cout<<"\n";
    }
    void DFS()
    {
        vector<node *> list;
        node *visitor = nodes[0];
        while (1)
        {
            visitor->visit();
            cout<<visitor->getValue()<<" ";
            for (auto i : visitor->adjacentNodes)
            {
                if (!(i->checkVisit()))
                {
                    list.push_back(i);
                }
            }
            while (!(list.empty()) && list[list.size() - 1]->checkVisit())
            {
                list.pop_back();
            }
            if (list.empty())
            {
                break;
            }
            visitor = list[list.size() - 1];
            list.pop_back();
        }
        for (auto i : this->nodes)
        {
            i->unvisit();
        }
        cout<<"\n";
    }
    bool testForConnectedness()
    {
        vector<node *> list;
        vector<node *> traversedNodes;
        node *visitor = nodes[0];
        while (1)
        {
            visitor->visit();
            traversedNodes.push_back(visitor);
            for (auto i : visitor->adjacentNodes)
            {
                if (!(i->checkVisit()))
                {
                    list.push_back(i);
                }
            }
            while (!(list.empty()) && list[0]->checkVisit())
            {
                for (int i = 0; i < list.size() - 1; i++)
                {
                    list[i] = list[i + 1];
                }
                list.pop_back();
            }
            if (list.empty())
            {
                break;
            }
            visitor = list[0];
            for (int i = 0; i < list.size() - 1; i++)
            {
                list[i] = list[i + 1];
            }
            list.pop_back();
        }
        for (auto i : this->nodes)
        {
            i->unvisit();
        }
        return (this->nodes.size() == traversedNodes.size());
    }
    bool checkBipartite()
    {
        vector<node *> list;
        vector<int> nums(nodes.size(), 0);
        node *visitor = nodes[0];
        int k = 1;
        while (1)
        {
            visitor->visit();
            for (auto i : visitor->adjacentNodes)
            {
                for (int j = 0; j < nodes.size(); j++)
                {
                    if (nodes[j] == i)
                    {
                        if ((nums[j] == 1 && k == 2) || (nums[j] == 2 && k == 1))
                        {
                            for (auto i : this->nodes)
                            {
                                i->unvisit();
                            }
                            return false;
                        } else
                        {
                            nums[j] = k;
                        }
                    }
                }
                if (!(i->checkVisit()))
                {
                    list.push_back(i);
                }
            }
            while (!(list.empty()) && list[list.size() - 1]->checkVisit())
            {
                list.pop_back();
            }
            if (list.empty())
            {
                break;
            }
            visitor = list[list.size() - 1];
            list.pop_back();
            if (k == 1)
            {
                k = 2;
            } else if (k == 2)
            {
                k = 1;
            }
        }
        for (auto i : this->nodes)
        {
            i->unvisit();
        }
        return true;
    }
    bool checkTree()
    {
        if (this->testForConnectedness())
        {
            vector<node *> list;
            node *visitor = nodes[0];
            while (1)
            {
                visitor->visit();
                for (auto i : visitor->adjacentNodes)
                {
                    if (!(i->checkVisit()))
                    {
                        list.push_back(i);
                    }
                }
                while (!(list.empty()))
                {
                    if (list[list.size() - 1]->checkVisit())
                    {
                        for (auto i : this->nodes)
                        {
                            i->unvisit();
                        }
                        return false;
                    } else
                    {
                        break;
                    }
                }
                if (list.empty())
                {
                    break;
                }
                visitor = list[list.size() - 1];
                list.pop_back();
            }
            for (auto i : this->nodes)
            {
                i->unvisit();
            }
            return true;
        } else
        {
            return false;
        }
    }
};

int main()
{
    int n;
    vector<node *> nodes;
    cout<<"\nEnter the number of nodes.\n";
    cin>>n;
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        char c;
        cout<<"Enter the value of node "<<i + 1<<".\n";
        cin>>c;
        node *X = new node(c);
        nodes.push_back(X);
    }
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the nodes adjacent to node "<<i + 1<<". (Enter '0' to stop.)\n";
        while (1)
        {
            int x;
            cin>>x;
            if (x > 0 && x <= n)
            {
                nodes[i]->adjacentNodes.push_back(nodes[x - 1]);
            } else if (x == 0)
            {
                break;
            } else
            {
                cout<<"Please enter the value requested correctly.\n";
            }
        }
    }
    graph Graph;
    for (int i = 0; i < n; i++)
    {
        Graph.nodes.push_back(nodes[i]);
    }
    cout<<"\nThe BFS traversal of the graph is as follows:\n";
    Graph.BFS();
    cout<<"\nThe DFS traversal of the graph is as follows:\n";
    Graph.DFS();
    cout<<"\nResult of the test of correctedness for the graph: ";
    if (Graph.testForConnectedness())
    {
        cout<<"True\n";
    } else
    {
        cout<<"False\n";
    }
    cout<<"\nResult of the test to check if the graph is a tree: ";
    if (Graph.checkTree())
    {
        cout<<"True\n";
    } else
    {
        cout<<"False\n";
    }
    cout<<"\nResult of the test to check if the graph is bipartite: ";
    if (Graph.checkBipartite())
    {
        cout<<"True\n";
    } else
    {
        cout<<"False\n";
    }
    cout<<"\nResult of the test to check if the graph is 2-colourable: ";
    if (Graph.checkBipartite())
    {
        cout<<"True\n";
    } else
    {
        cout<<"False\n";
    }
    cout<<"\nResult of the test to check if the graph is odd cyclic: ";
    if (Graph.checkBipartite())
    {
        cout<<"False\n";
    } else
    {
        cout<<"True\n";
    }
    cout<<"\n";
    return 0;
}