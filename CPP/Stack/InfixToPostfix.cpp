#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '*' || ch == '/')
    {
        return 2;
    }
    if(ch == '^')
    {
        return 3;
    }
    return 0;
}

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return true;
    }
    return false;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> stack;
    char stkop, expop;
    for(int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];
        if(ch == '(')
        {
            stack.push(ch);
        }
        else if(ch == ')')
        {
            while(!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            // For removing the open bracket
            if(!stack.empty())
            {
                stack.pop();
            }
        }
        else if(isOperator(ch))
        {
            expop = infix[i];
            while(!stack.empty())
            {
                stkop = stack.top();
                if(precedence(stkop) >= precedence(expop))
                {
                    postfix += stkop;
                    stack.pop();
                }
                else{
                    break;
                }
            }
            stack.push(expop);
        }
        else{
            postfix += ch;
        }
    }
    while(!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int main()
{
    string infix = "10-(2*3+(4-2)+8)";
    string postfix = infixToPostfix(infix);
    cout<<"Postfix Expression: "<<postfix<<endl;

    return 0;
}