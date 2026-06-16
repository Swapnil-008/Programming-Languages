#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> distance(V, INT_MAX);
        vector<vector<int>> adjNodes(V);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adjNodes[u].push_back(v);
            adjNodes[v].push_back(u);
        }
        queue<int> queue;
        queue.push(src);
        distance[src] = 0;
        while(!queue.empty())
        {
            int node = queue.front();
            int dist = distance[node];
            queue.pop();
            for(int &adjNode: adjNodes[node])
            {
                if(dist + 1 < distance[adjNode])
                {
                    distance[adjNode] = dist + 1;
                    queue.push(adjNode);
                }
            }
        }
        for(int i = 0; i < V; i++)
        {
            if(distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }
        return distance;
    }
};


class Solution {
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int count = 0;
        for(char &ch: moves)
        {
            if(ch == 'R')
            {
                count++;
            }
        }
        return max((int)(moves.length() - count), count);
    }
};