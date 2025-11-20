#include <iostream>
using namespace std;

/* 

Function to print an n x n square pattern of asterisks

Input: n = 4

Output:
* * * * 
* * * * 
* * * * 
* * * * 

*/

void pattern1(int n){
    // Outer loop for rows
    for(int i = 0; i < n; i++){
        // Inner loop for columns
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << endl; // Move to next line after each row
    }
}

int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern1(n); // Call function to print pattern
    return 0;
}