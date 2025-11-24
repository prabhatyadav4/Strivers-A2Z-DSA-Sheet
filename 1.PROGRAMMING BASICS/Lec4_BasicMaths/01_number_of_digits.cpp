#include <bits/stdc++.h>
using namespace std;

/*
 * Function: countDigits
 * ---------------------
 * Returns the number of digits in the integer 'n'.
 *
 * Example:
 * n = 123 → returns 3
 *
 * We use log10(n) to find how many digits n has.
 * +1 is added because log10 gives position of the highest digit.
 */

int countDigits(int n) {
    // Special case: if n is 0, it has exactly 1 digit
    if (n == 0) return 1;

    // Using absolute value in case the number is negative
    int cnt = (int)(log10(abs(n)) + 1);

    return cnt;
}

// OR

// int countDigits(int n) {
//     // Special case: if n is 0, it has exactly 1 digit
//     if (n == 0) return 1;

//     // Using absolute value in case the number is negative
//     int cnt = 0;
// 	while(n > 0){
// 		int lastDigit = n % 10;
// 		cnt = cnt + 1;
// 		n = n / 10;
// 	}
//     return cnt;
// }

int main() {
    int n;

    // Asking user for input
    cout << "Enter a number: ";
    cin >> n;

    // Calling the function
    int result = countDigits(n);

    // Displaying the answer
    cout << "Number of digits: " << result << endl;

    return 0;
}
