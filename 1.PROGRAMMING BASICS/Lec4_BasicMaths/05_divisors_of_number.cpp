#include <bits/stdc++.h>
using namespace std;

/*
Question:
Write a function printDivisors(int n, int &size) that returns all divisors
of an integer 'n' in ascending order. The function should check all numbers
from 1 to n, store the divisors in a list, convert the list into a dynamic
array, and update 'size' with the number of divisors.
*/

/* int* printDivisors(int n, int &size) {

    // Vector to store divisors temporarily
    vector<int> divisors;

    // Check all numbers from 1 to n
    for (int i = 1; i*i <= n; i++) {

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
} */


// Function to print divisors of a number
void printDivisors(int n){
    vector <int> ls; // Vector to store divisors
    // Loop from 1 to sqrt(n)
    for(int i = 1; i <= sqrt(n); i++){
        // If i divides n
        if(n % i == 0){
            ls.push_back(i); // Add i to divisors
            // If n/i is not equal to i, add n/i to divisors
            if(n/i != i){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(), ls.end()); // Sort the divisors in ascending order
    // Print the divisors
    for(auto it : ls){
        cout << it << " ";
    }
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printDivisors(n); // Call the function to print divisors

    return 0;
}