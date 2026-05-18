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

double BrutePow(double x, int n)
{
    if (n == 0 || n == 1)
        return 1;
    long long temp = n;

    if (n < 0)
    {
        x = 1 / x;
        temp = -1 * 1LL * n;
    }

    double ans = 1;

    for (long long i = 0; i < temp; i++)
    {
        ans *= x;
    }

    return ans;
}

double solve(double x, long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n < 0)
        return solve(1 / x, -n);

    if (n % 2 == 0)
        return solve(x * x, n / 2);
    else
        return x * solve(x * x, (n - 1) / 2);
}

double OptimalPow(double x, int n)
{
    return solve(x, (long)n);
}

int main()
{
    double x = 2.0;
    int n = 10;

    double result1 = BrutePow(x, n);
    cout << "BRUTE: " << x << "^" << n << " = " << result1 << endl;

    double result2 = OptimalPow(x, n);
    cout << "OPTIMAL: " << x << "^" << n << " = " << result2 << endl;

    return 0;
}