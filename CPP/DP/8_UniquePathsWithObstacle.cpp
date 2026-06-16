#include <bits/stdc++.h>
using namespace std;

// Memoization
int uniquePathsWithObstaclesMemo(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& memo)
{
    if(m == 0 && n == 0)
    {
        return grid[m][n] == 0 ? 1 : 0;
    }
    if(m < 0 || n < 0 || grid[m][n] == 1)
    {
        return 0;
    }
    if(memo[m][n] != -1)
    {
        return memo[m][n];
    }
    memo[m][n] = uniquePathsWithObstaclesMemo(grid, m - 1, n, memo) + uniquePathsWithObstaclesMemo(grid, m, n - 1, memo);
    return memo[m][n];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> memo(m, vector<int>(n, -1));
    return uniquePathsWithObstaclesMemo(obstacleGrid, m - 1, n - 1, memo);
}

// Tabulation
int uniquePathsWithObstaclesDp(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            break;
        }
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (obstacleGrid[0][j] == 1)
        {
            break;
        }
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] != 1)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}