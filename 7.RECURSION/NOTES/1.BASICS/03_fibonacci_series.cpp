/*
Write a program and recurrence relation to find the Fibonacci series of n where n >= 0. 

Mathematical Equation:  
n if n == 0, n == 1;      
fib(n) = fib(n-1) + fib(n-2) otherwise;

Recurrence Relation: 
T(n) = T(n-1) + T(n-2) + O(1)
*/

#include <iostream>
using namespace std;

int fib(int n) {
    // base condition 1
    if(n == 0)  return 0;
    // base condition 2
    if(n == 1 || n == 2)    return 1;

    return (fib(n-1) + fib(n-2));
}

int main() {
    int n = 5;

    cout << "The fibonacci series of n is: ";
    for(int i = 0; i <= n; i++) {
        cout << fib(i) << " ";
    }

    return 0;
}