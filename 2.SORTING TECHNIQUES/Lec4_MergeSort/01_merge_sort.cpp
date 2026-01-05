#include <iostream>
#include <vector>
using namespace std;

// Merges two sorted halves of arr: [st..mid] and [mid+1..end]
void merge(vector<int> &arr, int st, int end, int mid){
    vector<int> temp;        // Temporary array to store merged result
    int i = st;              // Pointer for left half
    int j = mid + 1;         // Pointer for right half
    
    // Compare elements from both halves and store smaller one
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    // Copy remaining elements of left half (if any)
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements of right half (if any)
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for(int idx = 0; idx < temp.size(); idx++){
        arr[idx + st] = temp[idx];
    }
}

// Recursively divides the array and sorts it
void mergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end - st) / 2;  // Find middle index

        mergeSort(arr, st, mid);        // Sort left half
        mergeSort(arr, mid + 1, end);   // Sort right half

        merge(arr, st, end, mid);       // Merge both halves
    }
}

int main(){
    vector<int> arr = {4, 3, 5, 6};     // Input array

    mergeSort(arr, 0, arr.size() - 1);  // Sort array

    // Print sorted array
    for(int val : arr){
        cout << val << " ";
    }

    return 0;
}