#include<iostream>
using namespace std;

/*
Question:
Given an integer 'n', check whether it is a prime number.
A prime number is a number that has exactly two distinct positive divisors:
1 and the number itself.

Return "true" if the number is prime, otherwise return "false".

Example:
Input: 7
Output: true
*/

int main() {

    // Input the number
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int cnt = 0;  // Will count total divisors of n

    // Loop from 1 to sqrt(n)
    for (int i = 1; i * i <= n; i++) {

        // If i divides n
        if (n % i == 0) {

            cnt++;  // Count divisor i

            // If i and n/i are different, count the second divisor
            if (n / i != i) {
                cnt++;
            }
        }
    }

    // Prime numbers have exactly 2 divisors
    if (cnt == 2) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}