/*
Question:
Given an array of integers called nums, sort the array in non-decreasing order
using the Bubble Sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is
greater than or equal to all preceding elements.

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
    void bubble(vector<int> &arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            bool isSwap = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    isSwap = true;
                }
            }
            // If no elements were swapped, array is already sorted
            if (!isSwap) {
                return;
            }
        }
    }

    vector<int> bubbleSort(vector<int>& nums) {
        bubble(nums, nums.size());
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