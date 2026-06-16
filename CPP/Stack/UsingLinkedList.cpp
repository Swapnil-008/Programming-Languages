#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
    Node *top;
    public:
    Stack()
    {
        top = NULL;
    }
    int empty();
    void push(int value);
    int pop();
    int peek();
};

int Stack::empty()
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

void Stack::push(int value)
{
    Node *newNode = new Node(value);
    if(top == NULL)
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

int Stack::pop()
{
    if(top == NULL)
    {
        cout<<"Stack underflow!"<<endl;
        return -1;
    }
    int popped = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return popped;
}

int Stack::peek()
{
    if(top == NULL)
    {
        cout<<"Stack underflow!"<<endl;
        return -1;
    }
    return top->data;
}

int main()
{
    Stack s;
    int choice, value;

    do {
        cout << "\n===== Stack Menu =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if(value != -1)
                    cout << "Popped value: " << value << endl;
                break;
            case 3:
                value = s.peek();
                if(value != -1)
                    cout << "Top value: " << value << endl;
                break;
            case 4:
                if(s.empty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while(choice != 5);

    return 0;
}