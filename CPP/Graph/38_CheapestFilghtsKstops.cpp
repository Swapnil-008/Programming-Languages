#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> distance(n, INT_MAX);
        vector<vector<pair<int, int>>> adjNodes(n);
        for(auto &flight: flights)
        {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adjNodes[u].push_back({v, price});
        }
        queue<pair<int, pair<int, int>>> queue;  // stops taken till now, node, distance / price
        queue.push({0, {src, 0}});
        distance[src] = 0;
        while(!queue.empty())
        {
            int stops = queue.front().first;
            int node = queue.front().second.first;
            int price = queue.front().second.second;
            queue.pop();
            if(stops > k)
            {
                continue;
            }
            for(auto &adjNode: adjNodes[node])
            {
                int adj = adjNode.first;
                int cost = adjNode.second;
                if(price + cost < distance[adj] && stops <= k)
                {
                    distance[adj] = price + cost;
                    queue.push({stops + 1, {adj, distance[adj]}});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};