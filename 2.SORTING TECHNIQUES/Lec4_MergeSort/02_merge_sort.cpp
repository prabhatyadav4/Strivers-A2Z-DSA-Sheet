/*
Question:
Given an array of integers nums, sort the array in non-decreasing order
using the Merge Sort algorithm and return the sorted array.

A sorted array in non-decreasing order is one in which each element is
greater than or equal to all the elements to its left in the array.

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
    // Merge two sorted halves of the array
    void merge(vector<int> &arr, int st, int mid, int end) {
        vector<int> temp;
        int i = st;
        int j = mid + 1;

        // Compare and merge
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        // Copy remaining elements from left half
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        // Copy remaining elements from right half
        while (j <= end) {
            temp.push_back(arr[j++]);
        }

        // Copy merged elements back to original array
        for (int idx = 0; idx < temp.size(); idx++) {
            arr[st + idx] = temp[idx];
        }
    }

    // Recursive merge sort function
    void mergeS(vector<int> &arr, int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;

            mergeS(arr, st, mid);
            mergeS(arr, mid + 1, end);
            merge(arr, st, mid, end);
        }
    }

    vector<int> mergeSort(vector<int>& nums) {
        mergeS(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {7, 4, 1, 5, 3};

    vector<int> sortedNums = obj.mergeSort(nums);

    cout << "Sorted Array: ";
    for (int x : sortedNums) {
        cout << x << " ";
    }

    return 0;
}