/*
Sum Of Digits

Given a positive number n. Find the sum of all the digits of n.

Examples:

Input: n = 687
Output: 21
Explanation: Sum of 687's digits: 6 + 8 + 7 = 21

Input: n = 12
Output 3
Explanation: Sum of 12's digits: 1 + 2 = 3

Constraints:
1 <= n <= 105
*/

#include <iostream>
using namespace std;

int sum_of_digits(int n) {
    if(n < 10)  return n;
    return (n % 10 + sum_of_digits(n / 10));
}

int main() {
    int n = 12345;
    cout << "Sum of digits: " << sum_of_digits(n) << endl;

    return 0;
}