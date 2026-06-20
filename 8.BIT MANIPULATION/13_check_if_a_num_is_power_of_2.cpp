/*
Check if a number is power of 2 or not

Problem Statement: Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two if there exists an integer x such that n == 2ˣ.

Examples

Example 1:

Input:
n = 16

Output:
true

Explanation:
2⁴ = 16, so 16 is a power of two.

Example 2:

Input:
n = 3

Output: false

Explanation:
3 is not a power of two.
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 16;

    if (num > 0 && (num & (num - 1)) == 0)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}