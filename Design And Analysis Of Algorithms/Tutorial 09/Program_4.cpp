#include<bits/stdc++.h>
using namespace std;

#define V 3

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
    {
		if (sptSet[v] == false && dist[v] <= min)
        {
			min = dist[v];
            min_index = v;
        }
    }
	return min_index;
}

void printSolution(int dist[])
{
	cout<<"Vertex \t Distance from Source"<<endl;
	for (int i = 0; i < V; i++)
    {
		cout<<i + 1<<" \t\t"<<dist[i]<<endl;
    }
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
    {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
        {
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
				dist[v] = dist[u] + graph[u][v];
            }
        }
	}
	printSolution(dist);
}

int main()
{
    int graph[V][V];
    for (int i = 0; i < V; i++)
    {
        graph[i][i]=0;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            cout<<"Enter weight of edge between nodes "<<i + 1<<" and "<<j + 1<<":";
            cin>>graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }
	dijkstra(graph, 0);
	return 0;
}