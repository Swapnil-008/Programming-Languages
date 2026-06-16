#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

class Solution{
    public:
    vector<int> topView(TreeNode *root)
    {
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        map<int, int> map;
        queue<pair<TreeNode*, int>> queue1, queue2;
        queue1.push({root, 0});
        while(!queue1.empty())
        {
            while(!queue1.empty())
            {
                auto itr = queue1.front();
                root = itr.first;
                int line = itr.second;
                queue1.pop();
                if(map.find(line) == map.end())
                {
                    map[line] = root->data;
                }
                if(root->left != NULL)
                {
                    queue2.push({root->left, line-1});
                }
                if(root->right != NULL)
                {
                    queue2.push({root->right, line+1});
                }
            }
            swap(queue1, queue2);
        }
        for(auto temp : map)
        {
            result.push_back(temp.second);
        }
        return result;
    }
};