#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<int> visited(V);
        vector<vector<int>> adjNodes(V);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjNodes[u].push_back(v);
            adjNodes[v].push_back(u);
        }
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, visited, adjNodes))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adjNodes)
    {
        visited[node] = 1;
        for(int i = 0; i < adjNodes[node].size(); i++)
        {
            if(!visited[adjNodes[node][i]])
            {
                if(dfs(adjNodes[node][i], node, visited, adjNodes))
                {
                    return true;
                }
            }
            else if(adjNodes[node][i] != parent)
            {
                return true;
            }
        }
        return false;
    }
};