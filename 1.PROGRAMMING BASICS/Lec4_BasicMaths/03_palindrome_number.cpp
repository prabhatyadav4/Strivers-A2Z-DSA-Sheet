#include <iostream>
using namespace std;

/*
Question:
Write a function `isPalindrome(int x)` that checks whether a given integer `x`
is a palindrome number. A palindrome reads the same forwards and backwards.
Return true if `x` is a palindrome, otherwise false. Negative numbers and
numbers ending with zero (except 0 itself) should not be considered palindromes.
*/

class Solution { 
public:
    bool isPalindrome(int x) {

        // If x is negative OR ends with 0 but is not 0 itself, it's not a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long reversed_x = 0;   // Will store the reversed number
        int duplicate_x = x;   // Copy of original x to compare later

        // Reverse the number
        while (x != 0) {
            int lastDigit = x % 10;          // Extract last digit
            x /= 10;                          // Remove the last digit
            reversed_x = (reversed_x * 10) + lastDigit;  // Build reversed number
        }

        // Check if reversed is equal to original
        return reversed_x == duplicate_x;
    }
};

// Main function to test the above code
int main() {
    Solution obj;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (obj.isPalindrome(x)) {
        cout << x << " is a palindrome number.\n";
    } else {
        cout << x << " is NOT a palindrome number.\n";
    }

    return 0;
}