#include<bits/stdc++.h>
using namespace std;

class Solution {
    int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int, int>>> adjNodes(n);

        for(auto &road: roads)
        {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adjNodes[u].push_back({v, time});
            adjNodes[v].push_back({u, time});
        }

        return totalPaths(n, adjNodes);
    }

    int totalPaths(int n, vector<vector<pair<int, int>>>& adjNodes)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pqueue;

        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        distance[0] = 0;
        ways[0] = 1;

        pqueue.push({0, 0});
        while(!pqueue.empty())
        {
            long long time = pqueue.top().first;
            int u = pqueue.top().second;
            pqueue.pop();

            if(time > distance[u]) 
            {
                continue;
            }
            for(auto &adjNode: adjNodes[u])
            {
                int v = adjNode.first;
                int currTime = adjNode.second;

                if(time + currTime < distance[v])
                {
                    distance[v] = time + currTime;
                    ways[v] = ways[u];
                    pqueue.push({distance[v], v});
                }
                else if(time + currTime == distance[v])
                {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};