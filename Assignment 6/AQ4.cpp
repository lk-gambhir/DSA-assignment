
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

void Insert(Node*& head, char value) {
    Node*newNode=new Node();
    newNode->data=value;
    newNode->next=nullptr;
    newNode->prev=nullptr;

    if(head==nullptr){
        head=newNode;
        return;
    }

    Node*temp=head;
    while(temp->next!=nullptr)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

bool isPalindrome(Node*head) {
    if(head==nullptr)
        return true;

    Node*left=head;
    Node*right=head;
    while(right->next!=nullptr)
        right=right->next;

    while(left!=right && right->next!=left) {
        if (left->data!=right->data)
            return false;
        left=left->next;
        right=right->prev;
    }
    return true;
}

int main() {
    Node*head=nullptr;
    string input;

    cout<<"Enter characters (no spaces): ";
    cin>>input;

    for(char ch : input)
        Insert(head,ch);

    if(isPalindrome(head))
        cout<<"The doubly linked list is a palindrome."<<endl;
    else
        cout<<"The doubly linked list is NOT a palindrome."<<endl;

    return 0;
}
