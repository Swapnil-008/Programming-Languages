#include<bits/stdc++.h>
using namespace std;

// Subsequence: Maintaining the order of the string 
// A string having length n has 2^n total possible subsequences including the empty string 
// Doing comparisions based on characters

// Tabulation
// This approach is used when there is only one subsequence with maximum length, for multiple subsequences with maximum length we have to use brute force 
string printLCSDp(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    // We have used shiffting of index to avoid the negative indexing, so dp[i][j] represents LCS for str1 upto i - 1 and str2 uptp j - 1
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

    // int maxi = 0;
    // cout<<"Longest Common Subsequence: ";
    // Printing Longest Common Subsequence
    // for(int i = 0; i <= n1; i++)
    // {
    //     for(int j = 0; j <= n2; j++)
    //     {
    //         if(dp[i][j] > maxi)
    //         {
    //             maxi = dp[i][j];
    //             // cout<<str1[i - 1];
    //         }
    //     }
    // }
    // cout<<endl;
    
    // Optimize way to print the longest common subsequence
    string result = "";
    int i = n1;
    int j = n2;
    while(i > 0 && j > 0)
    {
        if(str1[i - 1] == str2[j - 1])
        {
            result.push_back(str1[i - 1]);
            i = i - 1;
            j = j - 1;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
        {
            i = i - 1;
        }
        else{
            j = j - 1;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string str1 = "abcde";
    string str2 = "bdgek";
    cout<<"Longest Common Subsequence: "<<printLCSDp(str1, str2);
    return 0;
}

string printLCS(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1));
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
            i = i - 1;
            j = j - 1;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
        {
            i = i - 1;
        }
        else{
            j = j - 1;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}