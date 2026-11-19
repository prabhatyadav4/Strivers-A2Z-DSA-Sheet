/*
921. Factorial of a Given Number

Given an integer n, return the factorial of n.

Factorial of a non-negative integer, is the multiplication of all integers smaller than or equal to n (use 64-bits to return answer).

Example 1:
Input : n = 3

Output : 6

Explanation : Factorial = 1 * 2 * 3 => 6

Example 2:
Input : n = 5

Output : 120

Explanation : Factorial = 1 * 2 * 3 * 4 * 5 => 120

Constraints:
0 <= n <= 15
*/

#include <iostream>
#include <vector>
using namespace std;

long long factorialI(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorialI(n - 1);
}

/*
Problem statement
You are given an integer ‘N’. You have to print the value of Factorial of ‘N’. The Factorial of a number ‘N’ is defined as the product of all numbers from 1 to ‘N’.

For Example:
Consider if ‘N’ = 4, the Factorial of 4 will be the product of all numbers from 1 to 4, which is 1 * 2 * 3 * 4 = 24. Hence, the answer is 24.

Constraints:
1 <= T <= 10
1 <= N <= 100
*/

void factorialII(int n)
{
    vector<int> result(1, 1);

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        for (int j = 0; j < result.size(); j++)
        {
            int product = result[j] * i + carry;

            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry)
        {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }
}

int main()
{
    int n = 5;

    cout << "The factorial of n is: " << factorialI(n) << endl;

    cout << "The factorial of n is: ";
    factorialII(n);
    cout << endl;

    return 0;
}
