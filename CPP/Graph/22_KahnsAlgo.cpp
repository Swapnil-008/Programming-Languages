#include<bits/stdc++.h>
using namespace std;

// Kahn’s algorithm processes nodes with zero indegree and removes their outgoing edges, ensuring that all dependencies are resolved before a node is processed.
// It is usefull in 

// Insert all vertices with 0 indegree into the queue
// Take them out one by one, (Considered, that element is removed from the graph, it means the edges going from it towards its adjacent nodes are also removed that's why we are reducing the indegree of those) after taking the vertex out reduce the indegree of all adjacent nodes of that vertex by one
// If on reduction of indegree of any vertex it beocomes zero, insert it into queue
// Reduction of an edge states elimination of that edge from the graph

// Cycle Detection:
// In a cycle, no any vertex have indegree 0
// So queue becomes empty before processing all vertices
// Hence count != V


vector<int> findIndegree(int V, vector<vector<int>>& adjNodes)
{
    vector<int> indegree(V, 0);
    for(int i = 0; i < adjNodes.size(); i++)
    {
        for(int j = 0; j < adjNodes[i].size(); j++)
        {
            int adjNode = adjNodes[i][j];
            indegree[adjNode]++;
        }
    }
    return indegree;
}

// adjNodes[i]th contains nodes adjacent to ith vertex
void kahnsAlgorithm(int V, vector<vector<int>>& adjNodes)
{
    vector<int> indegree = findIndegree(V, adjNodes);
    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topologicalSort;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topologicalSort.push_back(node);
        for(int adjNode : adjNodes[node])
        {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }
    for(int node: topologicalSort)
    {
        cout<<node<<" ";
    }
}

int main()
{
    int V = 6;
    vector<vector<int>> vect = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    kahnsAlgorithm(V, vect);
}