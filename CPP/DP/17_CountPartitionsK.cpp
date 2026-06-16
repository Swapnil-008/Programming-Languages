#include<bits/stdc++.h>
using namespace std;

// Problem statement:
// Divide the given array into two partitions, and the union of two partitions must be an original array
// where s1 - s2 = D, D is the given parameter in function
// s1 must be greater than equal to s2
// Find the no. of different partitions possible

// Solution:
// Let totalSum = T
// Given: s1 - s2 = D
// Also:  s1 + s2 = T
// Adding both equations:
//     2*s1 = T + D   OR   2*s2 = T - D
// We choose to find subsets with sum:
//     s2 = (T - D) / 2
// So the problem reduces to:
// Count number of subsets having sum = s2.

int countPartitionsMemo(vector<int>& nums, int n, int target, vector<vector<int>>& memo)
{
    if(n == 0)
    {
        if(target == 0 && nums[0] == 0)
        {
            return 2;
        }
        if(target == 0 || nums[0] == target)
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
        include = countPartitionsMemo(nums, n - 1, target - nums[n], memo);
    }
    int exclude = countPartitionsMemo(nums, n - 1, target, memo);
    memo[n][target] = include + exclude;
    return memo[n][target];
}

int countPartitions(vector<int>& nums, int d)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if((totalSum - d) < 0 || (totalSum - d) % 2 != 0)
    {
        return 0;
    }
    int s2 = (totalSum - d) / 2;
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(s2 + 1, -1));
    return countPartitionsMemo(nums, n - 1, s2, memo);
}