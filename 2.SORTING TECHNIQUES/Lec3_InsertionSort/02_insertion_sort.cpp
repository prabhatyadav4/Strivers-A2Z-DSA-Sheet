/*
Question:
Given an array of integers called nums, sort the array in non-decreasing order
using the Insertion Sort algorithm and return the sorted array.

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
    void insertion(vector<int> &arr, int n) {
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            int prev = i - 1;

            // Shift elements that are greater than curr to one position ahead
            while (prev >= 0 && arr[prev] > curr) {
                arr[prev + 1] = arr[prev];
                prev--;
            }

            // Place curr at its correct position
            arr[prev + 1] = curr;
        }
    }

    vector<int> insertionSort(vector<int>& nums) {
        insertion(nums, nums.size());
        return nums;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {7, 4, 1, 5, 3};

    vector<int> sortedNums = obj.insertionSort(nums);

    cout << "Sorted Array: ";
    for (int x : sortedNums) {
        cout << x << " ";
    }

    return 0;
}