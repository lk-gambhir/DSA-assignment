/*
Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<int> qu;
    int arr[]={4,7,11,20,5,9};

    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        qu.push(arr[i]);
    }
    queue<int> temp;
    temp=qu;

    cout<<"Original queue: ";
    for(int i=0;i<n;i++){
        cout<<temp.front()<<" ";
        temp.pop();
    }

    temp=qu;
    queue<int> newqu;

    for(int i=0;i<n/2;i++){
        temp.pop();
    }
    queue<int> temp1=qu;

    for(int i=0;i<n;i++){
        if(i%2==0){
            newqu.push(temp1.front());
            temp1.pop();
        }
        else{
            newqu.push(temp.front());
            temp.pop();
        }
    }
    queue<int> temp2=newqu;

    cout<<"\nNew queue: ";
    for(int i=0;i<n;i++){
        cout<<temp2.front()<<" ";
        temp2.pop();
    }
    return 0;
}