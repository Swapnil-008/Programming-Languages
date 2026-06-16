#include<bits/stdc++.h>
using namespace std;

// Memoization
// It states: Can we form "target" using elements from index [0 … ind]
bool subsetSumToKMemo(vector<int>& nums, int ind, int target, vector<vector<int>>& memo)
{
    if(target == 0)
    {
        return true;
    }
    if(ind == 0)
    {
        return target == nums[0];
    }
    if(memo[ind][target] != -1)
    {
        return memo[ind][target];
    }
    int include = false;
    if(nums[ind] <= target)
    {
        include = subsetSumToKMemo(nums, ind - 1, target - nums[ind], memo);
    }
    int exclude = subsetSumToKMemo(nums, ind - 1, target, memo);
    memo[ind][target] = include || exclude;
    return memo[ind][target];
}
bool subsetSumToK(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    return subsetSumToKMemo(nums, n-1, k, memo);
}

// Tabulation
// It states: Can we form sum j using FIRST i elements (0, ..i-1)
bool subsetSumToKDp(vector<int>& nums, int k)
{
    int n = nums.size();
    // dp[i][j] =
    // can we make sum j using the FIRST i elements (0..i-1)
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    // Base Case 1:
    // Sum 0 is always possible by taking no elements
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    // Base Case 2:
    // dp[0][j > 0] remains false automatically,
    // because with 0 elements we cannot form any positive sum
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            // Option 1: do not take current element
            bool exclude = dp[i - 1][j];
            // Option 2: take current element if allowed
            bool include = false;
            if(nums[i - 1] <= j)
            {
                include = dp[i - 1][j - nums[i - 1]];
            }
            dp[i][j] = include || exclude;
        }
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][k];
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int k = 6;
    cout<<subsetSumToKDp(nums, k);
    // int a = 10;
    // int *b = &a;
    // int **c;
    // c = &b;
    // cout<<a<<*b<<**c;
    // int i = 10;
    // int j = 20;
    // printf("%d\n");

    return 0;
}