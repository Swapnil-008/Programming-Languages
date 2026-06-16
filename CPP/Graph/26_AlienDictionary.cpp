#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findEdge(string &str1, string &str2, vector<vector<int>>& adjNodes)
    {
        int len = min(str1.size(), str2.size());
        int i = 0;

        while(i < len && str1[i] == str2[i])
        {
            i++;
        }

        if(i < len)
        {
            int u = str1[i] - 'a';
            int v = str2[i] - 'a';

            // Avoid duplicate edges
            for(int x : adjNodes[u])
            {
                if(x == v)
                {
                    return true;
                }
            }
            adjNodes[u].push_back(v);
        }
        else
        {
            if(str1.size() > str2.size())
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findIndegree(vector<vector<int>>& adjNodes)
    {
        vector<int> indegree(26, 0);
        for(auto &adjNode: adjNodes)
        {
            for(int &adj: adjNode)
            {
                indegree[adj]++;
            }
        }
        return indegree;
    }

    string findOrder(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> adjNodes(26);
        vector<bool> exists(26, false);

        // Mark existing characters
        for(auto &word : words)
        {
            for(char ch : word)
            {
                exists[ch - 'a'] = true;
            }
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(!findEdge(words[i], words[i + 1], adjNodes))
            {
                return "";
            }
        }

        vector<int> indegree = findIndegree(adjNodes);
        queue<int> queue;

        for(int i = 0; i < 26; i++)
        {
            if(exists[i] && indegree[i] == 0)
            {
                queue.push(i);
            }
        }

        string result = "";
        while(!queue.empty())
        {
            int node = queue.front();
            queue.pop();
            result += ('a' + node);

            for(int &adjNode: adjNodes[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                {
                    queue.push(adjNode);
                }
            }
        }

        // Cycle check
        int count = 0;
        for(bool ch : exists)
        {
            if(ch == true)
            {
                count++;
            }
        }
        // If all existing characters are not visited -> cycle detected
        if(result.size() != count)
        {
            return "";
        }
        return result;
    }
};