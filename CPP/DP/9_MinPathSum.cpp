#include <bits/stdc++.h>
using namespace std;

// Memoization
int minPathSumMemo(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &memo)
{
    if (m < 0 || n < 0)
    {
        return INT_MAX;
    }
    if (m == 0 && n == 0)
    {
        return grid[m][n];
    }
    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }
    int left = minPathSumMemo(grid, m, n - 1, memo);
    int up = minPathSumMemo(grid, m - 1, n, memo);
    int best = min(left, up);
    if (best == INT_MAX)
    {
        return memo[m][n] = INT_MAX;
    }
    memo[m][n] = grid[m][n] + best;
    return memo[m][n];
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> memo(m, vector<int>(n, -1));
    return minPathSumMemo(grid, m - 1, n - 1, memo);
}

// Tabulation
int minPathSumDp(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0)
            {
                grid[i][j] += grid[i][j - 1];
            }
            else if (j == 0)
            {
                grid[i][j] += grid[i - 1][j];
            }
            else
            {
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }
    return grid[m - 1][n - 1];
}