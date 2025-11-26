
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};
void Insert(Node*&head,int value,int pos){
    Node*newNode=new Node();
    newNode->data=value;
    if (head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        return;
    }
    else if(pos==1){
        Node*last=head->prev;
        newNode->next=head;
        newNode->prev=last;
        head->prev=newNode;
        last->next=newNode;
        head=newNode;
    }
    else{
        Node*temp=head;
        int count=0;
        while (count<pos-1&&temp->next!=head) {
            temp=temp->next;
            count++;
        }
        Node*nextNode=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=nextNode;
        nextNode->prev=newNode;
        return;
    }
}
void Delete(Node*&head,int value){
    if(head==NULL){
        cout<<"List is empty, nothing to delete";
    }
    Node*temp=head;
    Node*toDelete=nullptr;

    do{
        if(temp->data==value) {
            toDelete=temp;
            break;
        }
        temp=temp->next;
    } while(temp!=head);

    if (!toDelete){
        cout<<"Value "<<value<<" not found.\n";
        return;
    }

    if(toDelete->next==toDelete){
        delete toDelete;
        head=nullptr;
    } 
    else{
        Node*prevNode=toDelete->prev;
        Node*nextNode=toDelete->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;

        if(toDelete == head)
            head=nextNode;

        delete toDelete;
    }

    cout<<"Node "<<value<<" deleted successfully.\n";
}
void Search(Node*&head, int value){
    Node*temp=head;
    int pos=1;
    do{
        if(temp->data == value) {
            cout<<"Value "<<value<<" found at position "<<pos<< ".\n";
            return;
        }
        temp=temp->next;
        pos++;
    } while(temp!=head);

    cout<< "Value "<<value<<" not found.\n";
}

int main(){
    Node* head = nullptr;
    int choice, value, pos;
    while(true){
        cout<<"Enter a choice\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert (1 for beginning): ";
                cin >> pos;
                Insert(head, value, pos);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                Delete(head, value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                Search(head, value);
                break;

            case 4:
                cout << "Exiting\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    }
}
