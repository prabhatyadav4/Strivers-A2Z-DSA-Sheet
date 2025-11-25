#include <iostream>
#include <cmath>
using namespace std;

/*
Question:
Write a function checkArmstrong(int n) that determines whether the integer 'n'
is an Armstrong number. A 'k'-digit number is called Armstrong if the sum of its
digits raised to the k-th power is equal to the number itself.
*/

bool checkArmstrong(int n) {

    int k = to_string(n).length();  // Count digits
    int duplicate_n = n;            // Store original number
    int sum = 0;                    // Will store sum of powered digits

    // Compute sum of digits raised to k-th power
    while (n != 0) {
        int ld = n % 10;           // Last digit
        sum += pow(ld, k);         // ld^k
        n /= 10;                   // Remove last digit
    }

    // Check if Armstrong
    return sum == duplicate_n;
}

// Main function to test Armstrong checker
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (checkArmstrong(n)) {
        cout << n << " is an Armstrong number.\n";
    } else {
        cout << n << " is NOT an Armstrong number.\n";
    }

    return 0;
}


// Only for 3-digit Armstrong numbers like 153, 371, 407)
// bool checkArmstrong(int n) {
//     int sum = 0;
//     int duplicate_n = n;

//     while (n != 0) {
//         int ld = n % 10;
//         sum += ld * ld * ld;   // Only correct for 3-digit Armstrong numbers
//         n /= 10;
//     }

//     return sum == duplicate_n;
// }