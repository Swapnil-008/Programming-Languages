#include <string>
#include <bits/stdc++.h>
#include <sstream>
#include<set>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parse(version1);
        vector<int> v2 = parse(version2);

        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int num1 = i < v1.size() ? v1[i] : 0;
            int num2 = i < v2.size() ? v2[i] : 0;
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }

private:
    vector<int> parse(const string& version) {
        vector<int> nums;
        stringstream ss(version);
        string temp;
        while (getline(ss, temp, '.'))
        {
            nums.push_back(stoi(temp));
        }
        return nums;
    }
};

vector<string> reverseParse(string& str)
{
    vector<string> result;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, ' '))
    {
        reverse(temp.begin(), temp.end());
        result.push_back(temp);
    }
    return result;
}


int main()
{
    string str = "Powerfull people come from powerfull places   ";
    vector<string> result = reverseParse(str);
    for(string &s: result)
    {
        cout<<s<<" ";
    }
    return 0;
}