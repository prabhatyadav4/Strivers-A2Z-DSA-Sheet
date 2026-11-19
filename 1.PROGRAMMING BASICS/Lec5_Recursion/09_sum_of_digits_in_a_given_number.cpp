/*
965. Sum of Digits in a Given Number

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input : num = 529
Output : 7
Explanation : In first iteration the digits sum will be = 5 + 2 + 9 => 16
In second iteration the digits sum will be 1 + 6 => 7.
Now single digit is remaining , so we return it.

Example 2:
Input : num = 101
Output : 2
Explanation : In first iteration the digits sum will be = 1 + 0 + 1 => 2

Now single digit is remaining , so we return it.

Constraints:
0 <= num <= 231 - 1
*/

#include <iostream>
using namespace std;

// Iterative:
// Time Complexity: O(log N)
// Space Complexity: O(1)

int addDigitsIterative(int num)
{
    while (num >= 10)
    {
        int sum = 0;

        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        num = sum;
    }

    return num;
}

// Recursion:
// Time Complexity: O(log N) for a 32-bit integer.
// Space Complexity: O(log N) due to recursion stack.

int sumOfDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return (num % 10) + sumOfDigits(num / 10);
}

int addDigitsRecursive(int num)
{
    if (num < 10)
    {
        return num;
    }

    return addDigitsRecursive(sumOfDigits(num));
}

int main()
{
    int num = 5435;

    cout << "Iterative result: " << addDigitsIterative(num) << endl;
    cout << "Recursive result: " << addDigitsRecursive(num) << endl;

    return 0;
}
