/*
Print reverse of a string using recursion

Given a string, the task is to print the given string in reverse order using recursion.

Examples:

Input: s = "Geeks for Geeks"
Output: "skeeG rof skeeG"
Explanation: After reversing the input string we get "skeeG rof skeeG". 

Input: s = "Reverse a string Using Recursion"
Output: "noisruceR gnisU gnirts a esreveR"
Explanation: After reversing the input string we get "noisruceR gnisU gnirts a esreveR". 
*/

#include <iostream>
using namespace std;

// [Approach - 1] - Make a Recursive Call and Then Process the First Char

string recursiveReverse1(string s) {
    if(s.size() == 0)   return s;
    return recursiveReverse1(s.substr(1)) + s[0];
}

// [Approach - 2] - Process the Last Char and Then Make Recursive Call
string recursiveReverse2(string s, int len) {
    if(len == 0)    return "";
    if(len == 1)    return string(1, s[0]);
    return s[len - 1] + recursiveReverse2(s, len - 1);
}

// [Approach - 3] - Optimized- Process from Both Ends
void optimizedReverse(string &s, int left, int right) {
    if(left >= right) return;
    swap(s[left], s[right]);
    optimizedReverse(s, left + 1, right - 1);
} 

int main() {
    string str = "Geeks for Geeks";

    cout << "Recursive1: Reversed String is" << recursiveReverse1(str) << endl;
    cout << "Recursive2: Reversed String is" <<recursiveReverse2(str, str.length()) << endl;
    optimizedReverse(str, 0, str.length() - 1);
    cout << "Optimized: Reversed String is" << str << endl;

    return 0;
}