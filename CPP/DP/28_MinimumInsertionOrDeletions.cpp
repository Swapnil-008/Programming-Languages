#include<bits/stdc++.h>
using namespace std;

// Minimum insertion or deletion operations to convert string into palindrome

// For finding the minimum inertion or deletion operations, we have to find the longest palindromic subsequence
// And if we observe the characters remained from longest palindromic subsequence, either we can add those characters at required places to make the string palindrome or we can remove those characters
// Either we can include those characters or remove those characters the no. of operations would be same, so the minimum operations will be (length of string - longest palindromic subsequence)

// Input: "abcaa"
// Output: 2
// Explanation:
    // Longest Palindromic Subsequence = "aba" (length = 3)
    // String length = 5
    // Minimum operations = 5 − 3 = 2

int minOperations(string& str1)
{
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    int n = str1.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int maxLength = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            maxLength = max(maxLength, dp[i][j]);
        }
    }
    return n - maxLength;
}