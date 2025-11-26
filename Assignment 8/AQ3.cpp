/*
3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

Node* insertElement(Node*root, int value){
    if (root==nullptr){
        return new Node(value);
    }
    if(value==root->data){
        return root;}
    if(value<root->data){
        root->left=insertElement(root->left, value);
    }
    else if(value>root->data){
        root->right=insertElement(root->right,value);
    }
    return root;
}


Node* findMin(Node* root) {
    while(root->left!=nullptr)
        root=root->left;
    return root;
}

Node* deleteElement(Node*root, int value){
    if(root==nullptr){
        return root;
    }
    if (value<root->data){
        root->left=deleteElement(root->left, value);
    }
    else if(value>root->data){
        root->right=deleteElement(root->right,value);
    }
    else{
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            root=nullptr;
        }
        else if(root->left==nullptr){
            Node*temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==nullptr){
            Node*temp=root;
            root=root->left;
            delete temp;
        }
        else{
            Node*temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteElement(root->right,temp->data);
        }
        
    }
    return root;
}

int maxDepth(Node*root){
    if (root==nullptr){
        return 0;
    }
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);

    return 1+max(leftDepth,rightDepth);
}

int minDepth(Node*root){
    if (root==nullptr){
        return 0;
    }
    if (root->left==nullptr){
        return 1+minDepth(root->left);
    }
    if(root->right==nullptr){
        return 1+minDepth(root->right);
    }

    return 1+min(minDepth(root->left), minDepth(root->right));


}

int main(){
    Node*root=nullptr;
    root=insertElement(root,10);
    root=insertElement(root,40);
    root=insertElement(root,30);
    root=insertElement(root,50);
    root=insertElement(root,20);

    root=deleteElement(root,10);
    int maxmDepth=maxDepth(root);
    int minmDepth=minDepth(root);

    cout<<"Minimum depth: "<<minmDepth<<"\nMaximum Depth: "<<maxmDepth;

    return 0;
}