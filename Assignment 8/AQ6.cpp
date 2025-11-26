#include <iostream>
using namespace std;

#define MAX 100

int heapArr[MAX];
int heapSize = 0;

void heapifyUp(int index){
    while (index > 0){
        int parent = (index - 1) / 2;
        if (heapArr[parent] < heapArr[index]) {
            swap(heapArr[parent], heapArr[index]);
            index = parent;
        } else break;
    }
}
void heapifyDown(int index){
    while (true){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heapSize && heapArr[left] > heapArr[largest])
            largest = left;

        if (right < heapSize && heapArr[right] > heapArr[largest])
            largest = right;

        if (largest != index) {
            swap(heapArr[index], heapArr[largest]);
            index = largest;
        } else break;
    }
}

void insertElement(int value){
    if (heapSize >= MAX) {
        cout << "Heap overflow!\n";
        return;
    }
    heapArr[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}
int getMax(){
    if (heapSize == 0){
        cout << "Heap empty!\n";
        return -1;
    }
    return heapArr[0];
}

void deleteMax(){
    if (heapSize == 0){
        cout << "Heap empty!\n";
        return;
    }

    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;

    heapifyDown(0);
}

void printHeap(){
    for (int i = 0; i < heapSize; i++)
        cout << heapArr[i]<<" ";
    cout << endl;
}
int main(){
    insertElement(40);
    insertElement(10);
    insertElement(50);
    insertElement(30);
    insertElement(20);

    cout<<"Max element: "<<getMax()<<endl;

    deleteMax();
    cout << "After deleting max: ";
    printHeap();

    return 0;
}
