#include <bits/stdc++.h>
using namespace std;

// Since it is consicative, current result shouldn't depend on previous results

// Memoization is slight complex, so mostly prefer Tabulation
int longestCommonSubstringMemoUtil(int i, int j, string &str1, string &str2, vector<vector<int>> &memo, int &maxi, int &endIndex)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    longestCommonSubstringMemoUtil(i - 1, j, str1, str2, memo, maxi, endIndex);
    longestCommonSubstringMemoUtil(i, j - 1, str1, str2, memo, maxi, endIndex);
    if (str1[i] == str2[j])
    {
        memo[i][j] = 1 + longestCommonSubstringMemoUtil(i - 1, j - 1, str1, str2, memo, maxi, endIndex);
        if (memo[i][j] > maxi)
        {
            maxi = memo[i][j];
            endIndex = i;
        }
    }
    else
    {
        memo[i][j] = 0;
    }
    return memo[i][j];
}

int longestCommonSubstringMemo(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> memo(n1, vector<int>(n2, -1));
    int maxi = 0;
    int endIndex = -1;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            longestCommonSubstringMemoUtil(i, j, str1, str2, memo, maxi, endIndex);
        }
    }
    if (endIndex != -1)
    {
        cout << str1.substr(endIndex - maxi + 1, maxi) << endl;
    }
    return maxi;
}

// Tabulation
int longestCommonSubstringDp(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int maxi = 0;
    int endIndex = -1;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxi)
                {
                    maxi = dp[i][j];
                    endIndex = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    // Print longest common substring
    if (endIndex != -1)
    {
        cout << str1.substr(endIndex - maxi, maxi) << endl;
    }
    // For analyzing the DP
    for(int i = 0; i <= n1; i++)
    {
        for(int j = 0; j <= n2; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxi;
}

int main()
{
    string str1 = "abcxyzdefghijklmnop";
    string str2 = "xyzdefghabc";
    cout << longestCommonSubstringDp(str1, str2);

    return 0;
}