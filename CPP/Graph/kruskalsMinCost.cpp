#include<bits/stdc++.h>
using namespace std;

// Pick the smallest edge that doesn't form the cycle, if on include some edge cycle is going to form, skip that edge 

class Solution {
  public:
    void kruskals(int V, vector<vector<pair<int, int>>>& adj)
    {
        // vector<pair<int, pair<int, int>>> edges;
        // for(int i = 0; i < V; i++)
        // {
        //     for(auto &adjNodes: adj[i])
        //     {
        //         int adjNode = adjNodes.first;
        //         int wt = adjNodes.second;
        //         int parent = i;
        //         edges.push_back({wt, {parent, adjNode}});
        //     }
        // }
        // sort(edges.begin(), edges.end());

        // vector<int> component(V);
        // for(int i = 0; i < V; i++)
        // {
        //     component[i] = i;
        // }
        // int minCost = 0;
        // vector<pair<int, int>> mst;
        // int totaledges = edges.size();
        // int requiredEdges = V - 1;
        // int i = 0;

        // while(i < totaledges && requiredEdges > 0)
        // {
        //     int wt = edges[i].first;
        //     int u = edges[i].second.first;
        //     int v = edges[i].second.second;
        //     int componentU = component[u];
        //     int componentV = component[v];
        //     if(componentU != componentV)
        //     {
        //         minCost += wt;
        //         mst.push_back({u, v});
        //         requiredEdges--;
        //         for(int j = 0; j < V; j++)
        //         {
        //             if(component[j] == componentU)
        //             {
        //                 component[j] = componentV;
        //             }
        //         }
        //     }
        //     i++;
        // }

        vector<pair<int, pair<int, int>>> edjes;
        for(int i = 0; i < V; i++)
        {
            for(auto &adjNodes: adj[i])
            {
                edjes.push_back({adjNodes.second, {i, adjNodes.first}});
            }
        }
        sort(edjes.begin(), edjes.end());
        int totalEdjes = edjes.size();
        int requiredEdjes = V - 1;

        vector<pair<int, int>> mst;
        vector<int> component(V);
        for(int i = 0; i < V; i++)
        {
            component[i] = i;
        }
        int i = 0;
        int minCost = 0;
        while(i < totalEdjes && requiredEdjes > 0)
        {
            int wt = edjes[i].first;
            int u = edjes[i].second.first;
            int v = edjes[i].second.second;
            
            int componentU = component[u];
            int componentV = component[v];

            if(componentU != componentV)
            {
                minCost += wt;
                requiredEdjes--;
                mst.push_back({u, v});
                for(int j = 0; j < V; j++)
                {
                    if(component[j] == componentU)
                    {
                        component[j] = componentV;
                    }
                }
            }
            i++;
        }
        cout<<"Minimum Cost: "<<minCost<<endl;
        cout<<"Minimum Spanning Tree: ";
        for(int i = 0; i < mst.size(); i++)
        {
            cout<<"{ "<<mst[i].first<<", "<<mst[i].second<<" }";
        }
    }
};

//Steps:
//      Step1: sort all edges by weight
//      Step2: traverse all the sorted edges and add the edge in mst, whose v is not existed in the connected component of u
//      Step3: if the edge is added in the mst update the component array of all the vetices having u component to component v

// (ChatGpt)
// Step 1:
// Sort all edges in non-decreasing order of their weights.
// Step 2:
// Traverse the sorted edge list, and for each edge (u, v):
// If u and v belong to different components, then include this edge in the MST.
// Step 3:
// When an edge (u, v) is added to MST,
// update the component[] array —
// i.e., set all vertices having the same component as u to have the component of v

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
    sln.kruskals(V, adj);

    return 0;

}