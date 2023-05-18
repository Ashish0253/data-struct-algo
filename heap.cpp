#include<iostream>
using namespace std;

class heap {
    public: 
        int arr[100];
        int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int idx = size;
        arr[idx] = val;

        while(idx > 1) {
            int parent = idx/2;

            if(arr[parent] < arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else {
                return;
            }
        } 
    }

    void print() {
        for(int i =1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromHeap() {

        if(size == 0) {
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int idx = 1;
        while(idx < size) {

            int leftIdx = 2*idx;
            int rightIdx = 2*idx + 1;

            if(leftIdx < size && arr[idx] < arr[leftIdx]) {
                swap(arr[idx], arr[leftIdx]);
                idx = leftIdx;
            }
            else if(rightIdx < size && arr[idx] < arr[rightIdx]) {
                swap(arr[idx], arr[rightIdx]);
                idx = rightIdx;
            }
            else {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    // <= is used for 1 based indexing and for 0 based indexing use <
    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    //build heap
    // for(int i=n/2; i>=i; i--) {
    //     heapify(arr, n, i);
    // }

    //heap sort logic
    for(int i=n; i>=1; i--) {

        // swap first and last element
        swap(arr[i], arr[1]);

        //heapify the remaining heap or bring the largest element to the top
        if(i > 1) 
            heapify(arr, i-1, 1);
    }
}

int main() {

    heap h;

    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(52);

    h.deletefromHeap();
    h.print();


    int arr[6] = { -1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation 
    for(int i=n/2; i>=1; i--) {
        heapify(arr, n, i);
    }

    cout << " printing heapified array " << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heapSort
    heapSort(arr, n);

    cout << " printing sorted array " << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}