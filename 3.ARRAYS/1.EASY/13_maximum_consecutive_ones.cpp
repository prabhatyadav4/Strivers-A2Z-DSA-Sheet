/*
Maximum Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1s in the array.

A binary array is an array that contains only 0s and 1s.

Example 1

Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]

Output: 3

Explanation:

The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s

Example 2

Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]

Output: 0

Explanation: 

No 1s are present in nums, thus we return 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }

        return maxCount;
    }
};

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << "Test Case 1 Output: "
         << obj.findMaxConsecutiveOnes(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << "Test Case 2 Output: "
         << obj.findMaxConsecutiveOnes(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {0, 0, 0, 0};
    cout << "Test Case 3 Output: "
         << obj.findMaxConsecutiveOnes(nums3) << endl;

    // Test Case 4
    vector<int> nums4 = {1, 1, 1, 1, 1};
    cout << "Test Case 4 Output: "
         << obj.findMaxConsecutiveOnes(nums4) << endl;

    // Test Case 5
    vector<int> nums5 = {1};
    cout << "Test Case 5 Output: "
         << obj.findMaxConsecutiveOnes(nums5) << endl;

    // Test Case 6
    vector<int> nums6 = {};
    cout << "Test Case 6 Output: "
         << obj.findMaxConsecutiveOnes(nums6) << endl;

    return 0;
}