/*
Sum of Array

Given an array of integers arr[], find the sum of its elements.

Examples:

Input : arr[] = [1, 2, 3]
Output : 6
Explanation: 1 + 2 + 3 = 6

Input : arr[] = [15, 12, 13, 10]
Output : 50
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Iterative Solution - O(n) Time and O(1) Space
int iterativeSumOfArray(vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    return sum;
}

// Recursive Solution - O(n) Time and O(n) Space
int recursiveSumOfArray(vector<int> &arr, int n) {
    if(n == 0)  return 0;
    return arr[n - 1] + recursiveSumOfArray(arr, n - 1);
}

// Inbuilt Methods - O(n) Time and O(1) Space
int inbuiltSumOfArray(vector<int> &arr) {
    return accumulate(arr.begin(), arr.end(), 0);
}

int main() {
    vector<int> arr = {12, 15, 13, 14};

    cout << "Iterative: Sum of Array is " << iterativeSumOfArray(arr) << endl;
    cout << "Recursive: Sum of Array is " << recursiveSumOfArray(arr, arr.size()) << endl;
    cout << "Inbuilt: Sum of Array is " << inbuiltSumOfArray(arr) << endl;

    return 0;
}