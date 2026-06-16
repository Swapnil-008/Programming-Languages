#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode* left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// class Solution{
//     public:
//     vector<int> bottomView(TreeNode *root)
//     {
//         vector<int> result;
//         if(root == NULL)
//         {
//             return result;
//         }
//         map<int, int> map;
//         queue<pair<TreeNode*, int>> queue1, queue2;
//         queue1.push({root, 0});
//         while(!queue1.empty())
//         {
//             while(!queue1.empty())
//             {
//                 auto itr = queue1.front();
//                 root = itr.first;
//                 int line = itr.second;
//                 queue1.pop();
//                 map[line] = root->data;
//                 if(root->left != NULL)
//                 {
//                     queue2.push({root->left, line-1});
//                 }
//                 if(root->right != NULL)
//                 {
//                     queue2.push({root->right, line+1});
//                 }
//             }
//             swap(queue1, queue2);
//         }
//         for(auto temp : map)
//         {
//             result.push_back(temp.second);
//         }
//         return result;
//     }
// };



class Solution {
public:
    vector<int> boundary(TreeNode* root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }

        if (!isLeaf(root))
        {
            res.push_back(root->data);
        }
        addLeftBoundary(root->left, res);
        addLeaves(root, res);
        addRightBoundary(root->right, res);

        return res;
    }

    bool isLeaf(TreeNode* root)
    {
        return root && !root->left && !root->right;
    }
    void addLeftBoundary(TreeNode* root, vector<int>& res)
    {
        while (root != NULL)
        {
            if (!isLeaf(root))
            {
                res.push_back(root->data);
            }
            else{
                return;
            }
            if (root->left)
            {
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
    }

    void addRightBoundary(TreeNode* root, vector<int>& res)
    {
        vector<int> temp;
        while (root != NULL)
        {
            if (!isLeaf(root))
            {
                temp.push_back(root->data);
            }
            else{
                return;
            }
            if (root->right)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
    }

    void addLeaves(TreeNode* root, vector<int>& res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
        {
            addLeaves(root->left, res);
        }
        if (root->right)
        {
            addLeaves(root->right, res);
        }
    }
};
