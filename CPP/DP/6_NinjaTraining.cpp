#include <bits/stdc++.h>
using namespace std;

// There are three tasks which could ninja perform, but he can't perform the same task on two consecative days

// Forward declaration:
// int maximumPointsMemo(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &memo);

// Memoization
int maximumPoints(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<vector<int>> memo(n, vector<int>(3, -1));
    int num1 = maximumPointsMemo(mat, n - 1, 0, memo);
    int num2 = maximumPointsMemo(mat, n - 1, 1, memo);
    int num3 = maximumPointsMemo(mat, n - 1, 2, memo);
    return max(num1, max(num2, num3));
}

// i: denotes the day
// j: denotes the task is going to performed on the current day
// A function call states, maximum points earned from 0 to ith day, if jth task is performed on ith day
int maximumPointsMemo(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &memo)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return mat[i][j];
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    // Alternative
    int maxi = 0;
    for (int k = 0; k < 3; k++)
    {
        // Avoiding the task performed on ith day to being perform on i-1th day
        if (k != j)
        {
            int num = mat[i][j] + maximumPointsMemo(mat, i - 1, k, memo);
            maxi = max(maxi, num);
        }
    }
    memo[i][j] = maxi;
    return memo[i][j];
}

// Tabulation
// i: represents day
// j: represents last day training performed, 4th column denotes nothing performed on last day
// k: represents current day
// dp[day][last] = best score till this day, when last task = last
// previous day must have last = k

int maximumPointsDp(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(mat[0][1], mat[0][2]);
    dp[0][1] = max(mat[0][0], mat[0][2]);
    dp[0][2] = max(mat[0][0], mat[0][1]);
    dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int maxi = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    int num = mat[i][k] + dp[i - 1][k];
                    maxi = max(maxi, num);
                }
            }
            dp[i][j] = maxi;
        }
    }
    return dp[n - 1][3];
}