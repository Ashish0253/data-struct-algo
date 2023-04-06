#include <bits/stdc++.h>
using namespace std;

// merges two subarrays
// first subarray is arr[begin...mid]
// second subarray is arr[mid+1...end]
void merge(int arr[], int left, int mid, int right) {

    // size of two subarrays 
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    // create temp arrays
    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    // copy data to temp arrays
    for(int i=0; i < subArrayOne; i++) 
        leftArray[i] = arr[left + i];
    for(int i=0; i < subArrayTwo; i++)
        rightArray[i] = arr[mid + 1 + i];
    
    int indexOfSubArrayOne = 0, // initial idx of first subarray 
        indexOfSubArrayTwo = 0; // initial idx of second subarray
    int indexOfMergedArray = left; // inital idx of merges array

    // merge the temp arrays back into arr[left...right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {

        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {

            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }

        indexOfMergedArray++;
    }

    // copy the remaining elements of left[]
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // copy the remaining elements of right[]
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int begin, int end) {

    // base case
    if(begin >= end)
        return; 
    
    int mid = begin + (end - begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}


// function to print an array
void printArray(int arr[], int size) {

    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main() {
    
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter array: ";
    for(int i=0; i<size; i++) 
        cin >> arr[i];
    
    cout << "Given array is : ";
    printArray(arr, size);

    mergeSort(arr, 0, size-1);

    cout << endl << "Sorted Array is: ";
    printArray(arr, size);

    return 0;
}