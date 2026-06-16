#include<bits/stdc++.h>
using namespace std;

// Time complexity: n * word.leggth() * 26

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> set;
        for(auto &word: wordList)
        {
            set.insert(word);
        }
        queue<pair<string, int>> queue;
        queue.push({beginWord, 1});
        set.erase(beginWord);
        while(!queue.empty())
        {
            string word = queue.front().first;
            int level = queue.front().second;
            if(word == endWord)
            {
                return level;
            }
            for(int i = 0; i < word.length(); i++)
            {
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch;
                    if(set.find(temp) != set.end())
                    {
                        queue.push({temp, level + 1});
                        set.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};