#include <iostream>
using namespace std;

int main(){

    int arr[6]={1,2,3,4,5,6};
    int temp=0;
    for(int i=0;i<3;i++){
        temp=arr[i];
        arr[i]=arr[5-i];
        arr[5-i]=temp;
    }
    cout << "Reversed Array: ";
    for(int i=0;i<6;i++){
        cout<< arr[i]<<" ";
    }
    cout<<"\n";

    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int C[2][2] = {0};

    cout << "Matrix Multiplication Result:\n";
    for(int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<3;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        cout<<"|";
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout<<"|\n";
    }

    int matrix[3][3]{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    temp=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    cout << "Transpose:\n";
    for(int i=0;i<3;i++){
        cout<<"|";
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }cout << "|\n";
    }
    return 0;
}