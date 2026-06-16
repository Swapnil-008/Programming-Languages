#include<bits/stdc++.h>
using namespace std;

int canPartitionMemo(vector<int>& nums, int n, int target, vector<vector<int>>& memo)
{
    if(target == 0)
    {
        return 1;
    }
    if(n == 0)
    {
        return nums[0] == target;
    }
    if(memo[n][target] != -1)
    {
        return memo[n][target];
    }
    int exclude = canPartitionMemo(nums, n - 1, target, memo);
    int include = 0;
    if(nums[n] <= target)
    {
        include = canPartitionMemo(nums, n - 1, target - nums[n], memo);
    }
    memo[n][target] = include || exclude;
    return memo[n][target];
}

bool canPartition(vector<int>& nums)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if(totalSum % 2 != 0)
    {
        return false;
    }
    int target = totalSum / 2;
    vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    return canPartitionMemo(nums, n - 1, target, memo);
}