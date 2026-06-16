#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void prims(int V, vector<vector<pair<int, int>>>& adj)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pqueue;
        vector<int> visited(V);
        pqueue.push({0, { 0, -1}});  // weight, node, parent
        int minCost = 0;
        vector<pair<int, int>> mst;
        while(!pqueue.empty())
        {
            int weight = pqueue.top().first;
            int node = pqueue.top().second.first;
            int parent = pqueue.top().second.second;
            pqueue.pop();
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
            for(auto &adjNodes: adj[node])
            {
                int adjNode = adjNodes.first;
                int wt = adjNodes.second;
                if(!visited[adjNode])
                {
                    pqueue.push({wt, {adjNode, node}});
                }
            }
        }
        cout<<"Minimum Cost: "<<minCost<<endl;
        cout<<"Minimum Spanning Tree: ";
        for(int i = 0; i < mst.size(); i++)
        {
            cout<<"{ "<<mst[i].first<<", "<<mst[i].second<<" }";
        }
    }
};

int main()
{
    int V;
    Solution sln;
    cout<<"Enter no. of vertices: ";
    cin>>V;
    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter parent, vertex, and weight (-1 to stop): \n";
    int weight, vertex, parent;
    while(true)
    {
        cin>>parent>>vertex>>weight;
        if(weight == -1 || vertex == -1 || parent == -1)
        {
            break;
        }
        if(vertex >= V || parent >= V)
        {
            cout<<"\nEnter valid vertex or parent...\n";
            continue;
        }
        adj[parent].push_back({vertex, weight});
        adj[vertex].push_back({parent, weight});
    }
    sln.prims(V, adj);

    return 0;
}

void prims(int V, vector<vector<pair<int, int>>>& adjNodes)
{
    // Min-heap -> weight, node, parent
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pqueue;
    vector<pair<int, int>> mst;
    vector<int> visited(V, 0);
    int minCost = 0;
    pqueue.push({0, {0, -1}});
    while(!pqueue.empty())
    {
        int weight = pqueue.top().first;
        int node = pqueue.top().second.first;
        int parent = pqueue.top().second.second;
        pqueue.pop();
        if(visited[node])
        {
            continue;
        }
        minCost += weight;
        visited[node] = 1;
        if(parent != -1)
        {
            mst.push_back({parent, node});
        }
        for(auto &adjNode: adjNodes[node])
        {
            int adj = adjNode.first;
            int wt = adjNode.second;
            if(!visited[adj])
            {
                pqueue.push({wt, {adj, node}});
            }
        }
    }
    for(int i = 0; i < mst.size(); i++)
    {
        cout<<mst[i].first<<" "<<mst[i].second<<endl;
    }
}