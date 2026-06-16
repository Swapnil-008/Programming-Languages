#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<climits>
#include<unordered_map>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     string frequencySort(string s)
//     {
//         priority_queue<pair<int, char>> pqueue;
//         unordered_map<char, int> umap;
//         for(char &ch : s)
//         {
//             umap[ch]++;
//         }
//         for(auto &temp : umap)
//         {
//             pqueue.push({temp.second, temp.first});
//         }
//         string res = "";
//         while(!pqueue.empty())
//         {
//             auto temp = pqueue.top();
//             pqueue.pop();
//             res += string(temp.first, temp.second);    //concating the string having a char temp.first temp.second times
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
//     {
//         vector<vector<int>> result;
//         priority_queue<pair<int, pair<int, int>>> pqueue;
//         for(int i = 0; i < nums1.size(); i++)
//         {
//             for(int j = 0; j < nums2.size(); j++)
//             {
//                 int sum = nums1[i] + nums2[j];
//                 if(pqueue.size() < k)
//                 {
//                     pqueue.push({sum, {nums1[i], nums2[j]}});
//                 }
//                 else if(sum < pqueue.top().first)
//                 {
//                     pqueue.pop();
//                     pqueue.push({sum, {nums1[i], nums2[j]}});
//                 }
//                 else if(sum >= pqueue.top().first)
//                 {
//                     break;
//                 }
//             }
//         }
//         while(!pqueue.empty())
//         {
//             result.push_back({pqueue.top().second.first, pqueue.top().second.second});
//             pqueue.pop();
//             k--;
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     struct compare
//     {
//         bool operator()(pair<int, string>& a, pair<int, string>& b)
//         {
//             return a.first < b.first || (a.first == b.first && a.second > b.second);
//         }
//     };
//     vector<string> topKFrequent(vector<string>& words, int k)
//     {
//         unordered_map<string, int> umap;
//         for(string &word : words)
//         {
//             umap[word]++;
//         }
//         priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pqueue;
//         for(auto &temp : umap)
//         {
//             pqueue.push({temp.second, temp.first});
//         }
//         vector<string> result;
//         while(!pqueue.empty() && k > 0)
//         {
//             result.push_back(pqueue.top().second);
//             pqueue.pop();
//             k--;
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
//     {
//         priority_queue<pair<int, vector<int>>> pqueue;
//     }
// };

// class Solution {
// public:
//     vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k)
//     {
//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pqueue;
//         for(int i = 0; i < nums1.size(); i++)
//         {
//             for(int j = 0; j < nums2.size(); j++)
//             {
//                 int sum = nums1[i] + nums2[j];

//                 if(pqueue.size() < k)
//                 {
//                     pqueue.push({sum, {nums1[i], nums2[j]}});
//                 }
//                 else if(sum > pqueue.top().first)
//                 {
//                     pqueue.pop();
//                     pqueue.push({sum, {nums1[i], nums2[j]}});
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//         vector<int> result;
//         while(!pqueue.empty())
//         {
//             result.push_back(pqueue.top().first);
//             pqueue.pop();
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
//     {
//         unordered_map<string, priority_queue<string, vector<string>, greater<string>>> umap;
//         for(int i = 0; i < searchWord.length(); i++)
//         {
//             string compare = searchWorld.substr()
//         }
//     }
// };

// class Solution {
// public:
//     void findCombinations(int start, vector<int> candidates, int target, vector<int>& vect, vector<vector<int>> result)
//     {
//         if(target == 0)
//         {
//             result.push_back(vect);
//             return;
//         }
//         for(int i = start; i < candidates.size(); i++)
//         {
//             if(i > start && candidates[i] == candidates[i-1])
//             {
//                 continue;
//             }
//             vect.push_back(candidates[i]);
//             findCombinations(i+1, candidates, target-candidates[i], vect, result);
//             vect.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
//     {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> result;
//         vector<int> vect;
//         findCombinations(0, candidates, target, vect, result);
//         return result;
//     }
// };


// class Solution{   
// public:
//     bool isSubsetSum(vector<int>arr, int target)
//     {
//         int n = arr.size();
//         return subsetRecursive(arr, target, n);
//     }
//     bool subsetRecursive(vector<int> vect, int &target, int n)
//     {
//         if(target != 0 && n == 0)
//         {
//             return false;
//         }
//         if(target == 0)
//         {
//             return true;
//         }
//         if(vect[n-1] <= target)
//         {
//             target -= vect[n-1];
//             bool pi = subsetRecursive(vect, target, n-1);
//             bool pe = subsetRecursive(vect, target, n-1);
//             return pi || pe;
//         }
//         return subsetRecursive(vect, target, n-1);
//     }
// };

// class Solution {
// public:
//     void findSubsets(int index,vector<int> nums, vector<int>& vect, vector<vector<int>>& result)
//     {

//         set<vector<int>> set;
//         if(set.find(vect) == set.end())
//         {
//             result.push_back(vect);
//             set.insert(vect);
//         }
//         for(int i = index; i < nums.size(); i++)
//         {
//             if(i != index && nums[i] == nums[i-1])
//             {
//                 continue;
//             }
//             vect.push_back(nums[i]);
//             findSubsets(i+1, nums, vect, result);
//             vect.pop_back();
//         }
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> result;
//         vector<int> vect;
//         findSubsets(0, nums, vect, result);
//         return result;
//     }
// };


// class Solution {
// public:
//     int maxEvents(vector<vector<int>>& events)
//     {
//         sort(events.begin(), events.end());
//         vector<int> vect(events.back()[1], 0);
//         int count = 0;
//         for(int i = 0; i < events.size(); i++)
//         {
//             int start = events[i][0];
//             int end = events[i][1];
//             for(int j = start; j <= end; j++)
//             {
//                 if(vect[j] == 0)
//                 {
//                     vect[j] = 1;
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int maxEvents(vector<vector<int>>& events)
//     {
//         sort(events.begin(), events.end());
//         int maxDay = 0;
//         for (auto &event : events)
//         {
//             maxDay = max(maxDay, event[1]);
//         }
//         int n = events.size();
//         int j = 0;
//         int count = 0;
//         priority_queue<int, vector<int>, greater<int>> pqueue;
//         for(int i = 1; i <= maxDay; i++)
//         {
//             while(j < n && events[j][0] == i)
//             {
//                 pqueue.push(events[j][1]);
//                 j++;
//             }
//             while(!pqueue.empty() && pqueue.top() < i)
//             {
//                 pqueue.pop();
//             }
//             if(!pqueue.empty())
//             {
//                 pqueue.pop();
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
//     {
//         priority_queue<pair<double, pair<int, int>>> pqueue;
//         for(auto &cls: classes)
//         {
//             double ratio = (double)cls[0] / cls[1];
//             double  newRatio = (double) (cls[0] + 1) / (cls[1] + 1);
//             pqueue.push({newRatio - ratio, {cls[0], cls[1]}});
//         }
//         while(extraStudents > 0)
//         {
//             auto top = pqueue.top();
//             pqueue.pop();
//             int students = top.second.first;
//             int capacity = top.second.second;
//             double ratio = (double)students / capacity;
//             double newRatio = (double)(students + 1) / (capacity + 1);
//             pqueue.push({newRatio - ratio, {students + 1, capacity + 1}});
//             extraStudents--;
//         }
//         double sum = 0;
        
//         while(!pqueue.empty())
//         {
//             auto top = pqueue.top();
//             pqueue.pop();
//             sum += (double) top.second.second / top.second.first;
//         }
//         return sum / classes.size();
//     }
// };

// // class Solution {
// // public:
// //     string repeatLimitedString(string s, int repeatLimit)
// //     {
// //         unordered_map<char, int> umap;
// //         for(char &ch : s)
// //         {
// //             umap[ch]++;
// //         }
// //         priority_queue<pair<char, int>> pqueue;
// //         for(auto &temp : umap)
// //         {
// //             pqueue.push({temp.first, temp.second});
// //         }
// //         string result = "";
// //         while(!pqueue.empty())
// //         {
// //             auto [ch1, freq1] = pqueue.top();
// //             pqueue.pop();
// //             int count = freq1 >= repeatLimit ? repeatLimit : freq1;
// //             result += string(count, ch1);
// //             freq1 -= count;
// //             if(pqueue.empty())
// //             {
// //                 break;
// //             }
// //             auto [ch2, freq2] = pqueue.top();
// //             pqueue.pop();
// //             if(freq1 > 0)
// //             {
// //                 result += ch2;
// //                 freq2--;
// //                 pqueue.push({ch1, freq1});
// //                 pqueue.push({ch2, freq2});
// //             }
// //             else{
// //                 count = freq2 >= repeatLimit ? repeatLimit : freq2;
// //                 result += string(count, ch2);
// //                 freq2 -= count;
// //                 if(freq2 > 0)
// //                 pqueue.push({ch2, freq2});
// //             }
// //         }
// //         return result;
// //     }
// // };

// class Solution {
// public:
//     double myPow(double x, int n)
//     {
//         if(n == 0)
//         {
//             return 1;
//         }
//         return (double)myPow(x, (n > 0) ? n - 1 : n + 1) * (double)((n > 0) ? x : 1 / x);
//     }
// };


// vector<vector<int>> completeSubarrays(vector<int>& nums)
// {
//     vector<vector<int>> result;
//     for(int i = 0; i < nums.size(); i++)
//     {
//         vector<int> vect;
//         for(int j = i; j < nums.size(); j++)
//         {
//             vect.push_back(nums[j]);
//         }
//         result.push_back(vect);
//     }
//     return result;
// }

// int longestSubarray(vector<int>& nums, int k)
// {
//     int left = 0, right = 0, maxLen = 0;
//     int sum = 0;
//     while(right < nums.size())
//     {
//         sum += nums[right];
//         while(sum > k)
//         {
//             sum -= nums[left];
//             left++;
//         }
//         maxLen = max(maxLen, right - left + 1);
//         right++;
//     }
//     return maxLen;
// }

// //Maximum sum from including k characters from front or back (Ex. k = 4   you can take all the 4 elements from front or you can take 3 from front and 1 back and so on ...)
// int maximumSum(vector<int>& nums, int k)
// {
//     int leftSum = 0, rightSum = 0;
//     int maxSum = 0;
//     int right = nums.size()-1;
//     for(int i = 0; i < k; i++)
//     {
//         leftSum += nums[i];
//     }
//     maxSum = leftSum;
//     for(int i = k - 1; i >= 0; i--)
//     {
//         leftSum -= nums[i];
//         rightSum += nums[right];
//         right--;
//         maxSum = max(maxSum, leftSum + rightSum);
//     }
//     return maxSum;
// }

// class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k)
//     {
//         int left = 0, right = 0, maxLen = 0;
//         bool found = false;
//         while(right < nums.size())
//         {
//             k -= nums[right];
//             if(k == 0) found = true;
//             while(k < 0)
//             {
//                 k += nums[left];
//                 left++;
//             }
//             maxLen = max(maxLen, right - left + 1);
//             right++;
//         }
//         return found == true ? maxLen : 0;
//     }
// };


// class Solution {
// public:
//     int kDistinctChar(string& s, int k)
//     {
//         //your code goes here
//         int n = s.length();
//         int left = 0, right = 0;
//         int maxLen = 0;
//         unordered_map<char, int> umap;
//         while(right < n)
//         {
//             umap[s[right]]++;
//             while(umap.size() > k)
//             {
//                 umap[s[left]]--;
//                 if(umap[s[left]] == 0)
//                 {
//                     umap.erase(s[left]);
//                 }
//                 left++;
//             }
//             maxLen = max(maxLen, right - left + 1);
//             right++;
//         }
//         return maxLen;
//     }
// };

// class Solution {
// public:
//     int minOperations(vector<int>& nums)
//     {
//         int n = nums.size();
//         int operations = 0;
//         int remain = n;
//         for(int i = 0; i <= n - 3; i++)
//         {
//             if(nums[i] == 1)
//             {
//                 continue;
//             }
//             nums[i] = (nums[i] == 0) ? 1 : 0;
//             nums[i+1] = (nums[i+1] == 0) ? 1 : 0;
//             nums[i+2] = (nums[i+2] == 0) ? 1 : 0;
//         }
//     }
// };

// class Solution {
// public:
//     int minSwaps(vector<int>& nums)
//     {
//         vector<int> vect = nums;
//         int sum = 0;
//         for(int num : nums)
//         {
//             sum += num;
//             vect.push_back(num);
//         }
//         int n = vect.size();
//         int left = 0, right = 0;
//         int minSwaps = INT_MAX;
//         int count = 0;
//         while(right < n)
//         {
//             count += vect[right];
//             while(count == sum)
//             {
//                 count -= vect[left];
//                 left++;
//             }
//             if(count == sum - 1)
//             {
//                 minSwaps = min(minSwaps, right - left + 1 - sum);
//             }
//             right++;
//         }
//         return minSwaps;
//     }
// };

int binaryTwoDecimal(string str)
{
    int len = str.length()-1;
    int decimal = 0;
    int pow = 1;
    for(int i = len; i >= 0; i--)
    {
        if(str[i] == '1')
        {
            decimal += pow;
        }
        pow = pow << 1;
    }
    return decimal;
}

int setBits(int num)
{
    int count = 0;
    while(num > 0)
    {
        if(num & 1 == 1)
        {
            count++;
        }
        num = num >> 1;
    }
    return count;
}

bool isKthBitSet(int num, int k)
{
    if((num >> k) & 1)  // or  num & (1 << k)
    {
        return true;
    }
    return false;
}

int setKthBit(int num, int k)
{
    return (num | (1 << k));
}

int unsetKthBit(int num, int k)
{
    return (num & (~(1 << k)));
}

int toggleKthBit(int num, int k)
{
    return (num ^ (1 << k));
}
int main()
{
    // cout<<binaryTwoDecimal("1011")<<endl;
    // cout<<setBits(binaryTwoDecimal("1011"));
    // cout<<~(-4);
    // int num1 = 5;
    // int num2 = 10;
    // cout<<num1<<" "<<num2<<endl;
    // num1 = num1 ^ num2;
    // num2 = num1 ^ num2;
    // num1 = num1 ^ num2;
    // cout<<num1<<" "<<num2<<endl;
    cout<<isKthBitSet(13, 1)<<endl;
    cout<<setKthBit(13, 1)<<endl;
    cout<<(unsetKthBit(13, 3));
    return 0;
}

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr)
    {
        int n = arr.size();
        vector<int> vect(n);
        stack<int> stack;
        for(int i = n-1; i >= 0; i--)
        {
            while(!stack.empty() && stack.top() >= arr[i])
            {
                stack.pop();
            }
            if(stack.empty())
            {
                vect[i] = -1;
            }
            else{
                vect[i] = stack.top();
            }
            stack.push(arr[i]);
        }
        return vect;
    }
};


class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        int MOD = 1000000007;
        int n = points.size();
        unordered_map<int, set<int>> umap;
        for(int i = 0; i < n; i++)
        {
            umap[points[i][1]].insert(points[i][0]);
        }
        int ans = 0;
        int count = 0;
        for(auto& temp : umap)
        {
            count += temp.second.size();
        }
        for(auto &temp : umap)
        {
            int len = temp.second.size();
            int combinations = (factorial(len) / factorial(len-2)) / 2;
            ans += (combinations * (count - len)) % MOD;
        }
        return ans % MOD;
    }
    int factorial(int n)
    {
        vector<int> vect(n+1);
        vect[0] = 0;
        vect[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            vect[i] = vect[i-1] * i;
        }
        return vect[n];
    }
};

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root)
    {
        unordered_map<TreeNode*, int> umapCount;
        unordered_map<TreeNode*, bool> umapBST;
        countNodes(root, umapCount);
        return largestBST(root, umapCount, umapBST);
    }
    int largestBST(TreeNode* root, unordered_map<TreeNode*, int>& umapCount, unordered_map<TreeNode*, bool>& umapBST)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(isValidBST(root, umapBST))
        {
            return max(umapCount[root], max(largestBST(root->left, umapCount, umapBST), largestBST(root->right, umapCount, umapBST)));
        }
        return max(largestBST(root->left, umapCount, umapBST), largestBST(root->right, umapCount, umapBST));
    }
    int countNodes(TreeNode* root, unordered_map<TreeNode*, int>& umapCount)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(umapCount.find(root) != umapCount.end())
        {
            return umapCount[root];
        }
        int left = countNodes(root->left, umapCount);
        int right = countNodes(root->right, umapCount);
        int count = 1 + left + right;
        umapCount[root] = count;
        return count;
    }
    bool isValidBST(TreeNode* root, unordered_map<TreeNode*, bool>& umapBST)
    {
        if(root == NULL)
        {
            return true;
        }
        if(umapBST.find(root) != umapBST.end())
        {
            return umapBST[root];
        }
        if(root->left == NULL && root->right == NULL)
        {
            umapBST[root] = true;
            return true;
        }
        if(root->right == NULL)
        {
            if(findMax(root->left) >= root->val)
            {
                umapBST[root] = false;
                return false;
            }
        }
        if(root->left == NULL)
        {
            if(findMin(root->right) <= root->val)
            {
                umapBST[root] = false;
                return false;
            }
        }
        umapBST[root] = isValidBST(root->left, umapBST) && isValidBST(root->right, umapBST);
        return umapBST[root];
    }
    int findMin(TreeNode* root)
    {
        while(root->left != NULL)
        {
            root = root->left;
        }
        return root->val;
    }
    int findMax(TreeNode* root)
    {
        while(root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        stack<int> stack;
        vector<int> temp(2 * n);
        for(int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!stack.empty() && stack.top() <= nums[i])
            {
                stack.pop();
            }
            if(stack.empty())
            {
                temp[i] = -1;
            }
            else{
                temp[i] = stack.top();
            }
            stack.push(nums[i]);
        }
        vector<int> result = {temp.begin(), temp.begin() + n};
        return result;
    }
};
struct PairHash
{
    size_t operator()(const pair<int, int>& p) const {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int dir = 0; // 0=N, 1=E, 2=S, 3=W
        int x = 0, y = 0;
        unordered_map<pair<int, int>, int, PairHash> umap;
        for (auto &obstacle : obstacles)
        {
            umap[{obstacle[0], obstacle[1]}] = 1;
        }
        int maxDist = 0;
        for (int command : commands)
        {
            if (command == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if (command == -2)
            {
                dir = (dir + 3) % 4;
            }
            else {
                for (int i = 0; i < command; i++)
                {
                    int nx = x, ny = y;
                    if (dir == 0) ny++;
                    else if (dir == 1) nx++;
                    else if (dir == 2) ny--;
                    else nx--;
                    if (umap.find({nx, ny}) != umap.end())
                    {
                        break;
                    }
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};