/*
nCr

Given two integer values n and r, the task is to find the value of Binomial Coefficient nCr

A binomial coefficient nCr can be defined as the coefficient of xr in the expansion of (1 + x)n that gives the number of ways to choose r objects from a set of n objects without considering the order.
The binomial coefficient nCr is calculated as : C(n,r) = n! / r! * (n-r) !
Note: If r is greater than n, return 0.
It is guaranteed that the value of nCr will fit within a 32-bit integer.

Examples:
Input: n = 5, r = 2
Output: 10
Explaination: The value of 5C2 is calculated as 5!/(5−2)!*2! = 5!/3!*2! = 10.

Input: n = 2, r = 4
Output: 0
Explaination: Since r is greater than n, thus 2C4 = 0

Input: n = 5, r = 0
Output: 1
Explaination: The value of 5C0 is calculated as 5!/(5−0)!*0! = 5!/5!*0! = 1.

Constraints:
1 ≤ n ≤ 100
0 ≤ r ≤ 100
*/

#include <iostream>
#include <vector>
using namespace std;

// [Approach - 1] Using Recursion - O(n) Time and O(1) Space
int fact(int n) {
    if(n == 0)  return 1;
    return fact(n - 1) * n;
}

int nCr(int n, int r) {
    if(r > n)   return 0;
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

// [Approach - 2] Using Pascal's Rule - O(2^n) Time and O(n) Space
int nCrPascal(int n, int r) {
    if(r > n)   return 0;
    if(r == 0 || n == r)    return 1;

    return (nCrPascal(n - 1, r - 1) + nCrPascal(n - 1, r));
}

// [Approach - 3] Using DP (Memoization) - O(n*r) Time and O(n*r) Space
int solve(int n, int r, vector<vector<int>> &dp) {
    if(r > n)   return 0;
    if(r == 0 || n == r)    return 1;
    if(dp[n][r] != -1)  return dp[n][r];

    return dp[n][r] = solve(n - 1, r - 1, dp) + solve(n - 1, r, dp);
}

int nCrDP(int n, int r) {
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    return solve(n, r, dp);
}

int main() {
    cout << "REC: Factorial of n is: " << nCr(5, 4);
    cout << "\nPASCAL: Factorial of n is: " << nCrPascal(4, 2);
    cout << "\nDP: Factorial of n is: " << nCrPascal(5, 2);
    
    return 0;
}