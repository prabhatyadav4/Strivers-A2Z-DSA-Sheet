/*
Question:
Given an array of integers called nums, sort the array in non-decreasing order
using the Quick Sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is
greater than or equal to all preceding elements in the array.

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
    // Partition function to place pivot at correct position
    int partition(vector<int> &arr, int st, int end) {
        int idx = st - 1;        // Index for smaller elements
        int pivot = arr[end];   // Choose last element as pivot

        for (int j = st; j < end; j++) {
            if (arr[j] <= pivot) {
                idx++;
                swap(arr[j], arr[idx]);
            }
        }

        idx++;                       // Correct pivot position
        swap(arr[end], arr[idx]);    // Place pivot

        return idx;
    }

    // Recursive Quick Sort
    void qs(vector<int> &arr, int st, int end) {
        if (st < end) {
            int pivIdx = partition(arr, st, end);

            qs(arr, st, pivIdx - 1);   // Left subarray
            qs(arr, pivIdx + 1, end);  // Right subarray
        }
    }

    vector<int> quickSort(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {7, 4, 1, 5, 3};

    vector<int> sortedNums = obj.quickSort(nums);

    cout << "Sorted Array: ";
    for (int x : sortedNums) {
        cout << x << " ";
    }

    return 0;
}
