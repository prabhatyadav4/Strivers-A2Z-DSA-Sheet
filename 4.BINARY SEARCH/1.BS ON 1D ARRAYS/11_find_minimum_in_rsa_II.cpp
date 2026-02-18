/*
Find minimum in Rotated Sorted Array II

Given an integer array nums of size N, sorted in ascending order with duplicate values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.

Example 1

Input : nums = [4, 4, 5, 5, 6, 7, 0, 1, 2, 3]

Output: 0

Explanation: Here, the element 0 is the minimum element in the array.

Example 2

Input : nums = [3, 4, 5, 5, 1, 2]

Output: 1

Explanation:Here, the element 1 is the minimum element in the array.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    
    int BruteFindMinII(vector<int> &nums){
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            ans = min(ans, nums[i]);
        }

        return ans;
    }

    int OptimalFindMinII(vector<int> &nums)  {
      int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        while(low <= high){
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
            }
            int mid = low + (high - low) / 2;
            ans = min(ans, nums[mid]);
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++, high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4, 4, 5, 5, 6, 7, 1, 2};

    int result1 = obj.BruteFindMinII(nums);
    cout << "Minimum element (Brute) is: " << result1 << endl;

    int result2 = obj.OptimalFindMinII(nums);
    cout << "Minimum element (Optimal) is: " << result1 << endl;

    return 0;
}