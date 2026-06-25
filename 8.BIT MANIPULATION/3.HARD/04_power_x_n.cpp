/*
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include <iostream>
using namespace std;

// 1. Brute Force

double BruteMyPow(double x, int n)
{
    long long N = n;

    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    double ans = 1;

    for (long long i = 0; i < N; i++)
    {
        ans *= x;
    }

    return ans;
}

double solve(double x, long n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return solve(1 / x, -n);
    }

    if (n % 2 == 0)
    {
        return solve(x * x, n / 2);
    }

    return x * solve(x * x, (n - 1) / 2);
}

double BetterMyPow(double x, int n)
{
    return solve(x, (long)n);
}

double OptimalMyPow(double x, int n)
{
    long long N = n;

    if (N < 0)
    {
        x = x / 2;
        N = -N;
    }

    double ans = 1;

    while (N > 0)
    {
        if (N & 1)
        {
            ans *= x;
        }

        x *= x;
        N >>= 1;
    }

    return ans;
}

int main()
{
    double x = 2;
    int n = 10;

    cout << "BRUTE: x raised to the power n is: " << BruteMyPow(x, n) << endl;
    cout << "BETTER: x raised to the power n is: " << BetterMyPow(x, n) << endl;
    cout << "OPTIMAL: x raised to the power n is: " << OptimalMyPow(x, n) << endl;

    return 0;
}