#include <bits/stdc++.h>
using namespace std;

// Key idea: if we can't pick two adjacent elements, includeing one we have to exclude other one

// Basic Recursion
int findMaxSumRecursive(vector<int> &arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    int include = arr[n] + findMaxSumRecursive(arr, n - 2);
    int exclude = findMaxSumRecursive(arr, n - 1);
    return max(include, exclude);
}
int findMaxSum(vector<int> &arr)
{
    int n = arr.size();
    return findMaxSumRecursive(arr, n - 1);
}

// Memoization
int findMaxSumMemo(vector<int> &arr, int n, vector<int> &memo)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    int include = arr[n] + findMaxSumMemo(arr, n - 2, memo);
    int exclude = findMaxSumMemo(arr, n - 1, memo);
    memo[n] = max(include, exclude);
    return memo[n];
}
int findMaxSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> memo(n, -1);
    return findMaxSumMemo(arr, n - 1, memo);
}

// Tabulation
int findMaxSumDp(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int include = arr[i];
        if (i > 1)
        {
            include += arr[i - 2];
        }
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "keep entering: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMaxSum(arr);

    return 0;
}