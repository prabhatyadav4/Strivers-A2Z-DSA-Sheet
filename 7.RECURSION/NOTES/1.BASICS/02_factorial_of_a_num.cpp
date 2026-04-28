/*
The factorial of a number n (where n >= 0) is the product of all positive integers from 1 to n. 
To compute the factorial recursively, we calculate the factorial of n by using the factorial of (n-1). 
The base case for the recursive function is when n = 0, in which case we return 1.
*/

#include <iostream>
using namespace std;

int fact(int n) {
    // base condition
    if(n == 1) return 1;

    return n * fact(n-1);
}

int main() {
    int n = 5;
    cout << "Factorial of n is: ";
    cout << fact(n);
    
    return 0;
}