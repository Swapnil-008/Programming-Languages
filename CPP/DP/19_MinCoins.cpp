#include<bits/stdc++.h>
using namespace std;

// Memoization
int minCoinsMemo(int n, int target, vector<int>& coins, vector<vector<int>>& memo)
{
    if(n == 0)
    {
        if(target % coins[0] == 0)
        {
            return target / coins[0];
        }
        return 1e9;  // Target can't be achieved
    }
    if(memo[n][target] != -1)
    {
        return memo[n][target];
    }
    int exclude = minCoinsMemo(n - 1, target, coins, memo);
    int include = 1e9;
    if(coins[n] <= target)
    {
        include = 1 + minCoinsMemo(n, target - coins[n], coins, memo);
    }
    memo[n][target] = min(include, exclude);
    return memo[n][target];
}
int minCoins(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int>(target + 1,  -1));
    return minCoinsMemo(n - 1, target, coins, memo);
}

// Tabulation
int minCoinsDp(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1,  0));
    for(int i = 0; i <= target; i++)
    {
        if(i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
        else{
            dp[0][i] = 1e9;
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            int include = 1e9;
            if(coins[i] <= j)
            {
                include = 1 + dp[i][j - coins[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = min(include, exclude);
        }
    }
    return dp[n - 1][target];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int target = 4;
    cout<<"Min coins: "<<minCoinsDp(coins, target);
}