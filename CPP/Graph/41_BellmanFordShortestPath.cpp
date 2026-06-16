// Bellman ford algorithm only works on directed graph
// For conversion of undirected graph to directed graph add both the edges (u -> v) and(v -> u) with same edge weight into the edge list.
// Dijkstra's algorithm fails when a graph has negative edges or negative cycle

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bellmanFord(int V, int source, vector<vector<pair<int, int>>>& adj)
    {
        vector<vector<int>> edges;
        for(int i = 0; i < adj.size(); i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
            {
                edges.push_back({i, adj[i][j].first, adj[i][j].second});
            }
        }
        vector<int> distance(V, INT_MAX);
        distance[source] = 0;
        // Distance of every node can be updated at most (V (total nodes) - 1), if still it can update denotes presense of negative cycle
        for(int i = 0; i < V - 1; i++)
        {
            for(int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(distance[u] != INT_MAX && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
        // One more iteration after V - 1 iterations to check whether cycle is present or not
        bool isCycle = false;
        for(int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                isCycle = true;
                break;
            }
        }
        if(isCycle)
        {
            cout<<"\nNegative cycle found!"<<endl;
        }
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << source << " to vertex " << i << " distance is " << distance[i] << endl;
        }
    }
};

int main()
{
    int V;
    Solution sln;
    cout << "Enter no. of vertices: ";
    cin >> V;
    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter parent, vertex, and weight (-1 to stop): \n";
    int weight, vertex, parent;
    while (true)
    {
        cin >> parent >> vertex >> weight;
        if (weight == -1 || vertex == -1 || parent == -1)
            break;

        if (vertex >= V || parent >= V)
        {
            cout << "\nEnter valid vertex or parent...\n";
            continue;
        }
        adj[parent].push_back({vertex, weight});
        // adj[vertex].push_back({parent, weight}); if the graph is undirected add this
    }
    int source;
    while (true)
    {
        cout << "Enter source: ";
        cin >> source;
        if (source >= V)
        {
            cout << "Enter valid source...\n";
        }
        else{
            break;
        }
    }
    sln.bellmanFord(V, source, adj);
    return 0;
}
/*
    Explanation of why Bellman-Ford runs for (V - 1) iterations:

    Consider a path:
    0 -> 1 -> 2 -> 3 -> 4 (with unit weights)

    The shortest distance to any node depends on the shortest
    distance of the nodes before it in the path.

    In Bellman-Ford, we relax all edges in each iteration.
    Due to the order of edges (for example: 3->4, 2->3, 1->2, 0->1),
    the shortest distance information propagates one edge forward
    per iteration in the worst case.

    So:

    Iteration 1:
    - Distance to node 1 gets updated

    Iteration 2:
    - Distance to node 2 gets updated

    Iteration 3:
    - Distance to node 3 gets updated

    Iteration 4:
    - Distance to node 4 gets updated

    This shows that in the worst case, shortest distance propagates
    one edge per iteration.

    Since the maximum number of edges in any shortest path is (V - 1),
    we need (V - 1) iterations to ensure all shortest paths are computed.

    Therefore, Bellman-Ford relaxes all edges (V - 1) times.
*/
