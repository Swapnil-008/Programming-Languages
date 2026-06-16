#include<bits/stdc++.h>
using namespace std;

// Memoization
int longestPalindromicSubsequenceMemo(int n1, int n2, string& str1, string& str2, vector<vector<int>>& memo)
{
    if(n1 < 0 || n2 < 0)
    {
        return 0;
    }
    if(memo[n1][n2] != -1)
    {
        return memo[n1][n2];
    }
    if(str1[n1] == str2[n2])
    {
        memo[n1][n2] = 1 + longestPalindromicSubsequenceMemo(n1 - 1, n2 - 1, str1, str2, memo);
    }
    else{
        int firstExclude = longestPalindromicSubsequenceMemo(n1 - 1, n2, str1, str2, memo);
        int secondExclude = longestPalindromicSubsequenceMemo(n1, n2 - 1, str1, str2, memo);
        memo[n1][n2] = max(firstExclude, secondExclude);
    }
    return memo[n1][n2];
}
int longestPalindromicSubsequence(string& str)
{
    string str2 = str;
    reverse(str2.begin(), str2.end());
    int n = str.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return longestPalindromicSubsequenceMemo(n - 1, n - 1, str, str2, memo);
}

// Tabulation
int longestPalindromicSubsequenceDp(string& str)
{
    string str2 = str;
    reverse(str2.begin(), str2.end());
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(str[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}