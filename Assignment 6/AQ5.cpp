
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Insert(Node*& head, int value) {
    Node*newNode=new Node();
    newNode->data=value;
    if(head==nullptr){
        head=newNode;
        head->next=head;
        return;
    }
    Node*temp=head;
    while (temp->next!=head)
        temp=temp->next;
    temp->next=newNode;
    newNode->next=head;
}

bool isCircular(Node* head){
    if(head==nullptr)
        return false;

    Node*temp=head->next;
    while(temp!=nullptr && temp!=head)
        temp=temp->next;

    return(temp==head);
}

int main() {
    Node* head=nullptr;

    Insert(head,10);
    Insert(head,20);
    Insert(head,30);
    Insert(head,40);
    Insert(head,50);

    if (isCircular(head))
        cout<<"The linked list is circular."<<endl;
    else
        cout<<"The linked list is NOT circular."<<endl;

    return 0;
}
