#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(string input)
{
    int count = 0;
    int i = 0;
    while(input[i] != ']')
    {
        if(input[i] == ',')
        {
            count++;
        }
        i++;
    }
    int n = count + 1;
    vector<vector<int>> matrix(n, vector<int>(n));
    int row = 0, col = 0;
    i = 0;
    while (i < input.length())
    {
        if (input[i] == '[')
        {
            i++;
            int num = 0;
            bool found = false;
            while (i < input.length() && input[i] != ']')
            {
                if (isdigit(input[i]))
                {
                    num = num * 10 + (input[i] - '0');
                    found = true;
                }
                else if (input[i] == ',')
                {
                    if (found)
                    {
                        matrix[row][col] = num;
                        col++;
                        num = 0;
                        found = false;
                    }
                }
                i++;
            }
            if (found)
            {
                matrix[row][col] = num;
            }
            row++;
            col = 0;
        }
        i++;
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    vector<int> result;
    while(result.size() < (n * n))
    {
        for(int i = left; i <= right && result.size() < (n * n); i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom && result.size() < (n * n); i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        for(int i = right; i >= left && result.size() < (n * n); i--)
        {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;
        for(int i = bottom; i >= top && result.size() < (n * n); i--)
        {
            result.push_back(matrix[i][left]);
        }
        left++;
    }
    for(auto vect : matrix)
    {
        for(int num : vect)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return result;
}

int main()
{
    string input = "[5412,4,3,2,1],[1,2,3,4,5],[9,8,7,6,5],[4,4,4,4,4],[7,1,3,9,2]";
    auto result = spiralMatrix(input);
    for(auto num : result)
    {
        cout<<num<<" ";
    }
    return 0;
}