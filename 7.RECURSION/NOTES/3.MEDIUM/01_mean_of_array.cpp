/*
Mean of an Array

Given an unsorted array arr[], the task is to find the mean of the array.

Note: Return the floor value of the mean.

Examples:
Input: arr[] = [1, 3, 4, 2, 6, 5, 8, 7]
Output: 4
Explanation: Sum of the elements is 1 + 3 + 4 + 2 + 6 + 5 + 8 + 7 = 36, Mean = 36/8 = 4.5. Floor(4.5) = 4.

Input: arr[] = [4, 4, 4, 4, 4]
Output: 4
Explanation: Sum of the elements is 4 + 4 + 4 + 4 + 4 = 20, Mean = 20/5 = 4

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106
*/

#include <iostream>
#include <vector>
using namespace std;

double findMean(vector<int> &arr, int n) {
    if(n == 1)  return arr[0];
    return (findMean(arr, n - 1) * (n - 1) + arr[n - 1]) / n;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "The mean of the array is: " << findMean(arr, arr.size());
    
    return 0;
}