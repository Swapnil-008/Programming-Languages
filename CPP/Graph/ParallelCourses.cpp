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
    int minimumSemesters(int n, vector<vector<int>>& relations)
    {
        vector<vector<int>> adjNodes(n);
        for(auto &relation: relations)
        {
            int u = relation[0] - 1;
            int v = relation[1] - 1;
            adjNodes[u].push_back(v);
        }
        vector<int> indegree = findIndegree(n, adjNodes);
        queue<int> queue;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
        int semester = 0;
        while(!queue.empty())
        {
            int size = queue.size();
            semester++;
            for(int i = 0; i < size; i++)
            {
                int node = queue.front();
                queue.pop();
                n--;
                for(int &adjNode: adjNodes[node])
                {
                    indegree[adjNode]--;
                    if(indegree[adjNode] == 0)
                    {
                        queue.push(adjNode);
                    }
                }
            }
        }
        return n == 0 ? semester : -1;
    }
};