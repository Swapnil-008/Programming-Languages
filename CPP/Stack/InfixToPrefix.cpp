#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

// Step 1 : Reverse the given infix expression
// Step 2 : Exchange the brackets from '(' -> ')' and ')' -> '('
// Step 3 : Convert the expression into Postfix expression with one correction (stkop > expop) instead of (stkop >= expop)
// Step 4 : Reverse the expression

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

string infixToPrefix(string infix)
{
    string prefix = "";
    stack<char> stack;
    char expop, stkop;
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
                prefix += stack.top();
                stack.pop();
            }
            if(!stack.empty())
            {
                stack.pop();
            }
        }
        else if(isOperator(ch))
        {
            expop = ch;
            while(!stack.empty())
            {
                stkop = stack.top();
                if(precedence(stkop) > precedence(expop))
                {
                    prefix += stkop;
                    stack.pop();
                }
                else{
                    break;
                }
            }
            stack.push(expop);
        }
        else{
            prefix += ch;
        }
    }
    while(!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix = "(A+B)*(C-D)/E+F";
    reverse(infix.begin(), infix.end());
    for(char &ch : infix)
    {
        if(ch =='(')
        {
            ch = ')';
        }
        else if(ch == ')')
        {
            ch = '(';
        }
    }
    string prefix = infixToPrefix(infix);
    cout<<"Prefix Expression: "<<prefix<<endl;

    return 0;
}