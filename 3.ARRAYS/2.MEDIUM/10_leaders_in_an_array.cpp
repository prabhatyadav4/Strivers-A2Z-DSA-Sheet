/*
Leaders in an Array

Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

Example 1

Input: nums = [1, 2, 5, 3, 1, 2]

Output: [5, 3, 2]

Explanation:

2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]

Example 2

Input: nums = [-3, 4, 5, 1, -4, -5]

Output: [5, 1, -4, -5]

Explanation:

-5 is the rightmost element, -4 is the largest element in the index range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Brute force approach: check every element with elements to its right
    vector<int> BruteLeaders(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool leader = true;   // assume current element is a leader

            // check if any element on the right is greater
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    leader = false; // not a leader
                    break;
                }
            }

            // if still a leader, add to answer
            if (leader) {
                ans.push_back(nums[i]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    // Optimal approach: traverse from right and track maximum
    vector<int> OptimalLeaders(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        int maxi = INT_MIN; // stores maximum element seen so far from right

        // traverse array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // if current element is greater than max on right
            if (nums[i] > maxi) {
                ans.push_back(nums[i]); // current element is a leader
                maxi = nums[i];         // update maximum
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 2, 5, 3, 1, 2};
    
    cout << "The Leaders of the Array (Brute) are: ";
    for (int x : obj.BruteLeaders(arr)) {
        cout << x << " ";
    }

    cout << "\nThe Leaders of the Array (Optimal) are: ";
    for (int x : obj.OptimalLeaders(arr)) {
        cout << x << " ";
    }

    return 0;
}