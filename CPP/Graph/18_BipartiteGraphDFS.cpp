#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++)
        {
            if(color[i] == -1)
            {
                if(!dfs(i, 0, color, graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node, int clr, vector<int>& color, vector<vector<int>>& graph)
    {
        color[node] = clr;
        for(int &adjNode: graph[node])
        {
            if(color[adjNode] == -1)
            {
                if(!dfs(adjNode, !clr, color, graph))
                {
                    return false;
                }
            }
            else if(color[adjNode] == clr)
            {
                return false;
            }
        }
        return true;
    }
};