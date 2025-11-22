#include <iostream>
using namespace std;

/*
Function to print a triangle pattern of characters

Input: n = 5

Output:
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/

// Function to print triangle pattern with alphabetic characters
void pattern17(int n){
    for(int i = 0; i < n; i++){
        // Print leading spaces
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        
        // Initialize character and calculate midpoint
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        
        // Print characters (ascending then descending)
        for(int k = 1; k <= 2 * i + 1; k++){
            cout << ch;
            if(k <= breakpoint){
                ch++;
            }
            else{
                ch--;
            }
        }
        
        // Print trailing spaces
        for(int l = 0; l < n - i - 1; l++){
            cout << " ";
        }
        cout << endl;
    }
}

// Main function
int main(){
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;
    pattern17(n);

    return 0;
}