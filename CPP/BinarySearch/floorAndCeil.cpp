#include<bits/stdc++.h>
using namespace std;

// Floor -> largest element in the array <= target
int floor(vector<int>& nums, int low , int high, int target)
{
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] <= target)
        {
            ans = max(ans, mid);         // ans = mid -> can also work
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

// Ceil -> smallest element in the array >= target (equivalent to lower bound)
int ceil(vector<int>& nums, int low , int high, int target)
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

// Unique elements.
// Steps:
//  1.Apply the binary search
//  2.Find the sorted half
//  3.Eliminate the unwanted part by adjusting the low and high

int searchRotatedArray(vector<int>& nums, int target)
{
    int n = nums.size();
    int ind = -1;
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        if(nums[low] <= nums[mid])
        {
            //left sorted half
            if(nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(nums[mid] <= nums[high])
        {
            //right sorted half
            if(nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return ind;
}

bool searchRotatedArray2(vector<int>& nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target)
        {
            return true;
        }
        if(nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(nums[low] <= nums[mid])
        {
            //left sorted half
            if(nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(nums[mid] <= nums[high])
        {
            //right sorted half
            if(nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return false;
}

// Duplicate elemets.

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter element: ";
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"Enter target element: ";
    cin>>target;

    int low = 0;
    int high = n - 1;

    int fl = floor(nums, low, high, target);
    if(fl != -1)
    {
        cout<<"The Floor of "<<target<<" is "<<nums[fl]<<" present at "<<fl<<endl;
    }
    else{
        cout<<"The Floor of "<<target<<" is not present!"<<endl;
    }

    int cl = ceil(nums, low, high, target);
    if(cl != -1)
    {
        cout<<"The Ceil of "<<target<<" is "<<nums[cl]<<" present at "<<cl<<endl;
    }
    else{
        cout<<"The Ceil of "<<target<<" is not present!"<<endl;
    }
    return 0;
}

// Steps:
//  1. Find the which is sorted
//  2.  i). If the left half is sorted then take the lowest element and now there is no need of this half so update the low to mid+1 (to eliminate the lower half from searching)
//     ii). If the right half is sorted then take the mid element and now there is no need of this half so update the high to mid - 1 (to eliminate the upper half from searching)

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid])
            {
                // sorted left half
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else{
                // sorted right half
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};