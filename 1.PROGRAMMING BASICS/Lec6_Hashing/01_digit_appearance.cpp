#include <iostream>
using namespace std;

// Count of digit appearance
int main(){
    // Declare an integer variable 'n' to store the size of the array.
    int n;
    cout << "Enter the size of the array: "; // Prompt user for array size
    cin >> n;
    // Declare an integer array 'arr' of size 'n'.
    int arr[n];
    cout << "Enter the elements of the array: "; // Prompt user for array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // Read elements into the array
    }

    // Precompute the frequency of each digit.
    // 'hash' array will store the frequency of numbers.
    // Assuming numbers are between 0 and 12 for this example (size 13).
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1; // Increment the count for the current number
    }

    // Declare an integer variable 'q' to store the number of queries.
    int q;
    cout << "Enter the number of queries: "; // Prompt user for number of queries
    cin >> q;
    while(q--){
        // Declare an integer variable 'number' to store the number to be searched.
        int number; 
        cout << "Enter the number to search for its appearance: "; // Prompt user for the number to search
        cin >> number;
        cout << "Appearance of " << number << ": " << hash[number] << endl; // Fetch and print the frequency of the number
    }
    return 0;
}