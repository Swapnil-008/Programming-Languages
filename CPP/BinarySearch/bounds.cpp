#include<bits/stdc++.h>
using namespace std;

//Lower bound -> lowest index such that nums[ind] >= x
int lowerBound(vector<int>& nums, int low , int high, int target)
{
    int ans = nums.size();
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] >= target)
        {
            ans = min(ans, mid);                   // ans = mid -> can also work
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

//Upper bound -> smallest index such that nums[ind] > x
int upperBound(vector<int>& nums, int low, int high, int target)
{
    int ans = nums.size();
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] > target)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // int n;
    // cout<<"Enter number of elements: ";
    // cin>>n;

    // vector<int> nums(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cout<<"Enter element: ";
    //     cin>>nums[i];
    // }
    // sort(nums.begin(), nums.end());
    // for(int i = 0; i < n; i++)
    // {
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;
    // int target;
    // cout<<"Enter target element: ";
    // cin>>target;

    // int low = 0;
    // int high = n - 1;

    // int lower = lowerBound(nums, low, high, target);
    // // lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();   // Inbuilt function for finding the lower bound of any element returns the iterator not an index.
    // // similar for upper bound also.

    // if(lower != n)
    // {
    //     cout<<"The Lower Bound of "<<target<<" is "<<nums[lower]<<endl;
    // }
    // else{
    //     cout<<"The Lower Bound of "<<target<<" is not present!"<<endl;
    // }
    string str = "hit";
    string str2 = "hot";
    unordered_set<int> set;

    return 0;
}

class Solution{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V);
        queue<pair<int, int>> queue;
        queue.push({0, -1});
        while(!queue.empty())
        {
            int node = queue.front().first;
            int parent = queue.front().second;
            queue.pop();
            for(int adjNode: adj[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    queue.push({adjNode, node});
                }
                else if(adjNode != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V);
        for(int i = 0; i < V; i++)
        {
            if(!dfs(i, -1, visited, adj))
            {
                return true;
            }
        }
        return false;
    }
    bool dfs(int node, int parent, vector<int>& visited, vector<int>adj[])
    {
        visited[node] = 1;
        for(int i = 0; i < adj[node].size(); i++)
        {
            if(!visited[adj[node][i]])
            {
                return dfs(adj[node][i], node, visited, adj);
            }
            else if(parent != adj[node][i])
            {
                return false;
            }
        }
        return true;
    }
};