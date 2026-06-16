#include<iostream>
#include<stack>
using namespace std;

int postfixEvaluation(string postfix)
{
    int result;
    stack<int> stack;
    for(int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
        if(isdigit(ch))
        {
            stack.push(ch - '0');
        }
        else{
            int opr = stack.top();
            stack.pop();
            int opl = stack.top();
            stack.pop();
            switch(ch)
            {
                case '+': stack.push(opl + opr);
                break;
                case '-': stack.push(opl - opr);
                break;
                case '*': stack.push(opl * opr);
                break;
                case '/': stack.push(opl / opr);
                break;
            }
        }
    }
    if(!stack.empty())
    {
        result = stack.top();
        stack.pop();
        if(!stack.empty())
        {
            cout<<"Invalid Expression"<<endl;
            return -1;
        }
        return result;
    }
    cout<<"Invalid Expression"<<endl;
    return -1;
}

int main()
{
    string postfix = "53+82-*4/";
    int result = postfixEvaluation(postfix);
    cout<<"Postfix evaluation: "<<result<<endl;

    return 0;
}