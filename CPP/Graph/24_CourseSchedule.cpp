#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIndegree(vector<vector<int>>& adjNodes)
    {
        vector<int> indegree(adjNodes.size());
        for(auto &adjNode: adjNodes)
        {
            for(int &adj: adjNode)
            {
                indegree[adj]++;
            }
        }
        return indegree;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // Problem states prerequisites[i] = [ai, bi]
        // You must take course bi before ai
        // In topological sort, if there is an edge u -> v, u must be completed before v
        // So we create an edge from bi -> ai in the adjacency list
        
        vector<vector<int>> adjNodes(numCourses);
        for(auto &prerequisite: prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adjNodes[v].push_back(u);
        }
        
        vector<int> indegree = findIndegree(adjNodes);
        queue<int> queue;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }

        while(!queue.empty())
        {
            int node = queue.front();
            queue.pop();
            numCourses--;
            for(int &adjNode: adjNodes[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                {
                    queue.push(adjNode);
                }
            }
        }
        return numCourses == 0;
    }
};