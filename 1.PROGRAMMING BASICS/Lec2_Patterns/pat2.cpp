#include <iostream>
using namespace std;

// Function to print a triangular pattern of asterisks
/*
Function to print a right-aligned triangular pattern of asterisks

Input: n = 4

Output:
* 
* * 
* * * 
* * * * 

*/
void pattern2(int n){
    // Outer loop for each row
    for(int i = 0; i < n; i++){
        // Inner loop to print asterisks (increases with each row)
        for(int j = 0; j <= i; j++){
            cout << "* ";
        }
        // Move to next line after each row
        cout << endl;
    }
}

int main(){
    int n;
    // Get pattern size from user
    cout << "Enter the size of pattern: ";
    cin >> n;
    // Call function to display pattern
    pattern2(n);

    return 0;
}