#include<bits/stdc++.h>
using namespace std;

// Minimum insertion or deletion operations to convert string1 to string2

// Logic:
// To convert str1 into str2 using only insertion and deletion,
// we should preserve the characters that are common in both strings
// and only modify the characters that are different.

// The Longest Common Subsequence (LCS) represents the maximum number of characters that can remain unchanged in both strings.

// Characters not part of LCS must be:
    // - deleted from str1
    // - inserted into str1 to match str2

// Number of deletions required   = length of str1 - LCS
// Number of insertions required  = length of str2 - LCS

// Total minimum operations = deletions + insertions
//                          = (n1 - LCS) + (n2 - LCS)
//                          = (n1 + n2) - (2 * LCS)
int minOperations(string& str1, string& str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int maxLength = 0;
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
            maxLength = max(maxLength, dp[i][j]);
        }
    }
    return (n1 + n2) - (2 * maxLength);
}