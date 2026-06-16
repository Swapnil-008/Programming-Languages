#include <bits/stdc++.h>
using namespace std;

// Memoization
int cherryPickupMemo(vector<vector<int>> &grid, int m, int n1, int n2, vector<vector<vector<int>>> &memo)
{
    if (n1 < 0 || n1 >= grid[0].size() || n2 < 0 || n2 >= grid[0].size())
    {
        return INT_MIN;
    }
    if (m == grid.size() - 1)
    {
        if (n1 == n2)
        {
            return grid[m][n1];
        }
        return grid[m][n1] + grid[m][n2];
    }
    if (memo[m][n1][n2] != -1)
    {
        return memo[m][n1][n2];
    }
    int maxi = INT_MIN;
    for (int dn1 = -1; dn1 <= 1; dn1++)
    {
        for (int dn2 = -1; dn2 <= 1; dn2++)
        {
            int prev = cherryPickupMemo(grid, m + 1, n1 + dn1, n2 + dn2, memo);
            maxi = max(maxi, prev);
        }
    }
    if (maxi == INT_MIN)
    {
        memo[m][n1][n2] = INT_MIN;
        return memo[m][n1][n2];
    }
    int curr = 0;
    if (n1 == n2)
    {
        curr = grid[m][n1];
    }
    else
    {
        curr = grid[m][n1] + grid[m][n2];
    }
    memo[m][n1][n2] = maxi + curr;
    return memo[m][n1][n2];
}
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return cherryPickupMemo(grid, 0, 0, n - 1, memo);
}

// Tabulation
int cherryPickupDp(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
            {
                dp[m - 1][j1][j2] = grid[m - 1][j1];
            }
            else
            {
                dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        int indj1 = j1 + dj1;
                        int indj2 = j2 + dj2;
                        if (indj1 >= 0 && indj1 < n && indj2 >= 0 && indj2 < n)
                        {
                            int val = dp[i + 1][indj1][indj2];
                            maxi = max(maxi, val);
                        }
                    }
                }
                int curr = 0;
                if (j1 == j2)
                {
                    curr = grid[m][j1];
                }
                else
                {
                    curr = grid[m][j1] + grid[m][j2];
                }
                dp[i][j1][j2] = maxi + curr;
            }
        }
    }
    return dp[0][0][n - 1];
}