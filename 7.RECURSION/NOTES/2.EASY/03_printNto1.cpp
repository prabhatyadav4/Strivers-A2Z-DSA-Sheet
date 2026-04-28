/*
Print n to 1 using Recursion

Given an integer n. Print numbers from n to 1 using recursion.

Examples:

Input: n = 3
Output: [3, 2, 1]
Explanation: Print numbers in reverse order from n down to 1.

Input: n = 10
Output: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Explanation: Print numbers in reverse order from n down to 1.
*/

#include <iostream>
using namespace std;

void printNos(int n) {
    if(n == 0)  return;
    cout << n << " ";
    printNos(n - 1);
}

int main() {
    int n = 5;
    cout << "The numbers from n to 1 are: ";
    printNos(n);

    return 0;
}