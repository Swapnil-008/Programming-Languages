#include <bits/stdc++.h>
using namespace std;

// Why greedy algorithm doesn't work here?
// - So greedy algorithm just think about the current position and not about future, so the path is selected on the basis of current step, but in future it could face loss more energy as compared to any other path
// - Ex. 30 10 60 10 60 50

// Basic Recursion
int minCostRecursive(vector<int>& height, int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return abs(height[1] - height[0]);
    }
    int stepOne = minCostRecursive(height, n - 1) + abs(height[n] - height[n - 1]);
    int stepTwo = minCostRecursive(height, n - 2) + abs(height[n] - height[n - 2]);
    return min(stepOne, stepTwo);
}
int minCost(vector<int> &height)
{
    int n = height.size();
    return minCostRecursive(height, n - 1);
}

// Memoization
int minCostMemoization(vector<int>& height, int n, vector<int>& memo)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return abs(height[1] - height[0]);
    }
    if(memo[n] != -1)
    {
        return memo[n];
    }
    int stepOne = abs(height[n] - height[n - 1]) + minCostMemoization(height, n - 1, memo);
    int stepTwo = abs(height[n] - height[n - 2]) + minCostMemoization(height, n - 2, memo);
    memo[n] = min(stepOne, stepTwo);
    return memo[n];
}

// Tabulation
int minCostDp(vector<int> &height)
{
    int n = height.size();
    vector<int> dp(n, 0);
    dp[1] = abs(height[1] - height[0]);
    for (int i = 2; i <= n; i++)
    {
        int stepOne = dp[i - 1] + abs(height[i] - height[i - 1]);
        int stepTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(stepOne, stepTwo);
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> height(n);
    cout<<"Keep entering height: \n";
    for(int i = 0; i < n; i++)
    {
        cin>>height[i];
    }
    cout<<minCostDp(height)<<endl;

    return 0;
}