#include <bits/stdc++.h>
using namespace std;

// Problem statement: We have to count all unique paths from 0,0 to m-1,n-1 in which we can only move left and down

// In memoization we are going from m-1, n-1 to 0,0 that's why we are going up and right
// Memoization
int uniquePaths(int m, int n)
{
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return uniquePathsMemo(m - 1, n - 1, memo);
}
int uniquePathsMemo(int i, int j, vector<vector<int>> &memo)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 || j == 0)
    {
        return 1;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    // memo[i][j] = up + left;
    memo[i][j] = uniquePathsMemo(i - 1, j, memo) + uniquePathsMemo(i, j - 1, memo);
    return memo[i][j];
}

// Tabulation:
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // Because there is only one way to reach 0, if i == 0 or j == 0
            if(i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else{
                // dp[i][j] = up + left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}