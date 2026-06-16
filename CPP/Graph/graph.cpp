#include<bits/stdc++.h>
using namespace std;

void dfsRecursive(int v, vector<vector<int>>& matrix, vector<int>& visited)
{
    cout << v << " ";
    visited[v] = 1;
    for(int i = 0; i < matrix[v].size(); i++)
    {
        int neighbour = matrix[v][i];

        if(!visited[neighbour])
        {
            dfsRecursive(neighbour, matrix, visited);
        }
    }
}
void dfs(vector<vector<int>>& matrix)
{
    // nth row of matrix representing adjacency vertices of nth vertex
    // 0 to n-1 are vertices
    // This code is for connected graph, for discounnected we have to call this dfsRecursive function in loop for all remaining unvisited nodes
    vector<int> visited(matrix.size(), 0);
    dfsRecursive(0, matrix, visited);
}

void bfsTraversal(int v, vector<int>& visited, vector<vector<int>>& matrix)
{
    queue<int> queue;
    queue.push(v);
    visited[v] = 1;
    while(!queue.empty())
    {
        v = queue.front();
        queue.pop();
        cout<<v<<" ";
        for(int i = 0; i < matrix[v].size(); i++)
        {
            if(!visited[matrix[v][i]])
            {
                queue.push(matrix[v][i]);
                visited[matrix[v][i]] = 1;
            }
        }
    }
}
void bfs(vector<vector<int>>& matrix)
{
    // nth row of matrix representing adjacency vertices of nth vertex
    // 0 to n-1 are vertices
    vector<int> visited(matrix.size(), 0);
    bfsTraversal(0, visited, matrix);
}
void minCostPrims(int V, vector<vector<pair<int, int>>>& matrix)
{
    // Min heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pqueue;
    vector<int> visited(V, 0);
    pqueue.push({0, {0, -1}});
    int minCost = 0;
    vector<pair<int, int>> mst;
    while(!pqueue.empty())
    {
        auto temp = pqueue.top();
        pqueue.pop();
        int weight = temp.first;
        int node = temp.second.first;
        int parent = temp.second.second;
        if(visited[node])
        {
            continue;
        }
        visited[node] = 1;
        minCost += weight;
        if(parent != -1)
        {
            mst.push_back({parent, node});
        }
        if(mst.size() == V - 1)
        {
            break;
        }
        for(auto adjNodes: matrix[node])
        {
            if(!visited[adjNodes.first])
            {
                pqueue.push({adjNodes.second, {adjNodes.first, node}});
            }
        }
    }
    cout<<"Minimum Cost: "<<minCost<<endl;
    cout<<"Minimum Spanning Tree: ";
    for(int i = 0; i < mst.size(); i++)
    {
        cout<<"{ "<<mst[i].first<<", "<<mst[i].second<<" },";
    }
}
void minCostKruskals(int V, vector<vector<pair<int, int>>>& matrix)
{
    // nth row of matrix representing adjacency vertices of nth vertex
    // 0 to n-1 are vertices
    vector<vector<int>> edges;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            // To avoid the same edge 0 -> 1 and 1 -> 0 adding twice
            if(i > matrix[i][j].first)
            {
                continue;
            }
            edges.push_back({matrix[i][j].second, i, matrix[i][j].first});
        }
    }
    sort(edges.begin(), edges.end());
    int totalEdges = edges.size();
    int requiredEdges = V - 1;
    vector<int> component(V);
    for(int i = 0; i < V; i++)
    {
        component[i] = i;
    }
    int minCost = 0;
    vector<pair<int, int>> mst;
    int i = 0;
    while(i < totalEdges && requiredEdges > 0)
    {
        int weight = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        int componentU = component[u];
        int componentV = component[v];

        // It defines on adding edge u -> v cycle won't form
        if(componentU != componentV)
        {
            minCost += weight;
            mst.push_back({u, v});
            requiredEdges--;
            cout<<"Component array: ";
            for(int j = 0; j < V; j++)
            {
                cout<<component[j]<<" ";
                if(component[j] == componentU)
                {
                    component[j] = componentV;
                }
            }
            cout<<endl;
        }
        i++;
    }
    if(requiredEdges != 0)
    {
        cout << "Graph is disconnected. MST not possible." << endl;
    }
    cout<<"Min Cost: "<<minCost<<endl;
    for(int k = 0; k < mst.size(); k++)
    {
        cout<<"{ "<<mst[k].first<<", "<<mst[k].second<<" }";
    }
}

void printPath(int node, int source, vector<int>& parent)
{
    if(node == -1)
    {
        cout<<"No path!";
        return;
    }
    if(node == source)
    {
        cout<<source<<" -> ";
        return;
    }
    printPath(parent[node], source, parent);
    cout<<node<<" -> ";
}

void shortestPathDijkstra(int V, int source, vector<vector<pair<int, int>>>& matrix)
{
    vector<int> distance(V, INT_MAX);
    vector<int> parent(V, -1);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqueue;
    pqueue.push({0, source});
    while(!pqueue.empty())
    {
        int dist = pqueue.top().first;
        int node = pqueue.top().second;
        pqueue.pop();
        if(dist > distance[node])
        {
            continue;
        }
        for(auto &adjNodes: matrix[node])
        {
            int adjNode = adjNodes.first;
            int currDist = dist + adjNodes.second;
            if(currDist < distance[adjNode])
            {
                distance[adjNode] = currDist;
                parent[adjNode] = node;
                pqueue.push({currDist, adjNode});
            }
        }
    }
    // Print shortest path from source to each vertex
    for(int i = 0; i < V; i++)
    {
        cout<<"Shortest distance between "<<source<<" to "<<i<<" is: "<<distance[i]<<endl;
        cout<<"Shortest path: ";
        printPath(i, source, parent);
        cout<<endl;
    }
}

int main()
{
    int V;
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
    shortestPathDijkstra(V, source, adj);
    // minCostKruskals(V, adj);
    return 0;
}
