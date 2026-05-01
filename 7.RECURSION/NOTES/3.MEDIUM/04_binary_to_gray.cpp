/*
Binary to Gray code using recursion

Given the Binary code of a number as a decimal number, we need to convert this into its equivalent Gray Code. Assume that the binary number is in the range of integers. For the larger value, we can take a binary number as string.

Note: In Gray Code, two consecutive bits differ by exactly one bit. The most significant bit (MSB) of the Gray Code is always the same as the MSB of the binary number.

Examples: 

Input: 1001 
Output: 1101
Explanation: The Gray Code for binary 1001 is 1101.

Input: 11
Output: 10
Explanation: The Gray Code for binary 11 is 10.
*/

// Naive Approach [TC -> O(1) and SC -> O(1)]

#include <iostream>
using namespace std;

char xorChar(char a, char b) {
    return (a == b) ? '0' : '1';
}

string binaryToGray(string binary) {
    string gray = "";
    gray += binary[0];

    for(int i = 1; i < binary.length(); i++) {
        gray += xorChar(binary[i - 1], binary[i]);
    }

    return gray;
}

// Recursion Approach [TC -> O(log10(n)) and SC -> O(log10(n))]

int binaryToGrayRec(int n) {
    if(!n)  return 0;

    // last element
    int a = n % 10;
    // secondlast element
    int b = (n / 10) % 10;

    if((a && !b) || (!a && b)) {
        return (1 + 10 * binaryToGrayRec(n / 10));
    }

    return (10 * binaryToGrayRec(n / 10));
}

int main() {
    string number = "101110";
    cout << "Naive: The number from Binary to Gray is: " << binaryToGray(number);
    
    int binary_number = 1011100;
    cout << "\nRecursion: The number from Binary to Gray is: " << binaryToGrayRec(binary_number);

    return 0;
}