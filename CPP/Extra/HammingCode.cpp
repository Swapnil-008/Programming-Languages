#include<bits/stdc++.h>
using namespace std;

void hammingCode(string &input)
{
    int m = input.size();
    int r = 0;
    while(true)
    {
        if(pow(2, r) >= (m + r + 1))
        {
            break;
        }
        r++;
    }
    vector<string> bits(m + r + 1);
    int temp = 0;
    int ind = m - 1;
    for(int i = 1; i < bits.size(); i++)
    {
        if(i == pow(2, temp))
        {
            bits[i] = "r" + to_string(temp + 1);
            temp++;
        }
        else{
            bits[i] = input[ind];
            ind--;
        }
    }
    vector<int> parityBits(r + 1);
    parityBits[1] = stoi(bits[3]);
    for(int i = 4; i < bits.size(); i++)
    {
        try {
            int val = stoi(bits[i]);
            if (i % 2 != 0)
            {
                parityBits[1] ^= val;
            }
        } catch (invalid_argument &e){}
    }
}

int main()
{
    string input = "1001101";
    hammingCode(input);

    return 0;
}