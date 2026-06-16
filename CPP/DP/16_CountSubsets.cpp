#include<bits/stdc++.h>
using namespace std;

// if constraint is nums[i] >= 1 then the base condition would be
// if(target == 0)
// {
//     return 1;
// }
// if(n == 0)
// {
//     return nums[0] == target;
// }

int countSubsetsMemo(vector<int>& nums, int n, int target, vector<vector<int>>& memo)
{
    // Base condition: when nums[i] >= 0 (means nums[i] = 0 possible...)
    if(n == 0)
    {
        if(target == 0 && nums[0] == 0)
        {
            return 2;
        }
        if(target == 0 || target == nums[0])
        {
            return 1;
        }
        return 0;
    }
    if(memo[n][target] != -1)
    {
        return memo[n][target];
    }
    int include = 0;
    if(nums[n] <= target)
    {
        include = countSubsetsMemo(nums, n - 1, target - nums[n], memo);
    }
    int exclude = countSubsetsMemo(nums, n - 1, target, memo);
    memo[n][target] = include + exclude;
    return memo[n][target];
}
int countSubsets(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    return countSubsetsMemo(nums, n - 1, k, memo);
}

// Tabulation
int countSubsetsDp(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if(nums[0] <= k)
    {
        dp[0][nums[0]] = 1;
    }
    if(nums[0] == 0)
    {
        dp[0][0] = 2;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            int include = 0;
            if(nums[i] <= j)
            {
                include = dp[i - 1][j - nums[i]];
            }
            int exclude = dp[i - 1][j];
            dp[i][j] = include + exclude;
        }
    }
    return dp[n - 1][k];
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int k = 6;
    cout<<countSubsetsDp(nums, k);
}