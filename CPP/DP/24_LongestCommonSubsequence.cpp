#include<bits/stdc++.h>
using namespace std;

// Subsequence: Maintaining the order of the string 
// A string having length n has 2^n total possible subsequences including the empty string 
// Doing comparisions based on characters

// Memoization
int longestCommonSubsequenceMemo(int n1, int n2, string str1, string str2, vector<vector<int>>& memo)
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
        int common = longestCommonSubsequenceMemo(n1 - 1, n2 - 1, str1, str2, memo);
        memo[n1][n2] = 1 + common;
    }
    else{
        int temp1 = longestCommonSubsequenceMemo(n1 - 1, n2, str1, str2, memo);
        int temp2 = longestCommonSubsequenceMemo(n1, n2 - 1, str1, str2, memo);
        memo[n1][n2] = max(temp1, temp2);
    }
    return memo[n1][n2];
}

int longestCommonSubsequence(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> memo(n1, vector<int>(n2, -1));
    int lcs = longestCommonSubsequenceMemo(n1 - 1, n2 - 1, str1, str2, memo);
    return lcs;
}

// Tabulation
int longestCommonSubsequenceDp(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    // We have used shifting of index to avoid the negative indexing, so dp[i][j] represents LCS for str1 upto i - 1 and str2 uptp j - 1
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for(int i = 0; i < n1; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i < n2; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n1;
    int j = n2;
    string result = "";
    while(i > 0 && j > 0)
    {
        if(str1[i - 1] == str2[j - 1])
        {
            result.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if(dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }
        else{
            i--;
        }
    }
    reverse(result.begin(), result.end());
    cout<<result<<endl;
    return dp[n1][n2];
}

int main()
{
    string str1 = "abcde";
    string str2 = "bdgek";
    cout<<longestCommonSubsequenceDp(str1, str2);
    return 0;
}