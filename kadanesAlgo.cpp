#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int size) {

    int sum = 0, best = 0;

    for(int i =0; i<size; i++) {
        
        sum = max(arr[i], sum + arr[i]);
        best = max(sum, best);
    }

    return best;
}

int main() {

    int size = 0;

    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter the array: ";
    int *arr = new int[size];
    for(int i=0; i<size; i++)  
        cin>>arr[i];

    cout << "maximum subarray sum is: " << maxSubarraySum( arr, size);

    delete[] arr;
    
    return 0;
}