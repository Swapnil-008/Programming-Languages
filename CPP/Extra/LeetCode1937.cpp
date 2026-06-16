#include <bits/stdc++.h>
using namespace std;

// Memoization
long long maxPoints(vector<vector<int>> &points)
{
    int m = points.size();
    int n = points[0].size();
    vector<vector<long long>> memo(m, vector<long long>(n, LLONG_MIN));
    long long maxi = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        long long mx = maxPointsMemo(points, m - 1, i, memo);
        maxi = max(maxi, mx);
    }
    return maxi;
}
long long maxPointsMemo(vector<vector<int>> &points, int m, int n, vector<vector<long long>> &memo)
{
    if (n < 0 || n >= points[0].size())
    {
        return LLONG_MIN;
    }
    if (m == 0)
    {
        return points[m][n];
    }
    if (memo[m][n] != LLONG_MIN)
    {
        return memo[m][n];
    }
    // Check ALL columns
    long long bestPrev = LLONG_MIN;
    for (int k = 0; k < points[0].size(); k++)
    {
        long long prev = maxPointsMemo(points, m - 1, k, memo);
        if (prev != LLONG_MIN)
        {
            bestPrev = max(bestPrev, prev - llabs(k - n));
        }
    }
    if (bestPrev == LLONG_MIN)
    {
        return memo[m][n] = LLONG_MIN;
    }
    return memo[m][n] = points[m][n] + bestPrev;
}

// Tabulation
long long maxPoints(vector<vector<int>> &points)
{
    int m = points.size();
    int n = points[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    long long maxi = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = points[0][i];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long bestPrev = LLONG_MIN;
            for (int k = 0; k < n; k++)
            {
                long long prev = dp[i - 1][k] - abs(k - j);
                bestPrev = max(bestPrev, prev);
            }
            dp[i][j] = bestPrev;
        }
    }
    for (int j = 0; j < n; j++)
    {
        maxi = max(maxi, dp[m - 1][j]);
    }
    return maxi;
}

// Optimized DP
long long maxPoints(vector<vector<int>> &points)
{
    int m = points.size();
    int n = points[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = points[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        vector<long long> left(n), right(n);
        // LEFT sweep
        left[0] = dp[i - 1][0];
        for (int j = 1; j < n; j++)
        {
            left[j] = max(left[j - 1] - 1, dp[i - 1][j]);
        }
        // RIGHT sweep
        right[n - 1] = dp[i - 1][n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            right[j] = max(right[j + 1] - 1, dp[i - 1][j]);
        }
        // build dp row
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = points[i][j] + max(left[j], right[j]);
        }
    }

    return *max_element(dp[m - 1].begin(), dp[m - 1].end());
}
