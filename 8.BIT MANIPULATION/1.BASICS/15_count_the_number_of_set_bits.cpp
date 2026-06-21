/*
Count the number of set bits

Problem Statement: Given an integer n, return the number of set bits (1s) in its binary representation.

Examples

Example 1:

Input:
n = 5

Output:
 2

Explanation:
The binary representation of 5 is 101, which has 2 set bits.

Example 2:

Input:
n = 15

Output:
4

Explanation:
The binary representation of 15 is 1111, which has 4 set bits.
*/

#include <iostream>
using namespace std;

int main()
{

    // Method 1:
    int num = 13;

    int count = 0;

    while (num > 0)
    {
        count += (num & 1);
        num >>= 1;
    }

    cout << "The count of set bits is: " << count << endl;

    // Method 2:
    int n = 16;

    int cnt = 0;

    while (n)
    {
        n &= (n - 1);
        cnt++;
    }

    cout << "The count of set bits is: " << cnt << endl;

    return 0;
}