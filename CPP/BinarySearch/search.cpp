#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int low , int high, int target, vector<int>& nums)
{
    int mid = low + (high - low) / 2;    //more efficient than (low + high) / 2;
    if(low > high)
    {
        return false;
    }
    else if(nums[mid] == target)
    {
        return true;
    }
    else if(nums[mid] > target)
    {
        return binarySearch(low, mid - 1, target, nums);
    }
    else{
        return binarySearch(mid + 1, high, target, nums);
    }
}

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

    bool found = binarySearch(0, n-1, target, nums);

    if(found)
    {
        cout<<"Element found!"<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }

    return 0;
}