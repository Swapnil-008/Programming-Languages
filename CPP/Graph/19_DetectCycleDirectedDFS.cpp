#include<bits/stdc++.h>
using namespace std;

// The logic behind finding the cycle in a directed graph, if the node is visited and it is visited in the same path it denotes the presence of cycle
// While backtracking we will undo the record of visited path, but we keep track of visited nodes

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjNodes(V);
        for(auto &adjNode: edges)
        {
            int u = adjNode[0];
            int v = adjNode[1];
            adjNodes[u].push_back(v);
        }
        vector<int> visited(V, 0);
        vector<int> path(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, visited, path, adjNodes))
                {
                    return true;
                }
            }
        }
        return false;
    }
    int dfs(int node, vector<int>& visited, vector<int>& path, vector<vector<int>>& adjNodes)
    {
        visited[node] = 1;
        path[node] = 1;
        for(int &adjNode: adjNodes[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, visited, path, adjNodes))
                {
                    return true;
                }
            }
            else if(visited[adjNode] && path[adjNode])
            {
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
};