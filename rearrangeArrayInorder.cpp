// program to rearrange 
// positive and negative integers 
// in alternate fashion while keeping 
// the order of positive and negative numbers without using any extra space.

#include <bits/stdc++.h>
using namespace std;

void rightRotate(int arr[], int n, int outOfPlace, int cur) {

    int temp = arr[cur];
    for(int i=cur; i > outOfPlace; i--) 
        arr[i] = arr[i-1];
    arr[outOfPlace] = temp;
}

void rearrange(int arr[], int n) {

    int outOfPlace = -1;

    for(int idx = 0; idx < n; idx++) {

        if(outOfPlace >= 0) {
            
            //find the item which must be moved into the 
            // outOfPlace entry if outOfPlace entry is 
            // positive and current entry is negative OR if outOfPlace entry is negative and current 
            // entry is positive then rightRotate

            if(((arr[idx] >= 0) && (arr[outOfPlace] < 0)) || ((arr[idx] < 0) && (arr[outOfPlace] >= 0))) {

                rightRotate(arr, n, outOfPlace, idx); 

                // the new outOfPlace is now 2 steps 
                // ahead 
                if(idx - outOfPlace >= 2) 
                    outOfPlace = outOfPlace + 2;
                else 
                    outOfPlace = -1;
            }
        }

        // if no entry has been flagged out-of-place
        if(outOfPlace == -1) {
            
            // check if current entry is out-of-place
            if( ((arr[idx] >= 0) && (!(idx & 1))) || ((arr[idx] < 0) && (idx & 1)) ) {

                outOfPlace = idx;
            }
        }
    }
}

void printArray(int arr[], int n) {

    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << endl << "Enter array: ";
    for(int i=0; i<size; i++)
        cin >> arr[i];
    
    cout << "Given array is: \n";
    printArray(arr, size);

    rearrange(arr, size);

    cout << "Rearranged array is: \n";
    printArray(arr, size);

    return 0;
}