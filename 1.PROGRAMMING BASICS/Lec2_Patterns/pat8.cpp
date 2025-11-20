#include <iostream>
using namespace std;

/* 

Function to print an inverted triangle pattern of asterisks

Input: n = 4

Output:
*********
 ******* 
  *****  
   ***   
    * 

*/

void pattern8(int n){
        // Outer loop for rows
        for(int i = 0; i < n; i++){
                // Space before stars
                for(int j = 0; j < i; j++){
                        cout << " ";
                }
                // Print stars
                for(int k = 0; k < 2*n-(2*i+1); k++){
                        cout << "*";
                }
                // Space after stars
                for(int j = 0; j < i; j++){
                        cout << " ";
                }
                cout << endl; // Move to next line after each row
        }
}

int main(){
        int n;
        cout << "Enter the number of patterns: ";
        cin >> n; // Input for the number of rows in the pattern
        pattern8(n); // Call function to print the pattern
        return 0;
}