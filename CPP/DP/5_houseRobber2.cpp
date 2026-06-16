#include <bits/stdc++.h>
using namespace std;

// Memoization
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    vector<int> memo(n, -1);
    // included last one, that's why we can't include first one
    int num1 = robMemo(nums, n - 1, 1, memo);
    memo.clear();
    memo.resize(n, -1);
    // excluded last one, that's why we can include first one
    int num2 = robMemo(nums, n - 2, 0, memo);
    return max(num1, num2);
}
int robMemo(vector<int> &nums, int n, int end, vector<int> &memo)
{
    if (n < end)
    {
        return 0;
    }
    if (n == end)
    {
        return nums[n];
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    int include = nums[n] + robMemo(nums, n - 2, end, memo);
    int exclude = robMemo(nums, n - 1, end, memo);
    memo[n] = max(include, exclude);
    return memo[n];
}