#include<bits/stdc++.h>
using namespace std;

int calculateMinimumAdjustments(vector<int>& values)
{
    int n = values.size();
    int operations = values[n - 1];  // last element

    for(int i = n - 2; i >= 0; i--)
    {
        if(values[i] > values[i + 1])
        {
            operations += (values[i] - values[i + 1]);
        }
    }

    return operations;
}

int main()
{
    vector<int> temp = {3, 2, 1};
    cout<<calculateMinimumAdjustments(temp);
}