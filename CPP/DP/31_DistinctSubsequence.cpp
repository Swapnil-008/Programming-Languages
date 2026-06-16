#include <bits/stdc++.h>
using namespace std;

int distinctSubsequencesMemo(int n1, int n2, string &str1, string &str2, vector<vector<int>> &memo)
{
    if (n2 < 0)
    {
        return 1;
    }
    if (n1 < 0)
    {
        return 0;
    }
    if (memo[n1][n2] != -1)
    {
        return memo[n1][n2];
    }
    if (str1[n1] == str2[n2])
    {
        int take = distinctSubsequencesMemo(n1 - 1, n2 - 1, str1, str2, memo);
        int skip = distinctSubsequencesMemo(n1 - 1, n2, str1, str2, memo);
        memo[n1][n2] = take + skip;
    }
    else
    {
        memo[n1][n2] = distinctSubsequencesMemo(n1 - 1, n2, str1, str2, memo);
    }
    return memo[n1][n2];
}

int distinctSubsequences(string &str1, string &str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> memo(n1, vector<int>(n2, -1));
    return distinctSubsequencesMemo(n1 - 1, n2 - 1, str1, str2, memo);
}

int distinctSubsequencesMemo(string &s, string &t)
{
    int n1 = s.length();
    int n2 = t.length();
    vector<vector<long long>> dp(n1 + 1, vector<long long>(n2 + 1, 0));
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                if (dp[i - 1][j] > LLONG_MAX - dp[i - 1][j - 1])
                {
                    dp[i][j] = LLONG_MAX;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n1][n2];
}