/*
Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int BruteSingleNumber(vector<int> &nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count == 1) {
                return nums[i];
            }
        }
        return -1;
    }

    int BetterSingleNumber(vector<int> &nums) {

        unordered_map<int, int> freq;

        for(int x : nums){
            freq[x]++;
        }

        for(auto it : freq){
            if(it.second == 1){
                return it.first;
            }
        }

        return -1;
    }

    int OptimalSingleNumber(vector<int> &nums) {
        int xr = 0;
        for(int x : nums){
            xr ^= x;
        }
        return xr;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2,3,5,4,5,3,4};
    cout << "The single element (Brute) is : " << obj.BruteSingleNumber(arr);
    cout << "\nThe single element (Better) is : " << obj.BetterSingleNumber(arr);
    cout << "\nThe single element (Optimal) is : " << obj.OptimalSingleNumber(arr);

    return 0;
}