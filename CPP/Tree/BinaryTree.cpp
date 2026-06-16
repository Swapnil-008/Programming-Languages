#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    Node *root;
    public:
    Tree()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void create();
    Node* createRecursive();
    void preorderRecursive(Node* temp);
    void preorderIterative();
    void inorderRecursive(Node* temp);
    void inorderIterative();
    void postorderRecursive(Node* temp);
    void postorderIterative();
    int search(Node* temp, int target);
    int countAll(Node* temp);
    int countLeaf(Node* temp);
    int countOneChild(Node* temp);
    int countTwoChild(Node* temp);
    Node* findLeaf(Node* temp);
    void deleteNode();
    Node* deleteRecursive(Node *temp, int target, int &flag);
};


void Tree::create()
{
    cout<<"Enter data of root: ";
    root = createRecursive();
}

Node* Tree::createRecursive()
{
    int val;
    cin>>val;
    if(val == 0)
    {
        return NULL;
    }
    Node* newNode = new Node(val);
    cout<<"Enter left child of "<<val<<": ";
    newNode->left = createRecursive();
    cout<<"Enter right child of "<<val<<": ";
    newNode->right = createRecursive();
    return newNode;
}

void Tree::preorderRecursive(Node* temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<" ";
        preorderRecursive(temp->left);
        preorderRecursive(temp->right);
    }
}

void Tree::inorderRecursive(Node* temp)
{
    if(temp != NULL)
    {
        inorderRecursive(temp->left);
        cout<<temp->data<<" ";
        inorderRecursive(temp->right);
    }
}

void Tree::postorderRecursive(Node* temp)
{
    if(temp != NULL)
    {
        postorderRecursive(temp->left);
        postorderRecursive(temp->right);
        cout<<temp->data<<" ";
    }
}

void Tree::preorderIterative()
{
    stack<Node*> stack;
    Node* temp = root;
    while(temp != NULL || !stack.empty())
    {
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            stack.push(temp);
            temp = temp->left;
        }
        if(!stack.empty())
        {
            temp = stack.top();
            stack.pop();
            temp = temp->right;
        }
    }
}

void Tree::inorderIterative()
{
    stack<Node*> stack;
    Node* temp = root;
    while(temp != NULL || !stack.empty())
    {
        while(temp != NULL)
        {
            stack.push(temp);
            temp = temp->left;
        }
        if(!stack.empty())
        {
            temp = stack.top();
            stack.pop();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }
}

void Tree::postorderIterative()
{
    stack<Node*> stack1, stack2;
    Node* temp = root;
    stack1.push(temp);
    while(!stack1.empty())
    {
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
        if(temp->left != NULL)
        {
            stack1.push(temp->left);
        }
        if(temp->right != NULL)
        {
            stack1.push(temp->right);
        }
    }
    while(!stack2.empty())
    {
        cout<<stack2.top()->data<<" ";
        stack2.pop();
    }
}

int Tree::search(Node *temp, int target)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->data == target)
    {
        return 1;
    }
    int flag = search(temp->left, target);
    if(!flag)
    {
        return search(temp->right, target);
    }
}

int Tree::countAll(Node *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    int cl = countAll(temp->left);
    int cr = countAll(temp->right);
    return cl + cr + 1;
}

int Tree::countLeaf(Node *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->left == NULL && temp->right == NULL)
    {
        return 1;
    }
    return countLeaf(temp->left) + countLeaf(temp->right);
}

int Tree::countOneChild(Node *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->left == NULL && temp->right == NULL)
    {
        return 0;
    }
    if(temp->right == NULL)
    {
        return 1 + countOneChild(temp->left);
    }
    if(temp->left == NULL)
    {
        return 1 + countOneChild(temp->right);
    }
    return countOneChild(temp->left) + countOneChild(temp->right);
}

int Tree::countTwoChild(Node *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->left != NULL && temp->right != NULL)
    {
        return 1 + countTwoChild(temp->left) + countTwoChild(temp->right);
    }
    if(temp->right == NULL)
    {
        return countTwoChild(temp->left);
    }
    if(temp->left == NULL)
    {
        return countTwoChild(temp->right);
    }
}

Node* Tree::findLeaf(Node *temp)
{
    while(temp->left != NULL  || temp->right != NULL)
    {
        if(temp->left != NULL)
        {
            temp = temp->left;
        }
        else if(temp->right != NULL)
        {
            temp = temp->right;
        }
    }
    return temp;
}

void Tree::deleteNode()
{
    int val;
    cout<<"Enter data to delete: ";
    cin>>val;
    int flag = 0;
    root = deleteRecursive(root, val, flag);
    if(flag == 1)
    {
        cout<<"Element Deleted!"<<endl;
    }
    else{
        cout<<"Element Not Found!"<<endl;
    }
}

Node* Tree::deleteRecursive(Node* temp, int target, int &flag)
{
    if(temp == NULL)
    {
        return NULL;
    }
    if(temp->data == target)
    {
        flag = 1;
        Node *ptr;
        if(temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            return NULL;
        }
        if(temp->right == NULL)
        {
            ptr = temp->left;
            delete temp;
            return ptr;
        }
        if(temp->left == NULL)
        {
            ptr = temp->right;
            delete temp;
            return ptr;
        }
        ptr = findLeaf(temp->right);
        temp->data = ptr->data;
        int flag2 = 0;
        temp->right = deleteRecursive(temp->right, temp->data, flag2);
        return temp;
    }
    temp->left = deleteRecursive(temp->left, target, flag);
    if(flag == 0)
    {
        temp->right = deleteRecursive(temp->right, target, flag);
    }
    return temp;
}

int main()
{
    Tree tree;
    int choice;
    int val;

    do {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Preorder Recursive\n";
        cout << "3. Preorder Iterative\n";
        cout << "4. Inorder Recursive\n";
        cout << "5. Inorder Iterative\n";
        cout << "6. Postorder Recursive\n";
        cout << "7. Postorder Iterative\n";
        cout << "8. Search Element\n";
        cout << "9. Count All Nodes\n";
        cout << "10. Count Leaf Nodes\n";
        cout << "11. Count One Child Nodes\n";
        cout << "12. Count Two Children Nodes\n";
        cout << "13. Delete Node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.create();
            break;
        case 2:
            cout << "Preorder Recursive: ";
            tree.preorderRecursive(tree.getRoot());
            cout << endl;
            break;
        case 3:
            cout << "Preorder Iterative: ";
            tree.preorderIterative();
            cout << endl;
            break;
        case 4:
            cout << "Inorder Recursive: ";
            tree.inorderRecursive(tree.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "Inorder Iterative: ";
            tree.inorderIterative();
            cout << endl;
            break;
        case 6:
            cout << "Postorder Recursive: ";
            tree.postorderRecursive(tree.getRoot());
            cout << endl;
            break;
        case 7:
            cout << "Postorder Iterative: ";
            tree.postorderIterative();
            cout << endl;
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            if (tree.search(tree.getRoot(), val))
                cout << "Element found!\n";
            else
                cout << "Element not found!\n";
            break;
        case 9:
            cout << "Total nodes: " << tree.countAll(tree.getRoot()) << endl;
            break;
        case 10:
            cout << "Leaf nodes: " << tree.countLeaf(tree.getRoot()) << endl;
            break;
        case 11:
            cout << "One child nodes: " << tree.countOneChild(tree.getRoot()) << endl;
            break;
        case 12:
            cout << "Two children nodes: " << tree.countTwoChild(tree.getRoot()) << endl;
            break;
        case 13:
            tree.deleteNode();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}