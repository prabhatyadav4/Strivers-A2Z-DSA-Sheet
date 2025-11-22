#include <iostream>
using namespace std;

/*

Function to print a triangular pattern of characters in reverse alphabetical order

Input: n = 5

Output:
E 
D E 
C D E 
B C D E 
A B C D E 

*/

// Function to print triangular pattern with reverse alphabetical characters
void pattern18(int n){
    // Iterate for each row
    for(int i = 0; i < n; i++){
        // Print characters from (E - i) to E
        for(char ch = 'E' - i; ch <= 'E'; ch++){
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
    pattern18(n);

    return 0;
}