#include<bits/stdc++.h>
using namespace std;

// Base condition: If we are on n-1th step then there is only one way, and from n-2th step there are 2 ways (1, 1) and (2)

// Basic Recursion
long long climbingStairs(long long n)
{
    if(n <= 2)
    {
        return n;
    }
    return climbingStairs(n - 1) + climbingStairs(n - 2);
}

// Memoization
long long climbingStairsMemo(vector<long long>& memo, long long n)
{
    if(n <= 2)
    {
        return n;
    }
    if(memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = climbingStairsMemo(memo, n - 1) + climbingStairsMemo(memo, n - 2);
    return memo[n];
}

// Tabulation
long long climbingStairsDp(long long n)
{
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(long long int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    long long int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<long long> memo(n + 1, -1);
    cout<<climbingStairsMemo(memo, n);

    return 0;
}