#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        // nodes with 0 outdegree are terminal nodes
        // A node is called safe node if all the possible paths from it ends with terminal node (terminal node = node with 0 outdegree)
        // we reverse every edge so now we need indegree 0 instead of outdegree, if it is possible to make the indegree 0 of any node then it will be a safe node

        int V = graph.size();
        vector<vector<int>> adjNodes(V);
        for(int i = 0; i < V; i++)
        {
            for(int &adjNode: graph[i])
            {
                int u = i;
                int v = adjNode;
                adjNodes[v].push_back(u);
            }
        }
        vector<int> indegree = findIndegree(V, adjNodes);
        queue<int> queue;
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
        vector<int> safeStates(V);
        while(!queue.empty())
        {
            int node = queue.front();
            queue.pop();
            safeStates[node] = 1;
            for(int adjNode : adjNodes[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                {
                    queue.push(adjNode);
                }
            }
        }
        vector<int> safeNodes;
        for(int i = 0; i < V; i++)
        {
            if(safeStates[i] == 1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};