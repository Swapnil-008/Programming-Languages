#include <bits/stdc++.h>
using namespace std;

// We only need to check subset sums up to totalSum / 2.
//
// Reason:
// Let totalSum = S, and suppose a subset has sum = s1.
// Then the other subset has sum = s2 = S - s1.
// The absolute difference becomes:
//
//      |s1 - s2| = |s1 - (S - s1)| = |S - 2*s1|
//
// Notice that pairs (s1, s2) and (s2, s1) produce the same difference.
// For example, if S = 12:
//      s1 = 3, s2 = 9  → diff = 6
//      s1 = 9, s2 = 3  → diff = 6   (same result)
//
// So after S/2, the values just mirror each other.
// Therefore, it is enough to check subset sums only up to totalSum / 2.

int minAbsoluteDifferenceSubsetSum(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int target = totalSum / 2;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= target)
    {
        dp[0][nums[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            bool include = false;
            if (nums[i] <= j)
            {
                include = dp[i - 1][j - nums[i]];
            }
            bool exclude = dp[i - 1][j];
            dp[i][j] = include || exclude;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int minAbs = INT_MAX;
    for(int j = target; j >= 0; j--)
    {
        if(dp[n-1][j] == true)
        {
            int s1 = j;
            int s2 = totalSum - s1;
            minAbs = abs(s1 - s2);
            break;   // first found is minimum
        }
    }
    return minAbs;
}

int main()
{
    vector<vector<int>> testCases = {
        {1, 6, 11, 5},     // Expected: 1
        {1, 2, 3, 4},      // Expected: 0
        {5, 5, 5, 5},      // Expected: 0
        {7},               // Expected: 7
        {3, 1, 4, 2, 2}    // Expected: 0
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        for (int num : testCases[i])
        {
            cout << num << " ";
        }
        cout << endl;
        int result = minAbsoluteDifferenceSubsetSum(testCases[i]);
        cout << "Minimum Absolute Difference: " << result << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}