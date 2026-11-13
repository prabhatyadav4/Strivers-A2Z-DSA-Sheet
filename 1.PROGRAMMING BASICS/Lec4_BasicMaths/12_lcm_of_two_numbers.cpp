/*
792. LCM of two numbers

You are given two integers n1 and n2. You need find the Lowest Common Multiple (LCM) of the two given numbers. Return the LCM of the two numbers.

The Lowest Common Multiple (LCM) of two integers is the lowest positive integer that is divisible by both the integers.

Example 1:
Input: n1 = 4, n2 = 6

Output: 12

Explanation: 4 * 3 = 12, 6 * 2 = 12.

12 is the lowest integer that is divisible both 4 and 6.

Example 2:
Input: n1 = 3, n2 = 5

Output: 15

Explanation: 3 * 5 = 15, 5 * 3 = 15.

15 is the lowest integer that is divisible both 3 and 5.

Constraints:
1 <= n1, n2 <= 1000
*/

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int BruteLCM(int n1, int n2)
{
    int num = max(n1, n2);

    while (true)
    {
        if (num % n1 == 0 && num % n2 == 0)
        {
            return num;
        }

        num++;
    }
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int BetterLCM(int n1, int n2)
{
    return (n1 / gcd(n1, n2)) * n2;
}

int OptimalLCM(int n1, int n2)
{
    return lcm(n1, n2);
}

int main()
{
    int n1 = 4, n2 = 6;

    cout << "Brute LCM: " << BruteLCM(n1, n2) << '\n';
    cout << "Better LCM: " << BetterLCM(n1, n2) << '\n';
    cout << "Optimal LCM: " << OptimalLCM(n1, n2) << '\n';
}