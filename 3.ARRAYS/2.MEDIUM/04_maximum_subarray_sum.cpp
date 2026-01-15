/*
Maximum Subarray Sum

Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.



A subarray is a contiguous non-empty sequence of elements within an array.


Example 1

Input: nums = [2, 3, 5, -2, 7, -4]

Output: 15

Explanation:

The subarray from index 0 to index 4 has the largest sum = 15

Example 2

Input: nums = [-2, -3, -7, -2, -10, -4]

Output: -2

Explanation:

The element on index 0 or index 3 make up the largest sum when taken as a subarray
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>   // For INT_MIN
using namespace std;

class Solution {
public: 

    // O(N^3) Brute Force approach
    int BruteMaxSubArray(vector<int> &arr){
        int n = arr.size();
        int maxSum = INT_MIN;

        // Fix starting index
        for(int i = 0; i < n; i++){
            // Fix ending index
            for(int j = i; j < n; j++){
                int sum = 0;
                // Calculate sum of subarray [i..j]
                for(int k = i; k <= j; k++){
                    sum += arr[k];
                }
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // O(N^2) Improved approach
    int BetterMaxSubArray(vector<int> &arr){
        int n = arr.size();
        int maxSum = INT_MIN;

        for(int i = 0; i < n; i++){
            int sum = 0;
            // Extend subarray from i to j
            for(int j = i; j < n; j++){
                sum += arr[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // O(N) Kadane's Algorithm
    int OptimalMaxSubArray(vector<int> &arr){
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];

            if(sum > maxSum){
                maxSum = sum;
            }

            // Reset sum if it becomes negative
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
}; 

int main(){
    Solution obj;
    vector<int> arr = {2,3,-8,7,-1,2,3};

    cout << "Maximum Sub Array (Brute): "
         << obj.BruteMaxSubArray(arr);

    cout << "\nMaximum Sub Array (Better): "
         << obj.BetterMaxSubArray(arr);

    cout << "\nMaximum Sub Array (Optimal): "
         << obj.OptimalMaxSubArray(arr);

    return 0;
}