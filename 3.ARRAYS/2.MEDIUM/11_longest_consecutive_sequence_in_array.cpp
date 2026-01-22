/*
Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Example 1

Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation:

The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output: 9

Explanation:

The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


// -------------------- BRUTE FORCE --------------------
int longestConsecutiveBrute(vector<int>& nums) {
    int n = nums.size();
    int longest = 0;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int cnt = 1;

        while (find(nums.begin(), nums.end(), x + 1) != nums.end()) {
            x = x + 1;
            cnt++;
        }

        longest = max(longest, cnt);
    }

    return longest;
}

// -------------------- BETTER (SORTING) --------------------
int longestConsecutiveBetter(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int longest = 1;
    int cnt = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) {
            cnt++;
        }
        else if (nums[i] != nums[i - 1]) {
            cnt = 1;
        }
        longest = max(longest, cnt);
    }

    return longest;
}

// -------------------- OPTIMAL (HASH SET) --------------------
int longestConsecutiveOptimal(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (auto x : st) {
        if (st.find(x - 1) == st.end()) {
            int cnt = 1;
            int curr = x;

            while (st.find(curr + 1) != st.end()) {
                curr++;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}


int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Make copies because sorting modifies array
    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;

    cout << "Brute Force Answer   : " 
         << longestConsecutiveBrute(nums1) << endl;

    cout << "Better Answer : " 
         << longestConsecutiveBetter(nums2) << endl;

    cout << "Optimal Answer: " 
         << longestConsecutiveOptimal(nums3) << endl;

    return 0;
}