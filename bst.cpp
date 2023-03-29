#include<bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d) {
        
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* minVal(Node* root) {

    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

Node* deleteFromBST(Node* root, int val) {

    // base case
    if(root == NULL) 
        return NULL;

    if(root->data == val) {

        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL) {

            int mini = minVal(root->right) -> data;
            root->data = mini;

            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    // left subtree m jaao
    else if(root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    // right subtree m jaao
    else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }

}



Node* maxVal(Node* root) {

    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

void inorderTraversal(Node* root) {

    // base case
    if(root == NULL)        
        return ;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {

    // base case 
    if(root == NULL) 
        return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {

    // base case 
    if(root == NULL) 
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            // purana level complete traverse ho gya
            cout << endl;
            if(!q.empty()) {
                // queue still has some child
                q.push(NULL);
            } 
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    } 
}

Node* insertIntoBST(Node* &root, int d) {

    // base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d > root->data) {
        // right part m insert kro
        root->right = insertIntoBST(root->right, d);
    }
    else {
        // left part m insert kro
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root) {

    int data ;
    cin >> data ;

    while( data != -1) {

        root = insertIntoBST(root, data);
        cin>>data;
    }
}


int main() {

    Node* root = NULL;

    cout<<"Enter data to create BST" << endl;
    takeInput(root);

    cout << endl << "level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;


    cout << "inorder traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "preorder traversal: " << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "postorder traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    cout << "min value: " << minVal(root) -> data << endl;
    cout << "max value: " << maxVal(root) -> data << endl;

    cout << "Enter node to delete: ";
    int val;
    cin >> val;
    deleteFromBST(root, val);
     cout << "inorder traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

     cout << "level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;


    return 0;
}