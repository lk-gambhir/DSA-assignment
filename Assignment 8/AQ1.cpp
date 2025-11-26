/*
Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using a recursive approach
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode=new Node();
    newNode->data=value;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
}

void preorder(Node* root) {
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root==nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;

    return 0;
}
