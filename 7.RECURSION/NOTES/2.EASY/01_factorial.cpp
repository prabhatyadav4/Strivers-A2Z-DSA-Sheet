/*
Factorial of a Number

Given a non-negative integers n, compute the factorial of the given number. 
Factorial of n is defined as n * (n -1) * (n - 2) * ... * 1. For n = 0, the factorial is defined as 1.

Examples:

Input: n = 5
Output: 120
Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

Input: n = 4
Output: 24
Explanation: 4! = 4 * 3 * 2 * 1 = 24

Input: n = 0
Output: 1

Input: n = 1
Output: 1
*/


#include <iostream>
using namespace std;

// Iterative Approach: TC -> O(n) and SC -> O(1)
int factorialIterative(int n) {
    int ans = 1;
    for(int i = 2; i <= n; i++) {
        ans *= i;
    }

    return ans;
}

// Recursive Approach: TC -> O(n) and SC -> O(n)
int factorialRecursive(int n) {
    if(n == 0 || n == 1)    return 1;
    return n * factorialRecursive(n - 1);
}

int main() {
    int n = 5;
    cout << "Iterative: Factorial of n is: " << factorialIterative(n) << endl;
    cout << "Recursive: Factorial of n is: " << factorialRecursive(n) << endl;

    return 0;
}