/*
Checking if the i-th Bit is Set

Problem Statement: Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

Examples

Example 1:

Input: 
n = 5, i = 0

Output: 
true

Explanation: 
Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

Example 2:

Input: 
n = 10, i = 1

Output: 
true

Explanation: 
Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).


(1 << i) & num   → set if result ≠ 0
(num >> i) & 1   → set if result ≠ 0
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 13;
    int i = 2;

    // Method 1
    if ((1 << i) & num)
    {
        cout << "Bit is set." << endl;
    }
    else
    {
        cout << "Bit is not set." << endl;
    }

    // Method 2
    if ((num >> i) & 1)
    {
        cout << "Bit is set." << endl;
    }
    else
    {
        cout << "Bit is not set." << endl;
    }

    return 0;
}