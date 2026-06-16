// #include<bits/stdc++.h>
// using namespace std;

// void targetSumMemo(int n, int target, int attempts, vector<int>& coins, vector<string>& result, string str)
// {
//     if(attempts == 0 && target == 0)
//     {
//         result.push_back(str);
//         return;
//     }
//     else if(target == 0 || attempts == 0)
//     {
//         return;
//     }
//     if(n < 0)
//     {
//         return;
//     }
//     // Pick
//     if(coins[n] <= target)
//     {
//         targetSumMemo(n, target - coins[n], attempts - 1, coins, result, str + to_string(coins[n]) + '-');
//     }
//     // Not Pick
//     targetSumMemo(n - 1, target, attempts, coins, result, str);
// }

// vector<string> targetSum(vector<int>& coins, int target, int attempts)
// {
//     int n = coins.size();
//     vector<string> result;
//     string str = "";
//     targetSumMemo(n - 1, target, attempts, coins, result, str);
//     for(string str: result)
//     {
//         cout<<str<<endl;
//     }
//     return result;
// }

// int main()
// {
//     vector<int> coins = {1, 2, 3};
//     int target = 7;
//     int attempts = 4;
//     targetSum(coins, target, attempts);
// }

#include <bits/stdc++.h>
using namespace std;

vector<string> targetSumMemo(int n, int target, int attempts, vector<int> &coins, map<pair<int, pair<int, int>>, vector<string>>& dp)
{
    if (attempts == 0 && target == 0)
    {
        return {""};
    }
    if (target == 0 || attempts == 0 || n < 0)
    {
        return {};
    }
    if (dp.count({n, {target, attempts}}))
    {
        return dp[{n, {target, attempts}}];
    }
    vector<string> result;
    // Pick
    if (coins[n] <= target)
    {
        vector<string> pick = targetSumMemo(n, target - coins[n], attempts - 1, coins, dp);
        for (string s : pick)
        {
            result.push_back(to_string(coins[n]) + "-" + s);
        }
    }
    // Not Pick
    vector<string> notPick = targetSumMemo(n - 1, target, attempts, coins, dp);
    for (string s : notPick)
    {
        result.push_back(s);
    }
    dp[{n, {target, attempts}}] = result;
    return dp[{n, {target, attempts}}];
}

vector<string> targetSum(vector<int> &coins, int target, int attempts)
{
    map<pair<int, pair<int, int>>, vector<string>> dp;
    return targetSumMemo(coins.size() - 1, target, attempts, coins, dp);
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int target = 7;
    int attempts = 4;
    vector<string> ans = targetSum(coins, target, attempts);
    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}
