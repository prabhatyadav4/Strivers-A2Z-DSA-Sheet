/*
Swapping Two Numbers Without a Third Variable

Problem Statement: Given two integers a and b, swap them in-place using only 2 variables (without using a temporary variable).

Examples

Example 1:

Input:
 a = 5, b = 10

Output:
 a = 10, b = 5

Example 2:

Input:
 a = -100, b = -200

Output:
 a = -200, b = -100


A = A ^ B
B = A ^ B
A = A ^ B
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 5;

    cout << "Before Swap: " << a << " " << b << endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After Swap: " << a << " " << b << endl;

    return 0;
}