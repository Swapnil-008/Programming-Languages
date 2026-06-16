#include<bits/stdc++.h>
using namespace std;

// Fixed starting point multiple ending point

// Memoization
int minimumPathSumMemo(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& memo)
{
    if(j < 0 || j > i || i == triangle.size())
    {
        return INT_MAX;
    }
    if(i == triangle.size() - 1)
    {
        return triangle[i][j];
    }
    if(memo[i][j] != -1)
    {
        return memo[i][j];
    }
    int down = minimumPathSumMemo(triangle, i + 1, j, memo);
    int right = minimumPathSumMemo(triangle, i + 1, j + 1, memo);
    int best = min(down, right);
    if(best == INT_MAX)
    {
        return memo[i][j] = best;
    }
    memo[i][j] = triangle[i][j] + best;
    return memo[i][j];
}
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return minimumPathSumMemo(triangle, 0, 0, memo);
}

// Tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            int right = dp[i + 1][j + 1];
            int down = dp[i + 1][j];
            dp[i][j] = triangle[i][j] + min(right, down);
        }
    }
    return dp[0][0];
}