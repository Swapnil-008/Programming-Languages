#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prefixEvaluation(string prefix)
{
    stack<int> stack;
    int result;
    for(int i = 0; i < prefix.size(); i++)
    {
        char ch = prefix[i];
        if(isdigit(ch))
        {
            stack.push(ch - '0');
        }
        else{
            int opl = stack.top();
            stack.pop();
            int opr = stack.top();
            stack.pop();
            switch(ch)
            {
                case '+':
                stack.push(opl + opr);
                break;
                case '-':
                stack.push(opl - opr);
                break;
                case '*':
                stack.push(opl * opr);
                break;
                case '/':
                stack.push(opl / opr);
                break;
            }
        } 
    }
    if(!stack.empty())
    {
        result = stack.top();
        stack.pop();
        if(stack.empty())
        {
            return result;
        }
        cout<<"Invalid expression"<<endl;
        return -1;
    }
    cout<<"Invalid expression"<<endl;
    return -1;
}

int main()
{
    string prefix = "-+2*364";
    reverse(prefix.begin(), prefix.end());
    cout << prefixEvaluation(prefix);

    return 0;
}