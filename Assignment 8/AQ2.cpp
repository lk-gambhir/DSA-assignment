/*
2. Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST
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

Node* insertNode(Node* root,int value){
    if (root==nullptr){
        return new Node(value);
    }
    if(value<root->data){
        root->left=insertNode(root->left, value);
    }
    else if(value>root->data){
        root->right=insertNode(root->right,value);
    }
    return root;
}

bool searchRecursive(Node*root,int value){
    if(root==nullptr){
        return false;
    }
    if(root->data==value){
        return true;
    }
    if(value<root->data){
        return searchRecursive(root->left,value);
    }
    else if(value>root->data){
        return searchRecursive(root->right,value);
    }
}

bool searchNonRecursive(Node*root,int value){
    Node*curr=root;

    while(curr!=nullptr){
        if(value==curr->data){
            return true;
        }
        else if(value<curr->data){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    } 
    return false;  
}
int maximumElement(Node* root) {
    if(root==nullptr)
        return -1;

    Node*curr=root;
    while(curr->right!=nullptr){
        curr=curr->right;
    }
    return curr->data;
}

int minimumElement(Node* root) {
    if(root==nullptr)
        return -1;

    Node*curr=root;
    while(curr->left!=nullptr){
        curr=curr->left;
    }
    return curr->data;
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = nullptr;

    while(root!=nullptr) {
        if(target->data<root->data) {
            succ=root;
            root=root->left;
        }
        else if(target->data>root->data) {
            root=root->right;
        }
        else{
            if(root->right!=nullptr) {
                Node*temp=root->right;
                while(temp->left!=nullptr)
                    temp=temp->left;
                succ=temp;
            }
            break;
        }
    }
    return succ;
}
Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = nullptr;

    while(root!=nullptr) {
        if(target->data>root->data) {
            pred=root;
            root=root->right;
        }
        else if(target->data<root->data) {
            root=root->left;
        }
        else{
            if(root->left!=nullptr) {
                Node*temp=root->left;
                while(temp->right!=nullptr)
                    temp=temp->right;
                pred=temp;
            }
            break;
        }
    }
    return pred;
}



int main(){
    Node*root=nullptr;
    root=insertNode(root,10);
    root=insertNode(root,40);
    root=insertNode(root,30);
    root=insertNode(root,50);
    root=insertNode(root,20);

    bool found;
    found=searchNonRecursive(root,20);
    cout<<found<<endl;
    found=searchRecursive(root,60);
    cout<<found<<endl;
    
    int max,min;
    max=maximumElement(root);
    min=minimumElement(root);
    cout<<"Maximum: "<<max<<" Minimum: "<<min<<endl;

    return 0;
}