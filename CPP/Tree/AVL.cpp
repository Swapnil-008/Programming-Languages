#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class AVL
{
    Node* root;
    public:
    AVL()
    {
        root = NULL;
    }
    Node* getRoot()
    {
        return root;
    }
    int height(Node* T);
    int balanceFactor(Node* T);
    void create();
    Node* insertRecursive(Node* root, int val);
    Node* rotateLeft(Node* T);
    Node* rotateRight(Node* T);
    Node* rotateLeftRight(Node* T);
    Node* rotateRightLeft(Node* T);
    void inorder(Node* root);
    void levelOrder();
};

void AVL::create()
{
    int val;
    cout<<"Keep entering the data: \n";
    while(true)
    {
        cin>>val;
        if(val == -1)
        {
            break;
        }
        root = insertRecursive(root, val);
    }
}

int AVL::height(Node* T)
{
    if(T == NULL)
    {
        return 0;
    }
    return 1 + max(height(T->left), height(T->right));
}

int AVL::balanceFactor(Node* T)
{
    int hl = height(T->left);
    int hr = height(T->right);
    return abs(hl - hr);
}

Node* AVL::insertRecursive(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }
    if(val < root->data)
    {
        root->left = insertRecursive(root->left, val);
        if(balanceFactor(root) == 2)
        {
            if(val < root->left->data)
            {
                root = rotateRight(root);
            }
            else{
                root = rotateLeftRight(root);
            }
        }
    }
    else if(val > root->data)
    {
        root->right = insertRecursive(root->right, val);
        if(balanceFactor(root) == 2)
        {
            if(val < root->right->data)
            {
                root = rotateRightLeft(root);
            }
            else{
                root = rotateLeft(root);
            }
        }
    }
    else{
        cout<<"\nDuplicate Element Found!\n";
    }
    return root;
}

void AVL::inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* AVL::rotateLeft(Node* root)
{
    Node* rightChild = root->right;
    root->right = rightChild->left;
    rightChild->left = root;
    return rightChild;
}

Node* AVL::rotateRight(Node* root)
{
    Node* leftChild = root->left;
    root->left = leftChild->right;
    leftChild->right = root;
    return leftChild;
}

Node* AVL::rotateLeftRight(Node* root)
{
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
    return root;
}

Node* AVL::rotateRightLeft(Node* root)
{
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
    return root;
}

int main()
{
    AVL avl;
    avl.create();
    // avl.inorder(avl.getRoot());
    avl.levelOrder();
    return 0;
}
