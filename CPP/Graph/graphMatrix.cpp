#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    vector<vector<int>> graph;
    int isDirected;
    int isWeighted;
    Graph()
    {
        int n;
        cout<<"Enter No. of vertices: ";
        cin>>n;
        graph.resize(n, vector<int>(n));
        cout<<"Graph directed (0/1): ";
        cin>>isDirected;
        cout<<"Graph weighted (0/1): ";
        cin>>isWeighted;
    }
    void readGraphMatrix();
    void readGraphEdges();
    void showGraph();
    vector<int> inDegree();
    vector<int> outDegree();
};

void Graph::readGraphMatrix()
{
    int n = graph.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x;
            cout<<"Enter weight of Edge between "<<i<<" and "<<j<<": ";
            cin>>x;
            if(!isWeighted)
            {
                x = (x >= 1 ? 1 : 0);
            }
            graph[i][j] = x;
        }
    }
}

void Graph::readGraphEdges()
{
    int n = graph.size();
    int u, v, w;
    while(true)
    {
        cout<<"Enter Edge: (start, end, and weight): ";
        cin >> u >> v >> w;
        if(u == -1 && v == -1)
        {
            break;
        }
        if(u < 0 || v < 0 || u >= n || v >= n)
        {
            cout << "Invalid vertices... try again\n";
            continue;
        }
        if(!isWeighted)
        {
            w = (w >= 1) ? 1 : 0;
        }
        graph[u][v] = w;
        if(!isDirected)
        {
            graph[v][u] = w;
        }
    }
}

void Graph::showGraph()
{
    int n = graph.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> Graph::inDegree()
{
    int n = graph.size();
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j])
            {
                indegree[j]++;
            }
        }
    }
    return indegree;
}

vector<int> Graph::outDegree()
{
    int n = graph.size();
    vector<int> outdegree(n, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j])
            {
                outdegree[i]++;
            }
        }
    }
    return outdegree;
}

int main()
{
    Graph gph;
    // gph.readGraphMatrix();
    gph.readGraphEdges();
    gph.showGraph();
    auto indegree = gph.inDegree();
    auto outdegree = gph.outDegree();
    cout<<"\nIndegree:  ";
    for(int i = 0; i < indegree.size(); i++)
    {
        cout<<i<<": "<<indegree[i]<<", ";
    }
    cout<<"\nOutdegree: ";
    for(int i = 0; i < outdegree.size(); i++)
    {
        cout<<i<<": "<<outdegree[i]<<", ";
    }
    return 0;
}