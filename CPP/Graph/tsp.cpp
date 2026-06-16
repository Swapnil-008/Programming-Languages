#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> cost;
vector<bool> visited;
map<pair<int, vector<bool>>, int> dp;

int tsp(int curr, int count)
{
    // Base case: all cities visited
    if(count == n)
    {
        return cost[curr][0];  // return to start
    }  

    // If already computed
    if(dp.find({curr, visited}) != dp.end())
    {
        return dp[{curr, visited}];
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            int temp = cost[curr][i] + tsp(i, count + 1);
            ans = min(ans, temp);
            visited[i] = false;  // backtrack
        }
    }
    return dp[{curr, visited}] = ans;
}

int main()
{
    cost = {
        {0,10,15,20},
        {5,0,9,10},
        {6,13,0,12},
        {8,8,9,0}
    };
    n = cost.size();
    visited.assign(n, false);
    visited[0] = true;  // start from city 0
    cout << "Minimum TSP Cost: " << tsp(0, 1);
}