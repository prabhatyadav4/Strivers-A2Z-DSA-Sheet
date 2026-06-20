/*
Check if a number is odd or not

Problem Statement: Given a non-negative integer n, determine whether it is odd. Return true if the number is odd, otherwise return false. A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).

Examples

Example 1:
Input:
 n = 7

Output:
 true

Explanation:
 7 is not divisible by 2. Hence, it is odd.

Example 2:

Input:
 n = 10

Output:
 false

Explanation:
 10 is divisible by 2. Hence, it is not odd.
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 13;

    // if (num % 2 == 1)
    if(num & 1)                     // Last bit of odd num is always 1
    {
        cout << "Number is odd.";
    }
    else
    {
        cout << "Number is even.";
    }

    return 0;
}