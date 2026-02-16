/*
Search in rotated sorted array-II

Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

Example 1

Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3

Output: True

Explanation: The element 3 is present in the array. So, the answer is True.

Example 2

Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10

Output: False

Explanation:The element 10 is not present in the array. So, the answer is False.
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    
    bool BruteSearchInARotatedSortedArrayII(vector<int>& arr, int k) {
        int n = arr.size(); 
        for (int i = 0; i < n; i++) {
            if (arr[i] == k) return true; 
        }
        return false; 
    }

    bool OptimalSearchInARotatedSortedArrayII(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++, high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

    bool result1 = obj.BruteSearchInARotatedSortedArrayII(arr, k);
    cout << "Brute: ";
    if (!result1)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    bool result2 = obj.OptimalSearchInARotatedSortedArrayII(arr, k);
    cout << "Optimal: ";
    if (!result2)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}