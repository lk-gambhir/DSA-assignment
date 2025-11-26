
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

void displayCircular(Node* head) {
    if(head==nullptr){
        cout<<"List is empty.\n";
        return;
    }
    Node*temp=head;
    do{
        cout<<temp->data<< " ";
        temp=temp->next;
    } while(temp!=head);

    cout<<head->data<<endl;
}

int main() {
    Node*head=nullptr;

    Insert(head,20);
    Insert(head,100);
    Insert(head,40);
    Insert(head,80);
    Insert(head,60);
    cout<<"Output: ";
    displayCircular(head);

    return 0;
}
