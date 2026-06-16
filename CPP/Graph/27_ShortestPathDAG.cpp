#include<bits/stdc++.h>
using namespace std;

// Shortest path from source to each node in undirected Acyclic Graph

void dfsRecursive(int node, vector<int>& visited, vector<vector<pair<int, int>>>& adjNodes, stack<int>& stack)
{
    visited[node] = 1;
    for(int i = 0; i < adjNodes[node].size(); i++)
    {
        int adjNode = adjNodes[node][i].first;
        if(!visited[adjNode])
        {
            dfsRecursive(adjNode, visited, adjNodes, stack);
        }
    }
    stack.push(node);
}

void shortestPathDAG(int V, int source, vector<vector<pair<int, int>>>& adjNodes)
{
    vector<int> visited(V, 0);
    stack<int> stack;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            dfsRecursive(i, visited, adjNodes, stack);
        }
    }
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;
    while(!stack.empty())
    {
        int node = stack.top();
        stack.pop();
        int dist = distance[node];
        if(dist != INT_MAX)
        {
            for(auto adjNode: adjNodes[node])
            {
                int v = adjNode.first;
                int currDist = adjNode.second;
                if(dist + currDist < distance[v])
                {
                    distance[v] = dist + currDist;
                }
            }
        }
    }
    for(int i = 0; i < V; i++)
    {
        if(distance[i] != INT_MAX)
        {
            cout<<"Shortest path from "<<source<<" to "<<i<<" is "<<distance[i]<<endl;
        }
        else{
            cout<<"Node "<<i<<" is not reachable from source "<<source<<endl;
        }
    }
}