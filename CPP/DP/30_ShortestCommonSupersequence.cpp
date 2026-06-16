#include<bits/stdc++.h>
using namespace std;

// Shortest Common Supersequence (SCS):
// We need to construct the shortest string such that both given strings appear as subsequences of it.
// The common characters (LCS) should be included only once in the result.
// Length of SCS = |str1| + |str2| - LCS(str1, str2)
// Explanation:
// If we concatenate both strings, the length becomes |str1| + |str2|.
// However, the Longest Common Subsequence (LCS) gets counted twice.
// Since those common characters should appear only once in SCS,
// we subtract the LCS length once.

int LCSMemo(int n1, int n2, string& str1, string& str2, vector<vector<int>>& memo)
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
        memo[n1][n2] = 1 + LCSMemo(n1 - 1, n2 - 1, str1, str2, memo);
    }
    else{
        int takeFirst = LCSMemo(n1 - 1, n2, str1, str2, memo);
        int takeSecond = LCSMemo(n1, n2 - 1, str1, str2, memo);
        memo[n1][n2] = max(takeFirst, takeSecond);
    }
    return memo[n1][n2];
}

int shortestCommonSupersequence(string& str1, string& str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> memo(n1, vector<int>(n2, -1));
    int LCS = LCSMemo(n1 - 1, n2 - 1, str1, str2, memo);
    return n1 + n2 - LCS;
}

string shortestCommonSupersequenceDP(string& str1, string& str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    // Step 1: Build LCS DP table
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // Step 2: Backtrack from dp[n1][n2] to construct SCS
    // We move from bottom-right to top-left.
    // If characters match → take it once.
    // If not → move in direction of larger LCS value,
    // and include that character in result.
    int i = n1;
    int j = n2;
    string result = "";
    while(i > 0 && j > 0)
    {
        // If characters are same, include it once
        // (common part of both strings)
        if(str1[i - 1] == str2[j - 1])
        {
            result.push_back(str1[i - 1]);
            i--;
            j--;
        }
        // If value came from top cell
        // include character from str1
        else if(dp[i - 1][j] > dp[i][j - 1])
        {
            result.push_back(str1[i - 1]);
            i--;
        }
        // If value came from left cell
        // include character from str2
        else
        {
            result.push_back(str2[j - 1]);
            j--;
        }
    }
    // Step 3: Add remaining characters (if any string is not exhausted)
    while(i > 0)
    {
        result.push_back(str1[i - 1]);
        i--;
    }
    while(j > 0)
    {
        result.push_back(str2[j - 1]);
        j--;
    }
    // Since we built the string from back to front,
    // reverse it to get correct order.
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string str1 = "brute";
    string str2 = "groot";
    string SCS = shortestCommonSupersequenceDP(str1, str2);
    cout<<"Shortest common supersubsequence is '"<<SCS<<"' having length "<<SCS.length()<<endl;

    return 0;
}