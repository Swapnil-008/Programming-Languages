#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int ind = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind  = i;
                break;
            }
        }
        if(ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n - 1; i >= ind; i++)
        {
            if(nums[i] >= nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind, nums.end());
    }
};

class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < n; i++)
        {
            if(umap.find(nums[i]) == umap.end())
            {
                umap[nums[i]] = {i, -1, 1};
            }
            else{
                umap[nums[i]][1] = max(i, umap[nums[i]][1]);
                umap[nums[i]][2]++;
            }
        }
        int minDis = INT_MAX;
        for(auto &temp : umap)
        {
            if(temp.second[2] >= 3)
            {
                int num1 = temp.second[0];
                int num2 = temp.second[1];
                int dis = 2 * (num2 - num1);
                minDis = min(minDis, dis);
            }
        }
        return minDis;
    }
};