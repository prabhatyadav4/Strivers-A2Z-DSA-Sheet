/*
Given an array of integers nums,
sort the array in non-decreasing order using the Selection Sort algorithm
and return the sorted array.

A sorted array in non-decreasing order means:
each element is greater than or equal to the previous element.

Example 1:
Input: nums = [7, 4, 1, 5, 3]
Output: [1, 3, 4, 5, 7]

Example 2:
Input: nums = [5, 4, 4, 1, 1]
Output: [1, 1, 4, 4, 5]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    // Function to perform Selection Sort
    void selection(vector<int> &nums, int n) {
        for (int i = 0; i < n - 1; i++) {
            int mini = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[mini]) {
                    mini = j;
                }
            }
            swap(nums[mini], nums[i]);
        }
    }

    // Function to call selection sort
    vector<int> selectionSort(vector<int>& nums) {
        selection(nums, nums.size());
        return nums;
    }
};

int main() {
    Solution sol;

    // Input array
    vector<int> nums = {7, 4, 1, 5, 3};

    // Call selection sort
    vector<int> sortedNums = sol.selectionSort(nums);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int x : sortedNums) {
        cout << x << " ";
    }

    return 0;
}