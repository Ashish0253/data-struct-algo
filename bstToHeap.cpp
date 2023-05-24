#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a new node with given data
struct Node *getNode(int data)
{

    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorderTraversal(Node *root)
{

    if (root == NULL)
        return;

    // NLR
    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root, vector<int> &v)
{

    if (root == NULL)
        return;

    // LNR
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

// Function to convert BST into a Min-Heap without using any extra space
// performs preorder traversal of the tree
void BSTToMinHeap(Node *root, vector<int> arr, int &i)
{

    if (root == NULL)
        return;

    root->data = arr[++i];

    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

void convertToMinHeapUtil(Node *root)
{

    vector<int> arr;
    int i = -1;

    // inorder traversal of BST and store it in arr
    inorderTraversal(root, arr);

    // BST to min heap conversion
    BSTToMinHeap(root, arr, i);
}

int main()
{

    // BST formation
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    // Function Call
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);

    return 0;
}