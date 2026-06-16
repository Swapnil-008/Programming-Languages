#include<bits/stdc++.h>
using namespace std;

// Cycle Detection:
// In a cycle, no any vertex have indegree 0
// So queue becomes empty before processing all vertices
// Hence count != V

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

// adjNodes[i]th contains nodes adjacent to ith vertex
bool detectCycleDirectedBFS(int V, vector<vector<int>>& adjNodes)
{
    vector<int> indegree = findIndegree(V, adjNodes);
    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for(int adjNode : adjNodes[node])
        {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }
    if(count != V)
    {
        return true;
    }
    return false;
}

int main()
{
    int V = 6;
    vector<vector<int>> vect = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    cout<<detectCycleDirectedBFS(V, vect);

    return 0;
}