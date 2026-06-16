#include<bits/stdc++.h>
using namespace std;

// Memoization - Top-Down
int knapsackMemo(vector<int>& weight, vector<int>& cost, int n, int capacity, vector<vector<int>>& memo)
{
    if(n == 0)
    {
        if(weight[0] <= capacity)
        {
            return cost[0];
        }
        return 0;
    }
    if(memo[n][capacity] != -1)
    {
        return memo[n][capacity];
    }
    int include = INT_MIN;
    if(weight[n] <= capacity)
    {
        include = cost[n] + knapsackMemo(weight, cost, n - 1, capacity - weight[n], memo);
    }
    int exclude = knapsackMemo(weight, cost, n - 1, capacity, memo);
    memo[n][capacity] = max(include, exclude);
    return memo[n][capacity];
}
int knapsack(vector<int>& weight, vector<int>& cost, int capacity)
{
    int n = weight.size();
    vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
    return knapsackMemo(weight, cost, n - 1, capacity, memo);
}

// Tabulation - Bottom-Up
int knapsackDp(vector<int>& weight, vector<int>& cost, int capacity)
{
    int n = weight.size();
    vector<vector<int>>dp(n, vector<int>(capacity + 1, 0));
    for(int i = weight[0]; i <= capacity; i++)
    {
        dp[0][i] = cost[0];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= capacity; j++)
        {
            int include = INT_MIN;
            if(weight[i] <= j)
            {
                include = cost[i] + dp[i - 1][j - weight[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}