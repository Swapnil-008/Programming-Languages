#include<bits/stdc++.h>
using namespace std;

// If the node is already visited, it should be visited from the parent of current node or same edge, else it is visted because of any other edge which denotes the presence of cycle or a node can be visited from multiple directions
// Time complexicity: O(n + 2E) every edge is visited twice
// Space complexicity: O(n) query that stores the unvisited nodes

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges)
    {
        vector<int> visited(V, 0);
        vector<vector<int>> adjNodes(V);
        for(auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjNodes[u].push_back(v);
        }
        for(int i = 0; i < V; i++)
        {
            queue<pair<int, int>> queue;
            if(visited[i])
            {
                continue;
            }
            queue.push({i, -1});
            visited[i] = 1;
            while(!queue.empty())
            {
                int node = queue.front().first;
                int parent = queue.front().second;
                queue.pop();
                for(int &adjNode: adjNodes[node])
                {
                    if(!visited[adjNode])
                    {
                        queue.push({adjNode, node});
                        visited[adjNode] = 1;
                    }
                    else if(adjNode != parent)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};