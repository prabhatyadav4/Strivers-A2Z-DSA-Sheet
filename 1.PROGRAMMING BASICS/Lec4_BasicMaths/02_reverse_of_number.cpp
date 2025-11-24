#include <iostream>
using namespace std;

/*
 * Program: Reverse of a Number
 *
 * Given a number N, the task is to reverse its digits.
 *
 * Example:
 * Input: 1234
 * Output: 4321
 *
 * Note:
 * Trailing zeros are removed automatically when reversing.
 * Example: 10400 -> 401
 */

int main() {
    int N;
    cin >> N;   // Input the number

    int revNum = 0;   // Variable to store reversed number

    // Loop runs until all digits are processed
    while (N > 0) {
        int lastDigit = N % 10;    // Extract last digit
        revNum = (revNum * 10) + lastDigit;  // Append digit to reverse number
        N = N / 10;                // Remove last digit from N
    }

    cout << revNum;   // Output the reversed number
    return 0;
}