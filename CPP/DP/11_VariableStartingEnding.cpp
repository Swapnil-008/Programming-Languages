#include<bits/stdc++.h>
using namespace std;

// Variable starting point and variable ending point
// Greedy is not applicable on absence of uniformity

// Memoization
int getMaxPathSumMemo(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& memo)
{
    if(n < 0 || n >= grid[0].size())
    {
        return INT_MIN;
    }
    if(m == 0)
    {
        return grid[0][n];
    }
    if(memo[m][n] != -1)
    {
        return memo[m][n];
    }
    int up = getMaxPathSumMemo(grid, m - 1, n, memo);
    int leftDiagonal = getMaxPathSumMemo(grid, m - 1, n - 1, memo);
    int rightDiagonal = getMaxPathSumMemo(grid, m - 1, n + 1, memo);
    int maxi = max(up, max(leftDiagonal, rightDiagonal));
    if(maxi == INT_MIN)
    {
        return memo[m][n] = INT_MIN;
    }
    memo[m][n] = grid[m][n] + maxi;
    return memo[m][n];
}
int getMaxPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int mx = getMaxPathSumMemo(grid, m - 1, i, memo);
        maxi = max(maxi, mx);
    }
    return maxi;
}

// Tabulation
int getMaxPathSumDp(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        dp[0][i] = grid[0][i];
    }
    int maxi = INT_MIN;
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int up = dp[i - 1][j];
            int leftDiagonal = INT_MIN;
            if(j > 0)
            {
                leftDiagonal = dp[i - 1][j - 1];
            }
            int rightDiagonal = INT_MIN;
            if(j < n - 1)
            {
                rightDiagonal = dp[i - 1][j + 1];
            }
            maxi= max(up, max(leftDiagonal, rightDiagonal));
            if(maxi == INT_MIN)
            {
                dp[i][j] = INT_MIN;
            }
            else{
                dp[i][j] = grid[i][j] + maxi;
            }
        }
    }
    maxi = INT_MIN;
    for(int j = 0; j < n ; j++)
    {
        maxi = max(maxi, dp[m - 1][j]);
    }
    return maxi;
}