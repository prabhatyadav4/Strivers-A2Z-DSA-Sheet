/*
XOR of numbers in a given range

Given two integers L and R. Find the XOR of the elements in the range [L , R].


Example 1

Input : L = 3 , R = 5

Output : 2

Explanation : answer = (3 ^ 4 ^ 5) = 2.

Example 2

Input : L = 1, R = 3

Output : 0

Explanation : answer = (1 ^ 2 ^ 3) = 0.

Constraints
1 <= L <= R <= 109
*/

#include <iostream>
using namespace std;

int BruteFindRangeXOR(int l, int r)
{
    int sum = 0;

    for (int i = l; i <= r; i++)
    {
        sum ^= i;
    }

    return sum;
}

int XOR(int n)
{
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    return n;
}

int OptimalFindRangeXOR(int l, int r)
{
    return (XOR(l - 1) ^ XOR(r));
}

int main()
{

    int l = 3, r = 5;

    int ans = BruteFindRangeXOR(l, r);

    cout << "BRUTE: The XOR of numbers from " << l << " to " << r << " is: " << ans << endl;

    int res = OptimalFindRangeXOR(l, r);

    cout << "OPTIMAL: The XOR of numbers from " << l << " to " << r << " is: " << res << endl;

    return 0;
}