/*
Longest subarray with sum K

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Example 1

Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation:

The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2

Input: nums = [-3, 2, 1], k=6

Output: 0

Explanation:

There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// -------------------- Brute Force --------------------
// Time: O(n^2), Space: O(1)

int BruteLongestSubarray(vector<int>& arr, int K) {
    int n = arr.size();
    int maxLen = 0;

    // Fix starting index
    for (int i = 0; i < n; i++) {
        int sum = 0;

        // Extend subarray from i to j
        for (int j = i; j < n; j++) {
            sum += arr[j];

            // Check if current subarray sum equals K
            if (sum == K) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// -------------------- Better Solution --------------------
// Uses prefix sum + map
// Time: O(n log n), Space: O(n)
// Optimal for positive & negative numbers

int BetterLongestSubarray(vector<int>& arr, int K) {
    int n = arr.size();
    map<int, int> mp;   // Stores prefixSum -> first index
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Current prefix sum

        // Subarray from index 0 to i
        if (sum == K) {
            maxLen = max(maxLen, i + 1);
        }

        // Check if (sum - K) exists in map
        if (mp.find(sum - K) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum - K]);
        }

        // Store first occurrence of prefix sum
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxLen;
}

// -------------------- Optimal Solution --------------------
// Sliding window technique
// Time: O(n), Space: O(1)
// Works only for positive numbers


int OptimalLongestSubarray(vector<int>& arr, int K) {
    int n = arr.size();
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;

    while (right < n) {
        sum += arr[right];  // Expand window

        // Shrink window if sum exceeds K
        while (sum > K) {
            sum -= arr[left];
            left++;
        }

        // Update answer if sum equals K
        if (sum == K) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}

int main() {

    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int K = 3;

    cout << "Length of the longest sub-array (Brute) is: "
         << BruteLongestSubarray(arr, K);

    cout << "\nLength of the longest sub-array (Better) is: "
         << BetterLongestSubarray(arr, K);

    cout << "\nLength of the longest sub-array (Optimal) is: "
         << OptimalLongestSubarray(arr, K);

    return 0;
}