/*
Divisors of a Number

You are given an integer n. You need to find all the divisors of n.
Return all the divisors of n as an array or list in a sorted order.
A number which completely divides another number is called it's divisor.


Example 1

Input: n = 6

Output = [1, 2, 3, 6]

Explanation: The divisors of 6 are 1, 2, 3, 6.

Example 2

Input: n = 8

Output: [1, 2, 4, 8]

Explanation: The divisors of 8 are 1, 2, 4, 8.

Constraints
1 <= n <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> BruteDivisors(int n)
{
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

vector<int> OptimalDivisors(int n)
{
    vector<int> ans;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            if (i != n / i)
            {
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n = 36;

    vector<int> ans1 = BruteDivisors(n);

    cout << "BRUTE: The divisors of n are: ";

    for (int num : ans1)
    {
        cout << num << " ";
    }

    vector<int> ans2 = OptimalDivisors(n);

    cout << "\nOPTIMAL: The divisors of n are: ";

    for (int num : ans2)
    {
        cout << num << " ";
    }

    return 0;
}