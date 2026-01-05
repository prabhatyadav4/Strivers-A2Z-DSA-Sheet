#include <iostream>
using namespace std;

// Function to perform Bubble Sort on the array
void bubble_sort(int arr[], int n) {
    // Outer loop runs from the last index to the first
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;  // Flag to check if any swap happened in this pass

        // Inner loop compares adjacent elements
        for (int j = 0; j <= i - 1; j++) {
            // If elements are in the wrong order, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;  // Mark that a swap occurred
            }
        }

        // If no swaps occurred, the array is already sorted
        if (didSwap == 0) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];  // Declare array of size n

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call bubble sort function
    bubble_sort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;  // End of program
}