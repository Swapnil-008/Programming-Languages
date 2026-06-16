#include <bits/stdc++.h>
using namespace std;

// We have to find shortest path from source node so that all the vertices must be covered
// Time complexity: E(logV)
class Solution {
public:
    void dijkstra(int V, int source, vector<vector<pair<int, int>>>& adj)
    {
        vector<int> distance(V, INT_MAX);
        vector<int> parent(V, -1); // 👈 added to track path
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqueue;

        distance[source] = 0;
        pqueue.push({0, source});

        while (!pqueue.empty())
        {
            int dist = pqueue.top().first;
            int node = pqueue.top().second;
            pqueue.pop();

            for (auto &adjNodes : adj[node])
            {
                int adjNode = adjNodes.first;
                int currDist = dist + adjNodes.second;

                if (currDist < distance[adjNode])
                {
                    distance[adjNode] = currDist;
                    parent[adjNode] = node; // 👈 store parent
                    pqueue.push({currDist, adjNode});
                }
            }
        }

        // Print shortest distances and paths
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << source << " to vertex " << i << " distance is " << distance[i] << endl;
            cout << "Path: ";
            printPath(i, parent);
            cout << endl;
        }
    }

    void printPath(int v, vector<int>& parent)
    {
        if (v == -1)
        {
            return;
        }
        printPath(parent[v], parent);
        cout << v << " ";
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
        adj[vertex].push_back({parent, weight});
    }
    // To just scan the valid source
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

    sln.dijkstra(V, source, adj);
    return 0;
}