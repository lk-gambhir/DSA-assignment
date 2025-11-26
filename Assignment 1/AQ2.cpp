#include <iostream>
using namespace std;

int main(){

    int arr[100],filterArr[100],num;
    
    cout <<"Enter the number of elements for the array: ";
    cin >>num;

    cout<<"Enter the elements: ";
    for(int i=0;i<num;i++){
        cout<<": ";
        cin>> arr[i];
    }
    int count=0;
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;){
            if(arr[i]==arr[j]){
                for(int k=j;k<num;k++){
                    arr[k]=arr[k+1];
                }
                num--;
            }else{
                j++;
            }
        }
    }
    for(int i=0;i<num;i++){
        cout<< arr[i]<<" ";
    }

    return 0;
}
