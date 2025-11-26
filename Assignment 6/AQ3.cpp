
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void InsertDoubly(Node*& head, int value) {
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

int sizeDoubly(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

struct NodeC{
    int data;
    NodeC* next;
};

void InsertCircular(NodeC*& head, int value) {
    NodeC*newNode=new NodeC();
    newNode->data=value;
    if(head==nullptr){
        head=newNode;
        head->next=head;
        return;
    }
    NodeC*temp=head;
    while (temp->next!=head)
        temp=temp->next;
    temp->next=newNode;
    newNode->next=head;
}
int sizeCircular(NodeC*head2) {
    if(!head2)
        return 0;

    int count=0;
    NodeC*temp=head2;
    do{
        count++;
        temp=temp->next;
    } while(temp!=head2);

    return count;
}

int main() {
    Node* head=nullptr;
    InsertDoubly(head,10);
    InsertDoubly(head,20);
    InsertDoubly(head,30);
    InsertDoubly(head,40);

    cout<<"Size of Doubly Linked List: "<<sizeDoubly(head)<< endl;

    NodeC* head2=nullptr;
    InsertCircular(head2, 20);
    InsertCircular(head2, 100);
    InsertCircular(head2, 40);
    InsertCircular(head2, 80);
    InsertCircular(head2, 60);

    cout<<"Size of Circular Linked List: "<<sizeCircular(head2)<<endl;
    return 0;
}
