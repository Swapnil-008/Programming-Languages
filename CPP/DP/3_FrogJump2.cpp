#include<bits/stdc++.h>
using namespace std;

// This problem is the extended version of frog jump where frog can jump 1 to k steps 

int minCostKStepsMemo(vector<int>& height, int k, int n, vector<int>& memo)
{
    if(n == 0)
    {
        return 0;
    }
    if(memo[n] != -1)
    {
        return memo[n];
    }
    int minCost = INT_MAX;
    for(int i = 1; i <= k; i++)
    {
        if(n >= i)
        {
            int cost = minCostKStepsMemo(height, k, n - i, memo) + abs(height[n] - height[n - i]);
            minCost = min(minCost, cost);
        }
        else{
            break;
        }
    }
    memo[n] = minCost;
    return minCost;
}

int minCostKSteps(vector<int>& height, int k)
{
    int n = height.size();
    vector<int> memo(n, -1);
    return minCostKStepsMemo(height, k, n - 1, memo);
}