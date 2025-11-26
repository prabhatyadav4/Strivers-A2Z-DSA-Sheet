/*
 GCD or HCF
 Moderate

 Problem Statement:
 You are given two integers 'n' and 'm'.
 Your task is to calculate gcd(n, m) *without using any library functions*.

 Note:
 The greatest common divisor (gcd) of two numbers 'n' and 'm' is the largest
 positive integer that divides both 'n' and 'm' without leaving a remainder.

 Example:
 Input:
 n = 6, m = 4
 Output:
 2

 Explanation:
 gcd(6,4) = 2 because 2 is the largest integer that divides both numbers.

 Sample Input 1:
 9 6

 Sample Output 1:
 3

 Explanation:
 gcd(9,6) = 3, as 3 is the largest positive integer that divides both 6 and 9.
*/

#include <iostream>
using namespace std;

/*
// ----------------------------
// Brute Force Method
// gcd(12, 9)
// ----------------------------
int calcGCD(int n, int m) {
    int gcd = 1;

    for (int i = 1; i <= min(n, m); i++) {
        if (n % i == 0 && m % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}
*/

/*
// -----------------------------------------
// Method 2: Reverse Loop (Optimized Brute)
// gcd(20, 40)
// -----------------------------------------
int calcGCD(int n, int m) {

    for (int i = min(n, m); i >= 1; i--) {
        if (n % i == 0 && m % i == 0) {
            return i;
        }
    }
}
*/

// -----------------------------------------
// Method 3: Euclidean Algorithm (Fastest)
// -----------------------------------------
int calcGCD(int n, int m) {

    while (n > 0 && m > 0) {

        if (n > m) {
            n = n % m;
        }
        else {
            m = m % n;
        }
    }

    if (n == 0) return m;
    return n;
}

int main() {

    int n, m;
    cout << "Enter two numbers: ";
    cin >> n >> m;

    int gcd = calcGCD(n, m);  // using active function
    cout << gcd;

    return 0;
}