/*
Decimal to binary number using recursion

Given a decimal number as input, we need to write a program to convert the given decimal number into an equivalent binary number. 

Examples : 

Input: d = 7                                                         
Output: 111
Explanation:  20 + 21  + 22 = 1+2+4 = 7.

Input: d = 10
Output: 1010
Explanation: 21  + 23 = 2+8 = 10.
*/

#include <iostream>
using namespace std;

// Recursive Approach for Small Integers - O(log2n) Time and O(log2n) Space
int decToBinSmall(int d) {
    if(d == 0)  return 0;
    return (d % 2 + 10 * decToBinSmall(d / 2));
}

// Recursive Approach for Big Integers Using String - O(log2n) Time and O(log2n) Space
void decToBinBigRec(int d, string &res) {
    if(d > 1)   decToBinBigRec(d / 2, res);
    res += (d % 2) + '0';
}

string decToBinBig(int d) {
    string res = "";
    decToBinBigRec(d, res);
    return res;
}

int main() {
    int d = 15;
    cout << "Small: The required Binary Number is: " << decToBinSmall(d) << endl;
    cout << "Big: The required Binary Number is: " << decToBinBig(d) << endl;
    
    return 0;
}