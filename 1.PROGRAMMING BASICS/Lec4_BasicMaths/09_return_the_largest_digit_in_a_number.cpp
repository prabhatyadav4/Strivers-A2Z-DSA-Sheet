/*
957. Return the Largest Digit in a Number
You are given an integer n. Return the largest digit present in the number.

Example 1:
Input: n = 25
Output: 5
Explanation: The largest digit in 25 is 5.

Example 2:
Input: n = 99
Output: 9
Explanation: The largest digit in 99 is 9.

Constraints:
0 <= n <= 5000
n will contain no leading zeroes except when it is 0 itself.
*/

#include <iostream>
using namespace std;

int largestDigit(int n)
{
    if (n == 0)
    {
        return 0;
    }

    n = abs(n);
    int maxDigit = 0;

    while (n > 0)
    {
        int digit = n % 10;

        if (digit == 9)
        {
            return 9;
        }

        maxDigit = max(maxDigit, digit);

        n /= 10;
    }

    return maxDigit;
}

int main()
{
    int n = 5432634;

    cout << "The largest digit in the number is: " << largestDigit(n) << endl;

    return 0;
}