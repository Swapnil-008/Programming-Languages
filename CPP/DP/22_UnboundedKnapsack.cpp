#include<bits/stdc++.h>
using namespace std;

// Memoization
int unboundedKnapsackMemo(int n, int capacity, vector<int>& weight, vector<int>& cost, vector<vector<int>>& memo)
{
    if(n == 0)
    {
        return (int)(capacity / weight[0]) * cost[0];
    }
    if(memo[n][capacity] != -1)
    {
        return memo[n][capacity];
    }
    int include = 0;
    if(weight[n] <= capacity)
    {
        include = cost[n] + unboundedKnapsackMemo(n, capacity - weight[n], weight, cost, memo);
    }
    int exclude = unboundedKnapsackMemo(n - 1, capacity, weight, cost, memo);
    memo[n][capacity] = max(include, exclude);
    return memo[n][capacity];
}
int unboundedKnapsack(vector<int>& weight, vector<int>& cost, int capacity)
{
    int n = weight.size();
    vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
    return unboundedKnapsackMemo(n-1, capacity, weight, cost, memo);
}

// Tabulation
int unboundedKnapsack(vector<int>& weight, vector<int>& cost, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for(int i = 0; i < capacity; i++)
    {
        if((i % weight[0]) == 0)
        {
            dp[0][i] = (int)(i / weight[0]) * cost[0];
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= capacity; j++)
        {
            int include = 0;
            if(weight[i] <= j)
            {
                include = cost[i] + dp[i][j - weight[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}