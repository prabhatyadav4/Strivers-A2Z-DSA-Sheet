#include <iostream>
using namespace std;

/*
Function to print a triangular pattern of characters in alphabetical order

Input: n = 5

Output:
A 
B B 
C C C 
D D D D 
E E E E E 
*/

// Function to print triangular pattern with alphabetical characters
void pattern16(int n){
    // Iterate for each row
    for(int i = 0; i < n; i++){
        // Get character starting from 'A'
        char ch = 'A' + i;
        // Print the same character (i+1) times
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Main function
int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern16(n);

    return 0;
}