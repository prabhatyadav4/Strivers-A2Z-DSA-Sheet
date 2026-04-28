/*
Sum of Natural Numbers (n=3)

Input : n = 3
Output : 6
Explanation : The sum of first 3 natural numbers is 1+2+3 = 6.

Input : n = 7
Output : 28
Explanation : The sum of first 7 natural numbers is 1+2+3+4+5+6+7 = 28.
*/

#include <iostream>
using namespace std;

int sum(int n) {
    // base condition
    if(n == 1)  return 1;

    return n + sum(n-1);
}

int main() {
    int n = 5;
    cout << "Sum of first n natural numbers is: ";
    cout << sum(n);
    
    return 0;
}