#include<bits/stdc++.h>
using namespace std;

// Gives memory limit exceeds error, but it is most efficient approach for interviews
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<vector<string>> queue;
        queue.push({beginWord});
        vector<vector<string>> result;
        while(!queue.empty())
        {
            int size = queue.size();
            vector<string> usedOnlevel;
            for(int i = 0; i < size; i++)
            {
                auto vect = queue.front();
                queue.pop();
                string word = vect.back();
                if(word == endWord)
                {
                    if(result.size() == 0)
                    {
                        result.push_back(vect);
                    }
                    else if(vect.size() == result[0].size())
                    {
                        result.push_back(vect);
                    }
                }
                for(int i = 0; i < word.size(); i++)
                {
                    char original = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;
                        if(set.find(word) != set.end())
                        {
                            vect.push_back(word);
                            queue.push(vect);
                            usedOnlevel.push_back(word);
                            vect.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }
            for(auto &temp: usedOnlevel)
            {
                set.erase(temp);
            }
        }
        return result;
    }
};