#include<iostream>
using namespace std;

#define MAX 5
class Stack
{
    int *data = new int[MAX];
    int top;
    public:
    Stack()
    {
        top = -1;
    }
    int empty();
    int full();
    void push(int val);
    int pop();
    int peek();
};

int Stack::empty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}

int Stack::full()
{
    if(top == MAX-1)
    {
        return 1;
    }
    return 0;
}

void Stack::push(int val)
{
    if(full())
    {
        cout<<"Stack overflow!"<<endl;
        return;
    }
    top++;
    data[top] = val;
}

int Stack::pop()
{
    if(empty())
    {
        cout<<"Stack is underflow!"<<endl;
        return -1;
    }
    int popped = data[top];
    top--;
    return popped;
}

int Stack::peek()
{
    if(empty())
    {
        cout<<"Stack is underflow!"<<endl;
        return -1;
    }
    return data[top];
}

int main()
{
    Stack s;
    int choice, val;

    do {
        cout << "\n===== Stack Menu =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                if(val != -1)
                    cout << "Popped value: " << val << endl;
                break;
            case 3:
                val = s.peek();
                if(val != -1)
                    cout << "Top value: " << val << endl;
                break;
            case 4:
                if(s.empty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 5:
                if(s.full())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while(choice != 6);

    return 0;
}