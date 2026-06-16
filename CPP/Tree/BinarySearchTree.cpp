#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST
{
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
    void create();
    Node *createRecursive(Node *temp, int val);
    void createIterative();
    void insert(int val);
    int searchIterative(int val);
    int searchRecursive(Node *temp, int val);
    int height(Node *temp);
    bool balancedTree(Node *temp);
    int findMin(Node *temp);
    int findMax(Node *temp);
    void deleteNode();
    Node *deleteRecursive(Node *temp, int val);
    void makeEmpty();
    Node *makeEmptyRecursive(Node *temp);
    void createCopyTree(BST tree);
    Node *createCopyTreeRecursive(Node *temp);
    bool validBST(Node *temp);
    bool childSum(Node *temp);
    void mirrorImage(Node *temp);
    void inorderRecursive(Node *temp);
    void preorderRecursive(Node *temp);
    void postorderRecursive(Node *temp);
    int inorderSearch(vector<int> &inorder, int start, int end, int x);
    void createTreeFromSequencePreorder(vector<int> &inorder, vector<int> &preorder);
    Node *createTreeFromSequencePreorderRecursive(vector<int> &inorder, vector<int> &preorder, int start, int end, int &preIndex);
    void createTreeFromSequencePostorder(vector<int> &inorder, vector<int> &postorder);
    Node *createTreeFromSequencePostorderRecursive(vector<int> &inorder, vector<int> &postorder, int start, int end, int &postIndex);
};

void BST::createIterative()
{
    int val;
    cout << "Enter Tree Data: ";
    while (true)
    {
        cin >> val;
        if (val == 0)
        {
            break;
        }
        insert(val);
    }
}

void BST::insert(int val)
{
    Node *temp = root;
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    Node *q;
    while (temp != NULL)
    {
        q = temp;
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else if (val > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            cout << "Duplicate data not allowed in BST!" << endl;
            return;
        }
    }
    if (val < q->data)
    {
        q->left = new Node(val);
    }
    else
    {
        q->right = new Node(val);
    }
}

void BST::create()
{
    int val;
    cout << "Enter data: ";
    while (true)
    {
        cin >> val;
        if (val == 0)
        {
            break;
        }
        root = createRecursive(root, val);
    }
}

Node *BST::createRecursive(Node *temp, int val)
{
    if (temp == NULL)
    {
        temp = new Node(val);
        return temp;
    }
    if (val < temp->data)
    {
        temp->left = createRecursive(temp->left, val);
        return temp;
    }
    if (val > temp->data)
    {
        temp->right = createRecursive(temp->right, val);
        return temp;
    }
    else
    {
        cout << "Duplicate Data not allowed in BST!" << endl;
        return temp;
    }
}

int BST::searchIterative(int val)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else if (val < temp->data)
        {
            temp = temp->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int BST::searchRecursive(Node *temp, int val)
{
    if (temp == NULL)
    {
        return 0;
    }
    if(val == temp->data)
    {
        return 1;
    }
    if (val < temp->data)
    {
        return searchRecursive(temp->left, val);
    }
    if (val > temp->data)
    {
        return searchRecursive(temp->right, val);
    }
}

int BST::height(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    int hl = height(temp->left);
    int hr = height(temp->right);
    return 1 + max(hl, hr);
}

bool BST::balancedTree(Node *temp)
{
    if (temp == NULL)
    {
        return true;
    }
    int hl = height(temp->left);
    int hr = height(temp->right);
    if (abs(hl - hr) > 1)
    {
        return false;
    }
    return balancedTree(temp->left) && balancedTree(temp->right);
}

int BST::findMin(Node *temp)
{
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int BST::findMax(Node *temp)
{
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

void BST::makeEmpty()
{
    root = makeEmptyRecursive(root);
}

Node *BST::makeEmptyRecursive(Node *temp)
{
    if (temp == NULL)
    {
        return NULL;
    }
    temp->left = makeEmptyRecursive(temp->left);
    temp->right = makeEmptyRecursive(temp->right);
    delete temp;
    return NULL;
}

void BST::createCopyTree(BST tree)
{
    root = createCopyTreeRecursive(tree.getRoot());
}

Node *BST::createCopyTreeRecursive(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    Node *newNode = new Node(temp->data);
    newNode->left = createCopyTreeRecursive(temp->left);
    newNode->right = createCopyTreeRecursive(temp->right);
    return newNode;
}

bool BST::validBST(Node* root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL)
    {
        int leftMax = findMax(root->left);
        if (leftMax >= root->data)
        {
            return false;
        }
    }
    if (root->right != NULL)
    {
        int rightMin = findMin(root->right);
        if (rightMin <= root->data)
        {
            return false;
        }
    }
    return validBST(root->left) && validBST(root->right);
}

bool BST::childSum(Node *temp)
{
    if (temp == NULL)
    {
        return true;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (temp->right != NULL)
    {
        sum += temp->right->data;
    }
    if (temp->left != NULL)
    {
        sum += temp->left->data;
    }
    if (sum != temp->data)
    {
        return false;
    }
    return childSum(temp->left) && childSum(temp->right);
}

void BST::mirrorImage(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    Node *ptr = temp->left;
    temp->left = temp->right;
    temp->right = ptr;
    mirrorImage(temp->left);
    mirrorImage(temp->right);
}

void BST::inorderRecursive(Node *temp)
{
    if (temp != NULL)
    {
        inorderRecursive(temp->left);
        cout << temp->data << " ";
        inorderRecursive(temp->right);
    }
}

void BST::preorderRecursive(Node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorderRecursive(temp->left);
        preorderRecursive(temp->right);
    }
}

void BST::postorderRecursive(Node *temp)
{
    if (temp != NULL)
    {
        postorderRecursive(temp->left);
        postorderRecursive(temp->right);
        cout << temp->data << " ";
    }
}

void BST::createTreeFromSequencePreorder(vector<int> &inorder, vector<int> &preorder)
{
    int preIndex = 0;
    root = createTreeFromSequencePreorderRecursive(inorder, preorder, 0, preorder.size() - 1, preIndex);
}

int BST::inorderSearch(vector<int> &inorder, int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == x)
        {
            return i;
        }
    }
    return -1;
}

Node *BST::createTreeFromSequencePreorderRecursive(vector<int> &inorder, vector<int> &preorder, int start, int end, int &preIndex)
{
    if (start > end)
    {
        return NULL;
    }

    Node *T = new Node(preorder[preIndex]);
    preIndex++;
    if (start == end)
    {
        return T;
    }
    int inIndex = inorderSearch(inorder, start, end, T->data);
    T->left = createTreeFromSequencePreorderRecursive(inorder, preorder, start, inIndex - 1, preIndex);
    T->right = createTreeFromSequencePreorderRecursive(inorder, preorder, inIndex + 1, end, preIndex);
    return T;
}

void BST::createTreeFromSequencePostorder(vector<int> &inorder, vector<int> &postorder)
{
    int postIndex = postorder.size() - 1;
    root = createTreeFromSequencePostorderRecursive(inorder, postorder, 0, inorder.size() - 1, postIndex);
}

Node *BST::createTreeFromSequencePostorderRecursive(vector<int> &inorder, vector<int> &postorder, int start, int end, int &postIndex)
{
    if (start > end)
    {
        return NULL;
    }

    Node *T = new Node(postorder[postIndex]);
    postIndex--;

    if (start == end)
    {
        return T;
    }

    int inIndex = inorderSearch(inorder, start, end, T->data);
    T->right = createTreeFromSequencePostorderRecursive(inorder, postorder, inIndex + 1, end, postIndex);
    T->left = createTreeFromSequencePostorderRecursive(inorder, postorder, start, inIndex - 1, postIndex);

    return T;
}

void BST::deleteNode()
{
    int val;
    cout << "Enter data to delete: ";
    cin >> val;
    root = deleteRecursive(root, val);
}

Node *BST::deleteRecursive(Node *temp, int val)
{
    if (temp == NULL)
    {
        return NULL;
    }
    if (val < temp->data)
    {
        temp->left = deleteRecursive(temp->left, val);
    }
    else if (val > temp->data)
    {
        temp->right = deleteRecursive(temp->right, val);
    }
    else
    {
        Node *ptr;
        if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            return NULL;
        }
        if (temp->left == NULL)
        {
            ptr = temp->right;
            delete temp;
            return ptr;
        }
        if (temp->right == NULL)
        {
            ptr = temp->left;
            delete temp;
            return ptr;
        }
        temp->data = findMin(temp->right);
        temp->right = deleteRecursive(temp->right, temp->data);
        cout << "Element Deleted!" << endl;
        return temp;
    }
}

int main()
{
    BST tree;
    int choice, val;
    vector<int> inorder{1, 2, 3, 5, 7, 10, 12, 15, 20};
    vector<int> preorder{10, 5, 2, 1, 3, 7, 15, 12, 20};
    vector<int> postorder{1, 3, 2, 7, 5, 12, 20, 15, 10};

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Create Tree (Recursive)\n";
        cout << "2. Create Tree (Iterative)\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Search (Iterative)\n";
        cout << "7. Search (Recursive)\n";
        cout << "8. Height of Tree\n";
        cout << "9. Check if Balanced Tree\n";
        cout << "10. Find Min\n";
        cout << "11. Find Max\n";
        cout << "12. Delete Node\n";
        cout << "13. Make Empty\n";
        cout << "14. Mirror Image\n";
        cout << "15. Validate BST\n";
        cout << "16. Check Child Sum Property\n";
        cout << "17. Create Tree from Inorder & Preorder\n";
        cout << "18. Create Tree from Inorder & Postorder\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.create();
            break;
        case 2:
            tree.createIterative();
            break;
        case 3:
            cout << "Inorder: ";
            tree.inorderRecursive(tree.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "Preorder: ";
            tree.preorderRecursive(tree.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "Postorder: ";
            tree.postorderRecursive(tree.getRoot());
            cout << endl;
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (tree.searchIterative(val) ? "Found" : "Not Found") << endl;
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (tree.searchRecursive(tree.getRoot(), val) ? "Found" : "Not Found") << endl;
            break;
        case 8:
            cout << "Height: " << tree.height(tree.getRoot()) << endl;
            break;
        case 9:
            cout << (tree.balancedTree(tree.getRoot()) ? "Balanced" : "Not Balanced") << endl;
            break;
        case 10:
            cout << "Min value: " << tree.findMin(tree.getRoot()) << endl;
            break;
        case 11:
            cout << "Max value: " << tree.findMax(tree.getRoot()) << endl;
            break;
        case 12:
            tree.deleteNode();
            break;
        case 13:
            tree.makeEmpty();
            cout << "Tree emptied." << endl;
            break;
        case 14:
            tree.mirrorImage(tree.getRoot());
            cout << "Mirror image created." << endl;
            break;
        case 15:
            cout << (tree.validBST(tree.getRoot()) ? "Valid BST" : "Invalid BST") << endl;
            break;
        case 16:
            cout << (tree.childSum(tree.getRoot()) ? "Follows Child Sum Property" : "Does not follow Child Sum Property") << endl;
            break;
        case 17:
            tree.createTreeFromSequencePreorder(inorder, preorder);
            cout << "Tree created from inorder and preorder." << endl;
            break;
        case 18:
            tree.createTreeFromSequencePostorder(inorder, postorder);
            cout << "Tree created from inorder and postorder." << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}