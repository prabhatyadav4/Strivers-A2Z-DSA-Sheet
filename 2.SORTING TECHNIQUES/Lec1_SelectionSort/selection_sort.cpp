#include <iostream>
using namespace std;

// Function to perform selection sort
void selection_sort(int arr[], int n){
    // Loop through the array elements
    for(int i = 0; i < n - 2; i++){
        int min = i; // Assume current index has the minimum value

        // Find the minimum element in the remaining array
        for(int j = i; j <= n - 1; j++){
            if(arr[j] < arr[min]){
                min = j; // Update index of minimum element
            }
        }

        // Swap the found minimum with the first element
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n]; // Declare array of size n

    // Take array input from user
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Sort the array
    selection_sort(arr, n);

    // Print the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
