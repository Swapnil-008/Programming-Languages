#include <bits/stdc++.h>
using namespace std;

void decodeHelper(string &digits, int index, string current, vector<string> &result)
{
    if (index == digits.size())
    {
        result.push_back(current);
        return;
    }
    if (digits[index] != '0')
    {
        int num = digits[index] - '0';
        char ch = 'A' + num - 1;
        decodeHelper(digits, index + 1, current + ch, result);
    }
    if (index + 1 < digits.size())
    {
        int num = stoi(digits.substr(index, 2));
        if (num >= 10 && num <= 26)
        {
            char ch = 'A' + num - 1;
            decodeHelper(digits, index + 2, current + ch, result);
        }
    }
}

vector<string> decodeWays(string digits)
{
    vector<string> result;
    if (digits.empty())
        return result;
    decodeHelper(digits, 0, "", result);
    return result;
}

int main()
{
    string s = "226";
    vector<string> ans = decodeWays(s);
    cout << "All possible decodings:\n";
    for (auto &x : ans)
    {
        cout << x << "\n";
    }
    return 0;
}

