/*
Search X in sorted array

Given a sorted array of integers nums with 0-based indexing, find the index of a specified target integer. If the target is found in the array, return its index. If the target is not found, return -1.

Example 1

Input: nums = [-1,0,3,5,9,12], target = 9

Output: 4

Explanation: The target integer 9 exists in nums and its index is 4

Example 2

Input: nums = [-1,0,3,5,9,12], target = 2

Output: -1

Explanation: The target integer 2 does not exist in nums so return -1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int BinarySearch(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = (low + high) / 2;         // int mid = low + (high - low) / 2 ----> To avoid overflow
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else    high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int low, int high, int target){
        if(low > high)  return -1;
        
        int mid = (low + high) / 2;

        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target){
            return search(nums, mid + 1, high, target);
        }
        
        return search(nums, low, mid - 1, target);
    }

    int RecursionBinarySearch(vector<int>& nums, int target){
        return search(nums, 0, nums.size() - 1, target);  
    }
};

int main() {
    Solution obj;

    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 16;

    cout << "The target integer 16 exists at index (Binary): " << obj.BinarySearch(arr, target) << endl;

    cout << "The target integer 16 exists at index (Recursion): " << obj.RecursionBinarySearch(arr, target) << endl;

    return 0;
}