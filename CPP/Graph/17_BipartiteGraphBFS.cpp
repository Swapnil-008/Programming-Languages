#include<bits/stdc++.h>
using namespace std;

// A graph is a bipartite if it can be divided into two parts set A and set B such that every edge in the graph connects the node in set A and node in set B

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);
        queue<int> queue;
        for(int i = 0; i < V; i++)
        {
            if(color[i] != -1)
            {
                continue;
            }
            queue.push(i);
            color[i] = 0;
            while(!queue.empty())
            {
                int node = queue.front();
                queue.pop();
                for(int &adjNode: graph[node])
                {
                    if(color[adjNode] == -1)
                    {
                        color[adjNode] = (color[node] == 0) ? 1 : 0;
                        queue.push(adjNode);
                    }
                    else if(color[adjNode] == color[node])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};