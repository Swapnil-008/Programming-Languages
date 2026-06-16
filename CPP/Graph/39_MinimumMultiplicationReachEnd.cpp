#include<bits/stdc++.h>
using namespace std;

class Solution {
    int MOD = 1000;
  public:
    int minSteps(vector<int>& arr, int start, int end)
    {
        vector<int> distance(1000, INT_MAX);
        distance[start] = 0;
        queue<pair<int, int>> queue;
        queue.push({start, 0});
        while(!queue.empty())
        {
            int node = queue.front().first;
            int steps = queue.front().second;
            queue.pop();
            for(int &num: arr)
            {
                int temp = (node * num) % MOD;
                if(steps + 1 < distance[temp])
                {
                    distance[temp] = steps + 1;
                    queue.push({temp, steps + 1});
                }
            }
        }
        return distance[end] == INT_MAX ? -1 : distance[end];
    }
};