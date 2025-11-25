#include <iostream>
#include <vector>
using namespace std;

/*
Question:
Write a function printDivisors(int n, int &size) that returns all divisors
of an integer 'n' in ascending order. The function should check all numbers
from 1 to n, store the divisors in a list, convert the list into a dynamic
array, and update 'size' with the number of divisors.
*/

int* printDivisors(int n, int &size) {

    // Vector to store divisors temporarily
    vector<int> divisors;

    // Check all numbers from 1 to n
    for (int i = 1; i <= n; i++) {

        // If i divides n without remainder, it's a divisor
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }

    // Set size to number of divisors found
    size = divisors.size();

    // Create a dynamic array to return
    int* ans = new int[size];

    // Copy vector elements to the dynamic array
    for (int i = 0; i < size; i++) {
        ans[i] = divisors[i];
    }

    // Return the dynamic array
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int size = 0;

    // Call the function to get divisors
    int* divisors = printDivisors(n, size);

    // Print divisors
    cout << "Divisors of " << n << ": ";
    for (int i = 0; i < size; i++) {
        cout << divisors[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] divisors;

    return 0;
}