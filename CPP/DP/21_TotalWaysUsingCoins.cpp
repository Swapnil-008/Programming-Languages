#include<bits/stdc++.h>
using namespace std;

// Count no. of ways to achieve target value using infinite supply of each coin
// Memoization
int totalWaysUsingCoinsMemo(int n, int target, vector<int>& coins, vector<vector<int>>& memo)
{
    if(n == 0)
    {
        if(target % coins[0] == 0)
        {
            return 1;
        }
        return 0;
    }
    if(memo[n][target] != -1)
    {
        return memo[n][target];
    }
    int include = 0;
    if(coins[n] <= target)
    {
        include = totalWaysUsingCoinsMemo(n, target - coins[n], coins, memo);
    }
    int exclude = totalWaysUsingCoinsMemo(n - 1, target, coins, memo);
    memo[n][target] = include + exclude;
    return memo[n][target];
}
int totalWaysUsingCoins(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    return totalWaysUsingCoinsMemo(n - 1, target, coins, memo);
}

int totalWaysMemo(int n, vector<int>& coins, int target, vector<vector<int>>& memo)
{
    if(n == 0)
    {
        if(target % coins[0] == 0)
        {
            return 1;
        }
        return 0;
    }
    if(memo[n][target] != -1)
    {
        return memo[n][target];
    }
    int include = 0;
    if(coins[n] <= target)
    {
        include = 1 + totalWaysMemo(n, coins, target - coins[n], memo);
    }
    int exclude = totalWaysMemo(n - 1, coins, target, memo);
    memo[n][target] = include + exclude;
    return memo[n][target];
}

int totalWays(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    return totalWaysMemo(n - 1, coins, target, memo);
}
// Tabulation
int totalWaysUsingCoinsDp(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for(int i = 0; i <= target; i++)
    {
        if(i % coins[0] == 0)
        {
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            int exclude = dp[i - 1][j];
            int include = 0;
            if(coins[i] <= j)
            {
                include = dp[i][j - coins[i]];
            }
            dp[i][j] = include + exclude;
        }
    }
    return dp[n - 1][target];
}
int main()
{
    vector<int> coins = {1, 2, 3};
    int target = 4;
    cout<<"Total ways: "<<totalWaysUsingCoinsDp(coins, target);
}