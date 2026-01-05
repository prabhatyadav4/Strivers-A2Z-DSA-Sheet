#include <iostream>
using namespace std;

// Function to sort the array using insertion sort
void insertionSort(int arr[], int n){
    // Start from the second element
    for(int i = 1; i < n; i++){
        int curr = arr[i];        // Current element to be placed
        int prev = i - 1;         // Index of previous element

        // Shift elements greater than curr to the right
        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Place curr in its correct position
        arr[prev + 1] = curr;
    }
}

// Function to print the array
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];  // Declare array of size n

    // Input array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Sort the array
    insertionSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}