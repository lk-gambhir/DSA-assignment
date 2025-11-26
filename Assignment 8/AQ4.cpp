/*
4. Write a program to determine whether a given binary tree is a BST or not.
*/

#include <iostream>
#include <limits.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=nullptr;
    }
};

bool isBSTUtil(Node* root, int minVal, int maxVal){
    if (root == nullptr){
        return true;
    }

    if (root->data <= minVal || root->data >= maxVal){
        return false;
    }

    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(20);
    root->left->left=new Node(3);
    root->left->right=new Node(7);

    if(isBST(root))
        cout << "Yes, it is a BST";
    else
        cout << "No, it is NOT a BST";

    return 0;
}
