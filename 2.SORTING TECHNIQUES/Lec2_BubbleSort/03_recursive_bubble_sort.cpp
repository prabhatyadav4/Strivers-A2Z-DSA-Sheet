/*
Question:
Given an array of integers nums, sort the array in non-decreasing order
using the recursive Bubble Sort algorithm, and return the sorted array.

You must implement Bubble Sort using recursion only.
Do not use built-in sorting functions (sort, sorted, Arrays.sort, etc.).

A sorted array in non-decreasing order is an array where each element is
greater than or equal to the previous one.

Example 1:
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]

Example 2:
Input: nums = [5, 4, 4, 1, 1]
Output: [1, 1, 4, 4, 5]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bubbleRec(vector<int> &arr, int n) {
        // Base case
        if (n == 1) {
            return;
        }

        // One pass of bubble sort
        for (int i = 0; i <= n - 2; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }

        // Recursive call for remaining array
        bubbleRec(arr, n - 1);
    }

    vector<int> bubbleSort(vector<int>& nums) {
        bubbleRec(nums, nums.size());
        return nums;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {7, 4, 1, 5, 3};

    vector<int> sortedNums = obj.bubbleSort(nums);

    cout << "Sorted Array: ";
    for (int x : sortedNums) {
        cout << x << " ";
    }

    return 0;
}