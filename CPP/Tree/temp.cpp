#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void create();
    Node *createRecursive();
    void inorder(Node *temp);
    void preorder(Node *temp);
    void postorder(Node *temp);
    void inorder();
    void preorder();
    void postorder();
    void levelOrder();
    int searchRecursive(Node *temp, int val);
    int countAll(Node *temp);
    int countLeaf(Node *temp);
    int countOneChild(Node *temp);
    int countTwoChild(Node *temp);
    Node *findLeaf(Node *temp);
    void deleteNode();
    Node *deleteRecursive(Node *temp, int val, int &flag);
};

void BinaryTree::create()
{
    cout << "Enter data of root (0 for STOP): ";
    root = createRecursive();
}

Node *BinaryTree::createRecursive()
{
    int val;
    cin >> val;
    if (val == 0)
    {
        return NULL;
    }
    Node *newNode = new Node(val);
    cout << "Enter left child of " << val << " (0 for STOP): ";
    newNode->left = createRecursive();
    cout << "Enter right child of " << val << " (0 for STOP): ";
    newNode->right = createRecursive();
    return newNode;
}

void BinaryTree::inorder(Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}
void BinaryTree::preorder(Node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void BinaryTree::postorder(Node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

void BinaryTree::inorder()
{
    stack<Node *> stack;
    Node *temp = root;
    while (temp != NULL || !stack.empty())
    {
        while (temp != NULL)
        {
            stack.push(temp);
            temp = temp->left;
        }
        if (!stack.empty())
        {
            temp = stack.top();
            cout << temp->data << " ";
            stack.pop();
            temp = temp->right;
        }
    }
}

void BinaryTree::preorder()
{
    stack<Node *> stack;
    Node *temp = root;
    while (temp != NULL || !stack.empty())
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            stack.push(temp);
            temp = temp->left;
        }
        if (!stack.empty())
        {
            temp = stack.top();
            stack.pop();
            temp = temp->right;
        }
    }
}

void BinaryTree::postorder()
{
    stack<Node *> stack1, stack2;
    Node *temp = root;
    if (root == NULL)
    {
        return;
    }
    stack1.push(temp);
    while (!stack1.empty())
    {
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
        if (temp->left != NULL)
        {
            stack1.push(temp->left);
        }
        if (temp->right != NULL)
        {
            stack1.push(temp->right);
        }
    }
    while (!stack2.empty())
    {
        cout << stack2.top()->data << " ";
        stack2.pop();
    }
}

void BinaryTree::levelOrder()
{
    queue<Node *> q1, q2;
    Node *temp = root;
    q1.push(temp);
    while (!q1.empty())
    {
        while (!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q2.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q2.push(temp->right);
            }
        }
        cout << endl;
        swap(q1, q2);
    }
}

int BinaryTree::searchRecursive(Node *temp, int val)
{
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->data == val)
    {
        return 1;
    }
    return searchRecursive(temp->left, val) || searchRecursive(temp->right, val);
}

int BinaryTree::countAll(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    return countAll(temp->left) + countAll(temp->right) + 1;
}

int BinaryTree::countLeaf(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        return 1;
    }
    return countLeaf(temp->left) + countLeaf(temp->right);
}

int BinaryTree::countOneChild(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        return 0;
    }
    if (temp->right == NULL)
    {
        return 1 + countOneChild(temp->left);
    }
    if (temp->left == NULL)
    {
        return 1 + countOneChild(temp->right);
    }
    return countOneChild(temp->left) + countOneChild(temp->right);
}

int BinaryTree::countTwoChild(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        return 0;
    }
    if (temp->right == NULL)
    {
        return countTwoChild(temp->left);
    }
    if (temp->right == NULL)
    {
        return countTwoChild(temp->right);
    }
    return 1 + countTwoChild(temp->left) + countTwoChild(temp->right);
}

Node *BinaryTree::findLeaf(Node *temp)
{
    while (temp->left != NULL && temp->right != NULL)
    {
        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else if (temp->right != NULL)
        {
            temp = temp->right;
        }
    }
    return temp;
}

void BinaryTree::deleteNode()
{
    int val;
    cout << "Enter data to delete: ";
    cin >> val;
    int flag = 0;
    root = deleteRecursive(root, val, flag);
    if (flag == 1)
    {
        cout << "\nElement is deleted!";
    }
    else
    {
        cout << "\nElement is not present in the tree.";
    }
}

Node *BinaryTree::deleteRecursive(Node *temp, int val, int &flag)
{
    if (temp == NULL)
    {
        return NULL;
    }
    if (temp->data == val)
    {
        flag = 1;
        if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            return NULL;
        }
        if (temp->right == NULL)
        {
            Node *ptr = temp->left;
            delete temp;
            return ptr;
        }
        if (temp->left == NULL)
        {
            Node *ptr = temp->right;
            delete temp;
            return ptr;
        }
        Node *ptr = findLeaf(temp->right);
        temp->data = ptr->data;
        int flag2 = 0;
        temp->right = deleteRecursive(temp->right, ptr->data, flag2);
        return temp;
    }
    temp->left = deleteRecursive(temp->left, val, flag);
    if (flag == 0)
    {
        temp->right = deleteRecursive(temp->right, val, flag);
    }
    return temp;
}

class BST
{
    private:
        Node *root;
    public:
    BST()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    Node* createRecursive(Node *temp, int val);
    void createIterative();
    void insert(int val);
    int searchIterative(int val);
    int searchRecursive(Node *temp, int val);
    int height(Node *temp);
    int balancedTree(Node *temp);
    int findMin(Node *temp);
    int findMax(Node *temp);
    void deleteNode();
    Node *deleteRecursive(Node *temp, int val);
    void makeEmpty();
    Node *makeEmptyRecursive(Node *temp);
    void copyTree(BST tree);
    Node *copyTreeRecursive(Node *temp);
    bool validBST(Node *temp);
    bool childSum(Node *temp);
    void mirrorImage(Node *temp);
    void createTreeFromArray();
    Node *createTreeFromArrayRecursive(vector<int> &nums, int low, int high);
};

Node *BST::createRecursive(Node *temp, int val)
{
    if(temp == NULL)
    {
        temp = new Node(val);
        return temp;
    }
    if(val < temp->data)
    {
        temp->left = createRecursive(temp->left, val);
        return temp;
    }
    if(val > temp->data)
    {
        temp->right = createRecursive(temp->right, val);
        return temp;
    }
    else{
        cout << "Duplicate value not allowed in BST" << endl;
        return temp;
    }
}

void BST::createIterative()
{
    int val;
    cout<<"Keep entering data (0 to STOP): ";
    while(true)
    {
        cin>>val;
        if(val == 0)
        {
            break;
        }
        insert(val);
    }
}

void BST::insert(int val)
{
    Node *temp = root;
    if(root == NULL)
    {
        root = new Node(val);
        return;
    }
    Node *q;
    while(temp != NULL)
    {
        q = temp;
        if(val < temp->data)
        {
            temp = temp->left;
        }
        else if(val > temp->data)
        {
            temp = temp->right;
        }
        else{
            cout << "\nDuplicate value not allowed in BST" << endl;
            return;
        }
    }
    if(val < q->data)
    {
        q->left = new Node(val);
    }
    else{
        q->right = new Node(val);
    }
}

int BST::searchIterative(int val)
{
    Node *temp = root;
    while(temp != NULL)
    {
        if(val < temp->data)
        {
            temp = temp->left;
        }
        else if(val > temp->data)
        {
            temp = temp->right;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int BST::searchRecursive(Node *temp, int val)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->data == val)
    {
        return 1;
    }
    if(val < temp->data)
    {
        return searchRecursive(temp->left, val);
    }
    else{
        return searchRecursive(temp->right, val);
    }
}

int BST::height(Node *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    int hl = height(temp->left);
    int hr = height(temp->right);
    return 1 + max(hl, hr);
}

int BST::balancedTree(Node *temp)
{
    if(temp == NULL)
    {
        return true;
    }
    int hl = height(temp->left);
    int hr = height(temp->right);
    if(abs(hl - hr) > 1)
    {
        return false;
    }
    return balancedTree(temp->left) && balancedTree(temp->right);
}

void BST::makeEmpty()
{
    root = makeEmptyRecursive(root);
}

Node *BST::makeEmptyRecursive(Node *temp)
{
    if(temp == NULL)
    {
        return NULL;
    }
    temp->left = makeEmptyRecursive(temp->left);
    temp->right = makeEmptyRecursive(temp->right);
    delete temp;
    return NULL;
}

void BST::copyTree(BST tree)
{
    root = copyTreeRecursive(tree.getRoot());
}

Node *BST::copyTreeRecursive(Node *temp)
{
    if(temp == NULL)
    {
        return NULL;
    }
    Node *newNode = new Node(temp->data);
    newNode->left = copyTreeRecursive(temp->left);
    newNode->right = copyTreeRecursive(temp->right);
    return newNode;
}

bool BST::validBST(Node *temp)
{
    if(temp == NULL)
    {
        return true;
    }
    int leftMax = findMax(temp->left);
    int rightMin = findMin(temp->right);
    if(leftMax >= temp->data || rightMin <= temp->data)
    {
        return false;
    }
    return validBST(temp->left) && validBST(temp->right);
}

bool BST::childSum(Node *temp)
{
    if(temp == NULL)
    {
        return true;
    }
    int sum = 0;
    if(temp->left == NULL && temp->right == NULL)
    {
        return true;
    }
    if(temp->right == NULL)
    {
        sum += temp->left->data;
    }
    if(temp->left == NULL)
    {
        sum += temp->right->data;
    }
    if(temp->data != sum)
    {
        return false;
    }
    return childSum(temp->left) && childSum(temp->right);
}

void BST::mirrorImage(Node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    Node *ptr = temp->left;
    temp->left = temp->right;
    temp->right = ptr;
    mirrorImage(temp->left);
    mirrorImage(temp->right);
}

void BST::createTreeFromArray()
{
    vector<int> nums = {2, 4, 8, 15, 20, 20, 25};
    root = createTreeFromArrayRecursive(nums, 0, nums.size()-1);
}

Node *BST::createTreeFromArrayRecursive(vector<int>& nums, int low, int high)
{
    if(low > high)
    {
        return NULL;
    }
    int mid = (low + high) / 2;
    Node *newNode = new Node(nums[mid]);
    newNode->left = createTreeFromArrayRecursive(nums, low, mid-1);
    newNode->right = createTreeFromArrayRecursive(nums, mid+1, high);
    return newNode;
}

int BST::findMin(Node *temp)
{
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int BST::findMax(Node *temp)
{
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

void BST::deleteNode()
{
    int val;
    cout<<"Enter data to be deleted: ";
    cin>>val;
    root = deleteRecursive(root, val);
}

Node *BST::deleteRecursive(Node *temp, int val)
{
    if(temp == NULL)
    {
        cout<<"\nElement Not found!";
        return NULL;
    }
    if(val < temp->data)
    {
        temp->left = deleteRecursive(temp->left, val);
    }
    else if(val > temp->data)
    {
        temp->right = deleteRecursive(temp->right, val);
    }
    else{
        Node *ptr;
        if(temp->left == NULL && temp->right == NULL)
        {
            delete temp;
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
        temp->data = findMin(temp->right);
        temp->right = deleteRecursive(temp->right, temp->data);
        cout<<"\nElement deleted!";
        return temp;
    }
}

int main()
{
    BinaryTree btree;
    int choice, val;

    do
    {
        cout << "\n============ Binary Tree Menu ============\n";
        cout << "1. Create Tree\n";
        cout << "2. Inorder Traversal (Recursive)\n";
        cout << "3. Preorder Traversal (Recursive)\n";
        cout << "4. Postorder Traversal (Recursive)\n";
        cout << "5. Inorder Traversal (Iterative)\n";
        cout << "6. Preorder Traversal (Iterative)\n";
        cout << "7. Postorder Traversal (Iterative)\n";
        cout << "8. Level Order Traversal\n";
        cout << "9. Search Element\n";
        cout << "10. Count All Nodes\n";
        cout << "11. Count Leaf Nodes\n";
        cout << "12. Count Nodes with One Child\n";
        cout << "13. Count Nodes with Two Children\n";
        cout << "14. Delete Node\n";
        cout << "15. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            btree.create();
            break;
        case 2:
            cout << "Inorder Traversal (Recursive): ";
            btree.inorder(btree.getRoot());
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal (Recursive): ";
            btree.preorder(btree.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal (Recursive): ";
            btree.postorder(btree.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "Inorder Traversal (Iterative): ";
            btree.inorder();
            cout << endl;
            break;
        case 6:
            cout << "Preorder Traversal (Iterative): ";
            btree.preorder();
            cout << endl;
            break;
        case 7:
            cout << "Postorder Traversal (Iterative): ";
            btree.postorder();
            cout << endl;
            break;
        case 8:
            cout << "Level Order Traversal: \n";
            btree.levelOrder();
            cout << endl;
            break;
        case 9:
            cout << "Enter element to search: ";
            cin >> val;
            if (btree.searchRecursive(btree.getRoot(), val))
                cout << "Element found!" << endl;
            else
                cout << "Element not found!" << endl;
            break;
        case 10:
            cout << "Total nodes: " << btree.countAll(btree.getRoot()) << endl;
            break;
        case 11:
            cout << "Total leaf nodes: " << btree.countLeaf(btree.getRoot()) << endl;
            break;
        case 12:
            cout << "Total nodes with one child: " << btree.countOneChild(btree.getRoot()) << endl;
            break;
        case 13:
            cout << "Total nodes with two children: " << btree.countTwoChild(btree.getRoot()) << endl;
            break;
        case 14:
            btree.deleteNode();
            break;
        case 15:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 15);

    return 0;
}