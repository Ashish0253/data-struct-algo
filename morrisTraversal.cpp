#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    Node* right; 
};

// Function to traverse the binary tree without recursion and without stack 
void MorrisTraversal(Node* root) {
    Node *curr;

    if(root == NULL)
        return;
    
    curr = root;
    while(curr != NULL) {

        if(curr->left == NULL) {
            cout<<curr->data << " ";
            curr = curr->right;
        }
        else {

            // Find inorder predecessor of curr 
            Node *pre = curr->left;
            while(pre->right != NULL && pre->right != curr) 
                pre = pre->right;

            //make curr as the right child of its inorder predecessor
            if(pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            }

            // revert the changes made to restore the original tree
            else{
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    
}

// helper function  that allocates a new node 
Node* newNode(int data) {
    
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Driver Program 
int main() {

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    MorrisTraversal(root);

    return 0;
}
