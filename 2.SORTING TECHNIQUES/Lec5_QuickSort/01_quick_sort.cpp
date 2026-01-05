#include <iostream>
#include <vector>
using namespace std;

// Partition function to place pivot at correct position
int partition(vector<int> &arr, int st, int end){
    int idx = st - 1;          // Index for smaller elements
    int pivot = arr[end];     // Choose last element as pivot

    // Traverse elements and compare with pivot
    for(int j = st; j < end; j++){
        if(arr[j] <= pivot){
            idx++;                       // Move index forward
            swap(arr[j], arr[idx]);     // Swap smaller element
        }
    }

    idx++;                               // Final pivot position
    swap(arr[end], arr[idx]);            // Place pivot correctly

    return idx;                          // Return pivot index
}

// QuickSort function (recursive)
void quickSort(vector<int> &arr, int st, int end){
    if(st < end){
        int pivIdx = partition(arr, st, end); // Partition array

        // Sort left subarray
        quickSort(arr, st, pivIdx - 1);

        // Sort right subarray
        quickSort(arr, pivIdx + 1, end);
    }
}

int main(){
    vector<int> arr = {5,2,6,4,1,3,6,6}; // Input array

    quickSort(arr, 0, arr.size() - 1); // Sort the array

    // Print sorted array
    for(int val : arr){
        cout << val << " ";
    }

    return 0;
}