#include <iostream>
using namespace std;

/*
Function to print a pattern of asterisks

Input: n = 4

Output:
    *    
   ***
  *****
 *******
*********

Parameters:
- n: integer representing the number of rows for the upper half of the diamond

Description:
This function creates a triangle-shaped pattern by:
1. Iterating through n rows
2. For each row i, printing (n-i-1) leading spaces
3. Printing (2*i+1) asterisk
4. Printing (n-i-1) trailing spaces
5. Moving to the next line after each row
*/
void pattern7(int n){
    for(int i = 0; i < n; i++){
        // Space
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        // Star
        for(int k = 0; k < 2 * i + 1; k++){
            cout << "*";
        }
        // Space
        for(int j = 0; j < n - i -1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the number of patterns: ";
    cin >> n;
    pattern7(n);

    return 0;
}