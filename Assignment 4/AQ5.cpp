/*
Write a program to implement a stack using (a) Two queues and (b) One Queue.
*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);

    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void pop(){
    if (q1.empty()){
        cout<<"Stack is empty!\n";
        return;
    }
    cout<<"Popped: "<< q1.front()<<endl;
    q1.pop();
}

int top(){
    if (q1.empty()){
        cout<<"Stack is empty!\n";
        return -1;
    }
    return q1.front();
}

bool empty(){
    return q1.empty();
}

int main() {
    push(10);
    push(20);
    push(30);

    cout <<"Top: "<<top()<<endl;
    pop();
    cout <<"Top: "<<top()<<endl;
    pop();
    pop();
    pop();
}

queue<int> q;

void push(int x) {
    int size = q.size();
    q.push(x);

    for (int i=0;i<size;i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop(){
    if (q.empty()){
        cout<<"Stack is empty!\n";
        return;
    }
    cout<<"Popped: "<<q.front()<<endl;
    q.pop();
}

int top(){
    if(q.empty()) {
        cout<<"Stack is empty!\n";
        return -1;
    }
    return q.front();
}

bool empty(){
    return q.empty();
}

int main(){
    push(10);
    push(20);
    push(30);

    cout<<"Top: "<<top()<<endl;
    pop();
    cout<<"Top: "<<top()<<endl;
    pop();
    pop();
    pop();
}

