/*
Maximum Subarray Sum with Subarray Printing

Problem Statement:
Given an integer array arr, find the contiguous subarray (containing at least one number)
which has the largest sum and print that subarray.
Also return the maximum sum of that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Approach Used:
Kadane’s Algorithm (Optimized approach) with index tracking.

Key Points:
- Maintain a running sum of elements.
- If the running sum becomes negative, reset it to 0.
- Track start and end indices whenever a new maximum sum is found.
- Works for arrays containing both positive and negative numbers.
- Handles edge cases such as all-negative arrays.

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input:
arr = {2, 3, -8, 7, -1, 2, 3}

Output:
Maximum Subarray: {7, -1, 2, 3}
Maximum Sum: 11
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MaxSubArrayPrint(vector<int> &arr){
    int sum = 0;                  // Current subarray sum
    int maxSum = INT_MIN;         // Maximum sum found so far

    int start = 0;                // Temporary start index
    int ansStart = 0;             // Final start index
    int ansEnd = 0;               // Final end index

    for(int i = 0; i < arr.size(); i++){
        
        // If sum becomes zero, start a new subarray
        if(sum == 0)
            start = i;

        sum += arr[i];

        // Update maximum sum and indices
        if(sum > maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        // Reset sum if it becomes negative
        if(sum < 0){
            sum = 0;
        }
    }

    // Print the subarray
    cout << "Maximum Subarray: ";
    for(int i = ansStart; i <= ansEnd; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Maximum Sum: ";

    return maxSum;
}

int main(){

    vector<int> arr = {2,3,-8,7,-1,2,3};

    cout << MaxSubArrayPrint(arr);

    return 0;
}