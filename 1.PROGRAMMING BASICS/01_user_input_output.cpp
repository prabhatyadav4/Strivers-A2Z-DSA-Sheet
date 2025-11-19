// Input Output - Easy Problem
// Complete the function printNumber which takes an integer input from the user and prints it on the screen.
//
// Use:
// for C++ : cout << variable_name;
// for Java : System.out.print();
// for Python : print()
// for Javascript : console.log()
//
// Examples:
// Input(user gives value): 7
// Output: 7

#include <iostream>
using namespace std;

class Solution {
public:
    void printNumber() {
        int n;           // Declare an integer variable
        cin >> n;        // Read integer input from user
        cout << n;       // Print the integer to console
    }
};

int main(){
    Solution obj;        // Create object of Solution class
    obj.printNumber();   // Call printNumber function
    return 0;            // Return 0 to indicate successful execution
}
 