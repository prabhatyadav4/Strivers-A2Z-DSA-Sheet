/*
29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.


Constraints:
-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

#include <iostream>
using namespace std;

int BruteDivide(int dividend, int divisor)
{

    if (dividend == divisor)
        return 1;
    if (divisor == 1)
        return dividend;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    bool negative = (dividend < 0) ^ (divisor < 0);

    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);

    long long ans = 0;
    long long sum = 0;

    while (sum + d <= n)
    {
        sum += d;
        ans++;
    }

    if (negative)
    {
        ans = -ans;
    }

    if (ans > INT_MAX)
        return INT_MAX;
    if (ans < INT_MIN)
        return INT_MIN;

    return (int)ans;
}

int OptimalDivide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    if (divisor == 1)
        return dividend;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    bool negative = (dividend < 0) ^ (divisor < 0);

    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);

    long long quotient = 0;

    while (dvd >= dvs)
    {
        long long temp = dvs;
        long long multiple = 1;

        while ((temp << 1) <= dvd)
        {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        quotient += multiple;
    }

    if (negative)
        quotient = -quotient;

    if (quotient > INT_MAX)
        return INT_MAX;
    if (quotient < INT_MIN)
        return INT_MIN;

    return (int)quotient;
}

int main()
{

    int dividend = 10, divisor = 3;

    int ans = BruteDivide(dividend, divisor);

    cout << "BRUTE: The result of dividing " << dividend << " and " << divisor << " is " << ans << endl;

    int res = OptimalDivide(dividend, divisor);

    cout << "OPTIMAL: The result of dividing " << dividend << " and " << divisor << " is " << res << endl;

    return 0;
}