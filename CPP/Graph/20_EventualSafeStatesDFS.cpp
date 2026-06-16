#include<bits/stdc++.h>
using namespace std;

// A node is called safe node if all the possible paths from it ends with terminal node (terminal node = node with 0 outdegree)
// The nodes which are not involed in any cycle or leads to a cycle are safe nodes

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int V = graph.size();
        vector<int> visited(V), pathVisited(V);
        vector<int> check(V), safeStates;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                dfs(i, visited, pathVisited, check, graph);
            }
        }
        for(int i = 0; i < V; i++)
        {
            if(check[i] == 1)
            {
                safeStates.push_back(i);
            }
        }
        return safeStates;
    }
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<int>& check, vector<vector<int>>& graph)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        for(int &adjNode: graph[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, visited, pathVisited, check, graph))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[adjNode])
            {
                check[node] = 0;
                return true;
            }
        }
        pathVisited[node] = 0;
        check[node] = 1;
        return false;
    }
};