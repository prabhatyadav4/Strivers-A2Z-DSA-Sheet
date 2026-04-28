/*
Print 1 to n using Recursion

Given an integer n. Print numbers from 1 to n using recursion.

Examples:

Input: n = 3
Output: [1, 2, 3]
Explanation: We have to print numbers from 1 to 3.

Input: n = 10
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
*/

#include <iostream>
using namespace std;

void printNos(int n) {
    if(n == 0)  return;
    printNos(n-1);
    cout << n << " ";
}

int main() {
    int n = 5;
    cout << "The numbers from 1 to n are: ";
    printNos(n);
    
    return 0;
}