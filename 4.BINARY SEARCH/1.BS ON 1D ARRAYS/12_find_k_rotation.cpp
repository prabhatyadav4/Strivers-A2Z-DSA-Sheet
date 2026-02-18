/*
Find out how many times the array is rotated

Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

Example 1

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

Output: 4

Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

Example 2

Input: nums = [3, 4, 5, 1, 2]

Output: 3

Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    int BruteFindKRotation(vector<int> &nums){
        int n = nums.size();
        int ans = nums[0];
        int index = -1;

        for(int i = 1; i < n; i++){
            if(nums[i] < ans){
                ans = nums[i];
                index = i;
            }
        }

        return index;
    }

    int BetterFindKRotation(vector<int> &nums){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i + 1]){
                return i + 1;
            }
        }

        return 0;
    }

    int OptimalFindKRotation(vector<int> &nums){
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            if(nums[low] <= nums[high]){
                return low;
            }
            int mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }

        return low;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int result1 = obj.BruteFindKRotation(arr);
    cout << "The number of rotations (Brute) is: " << result1 << endl;

    int result2 = obj.BruteFindKRotation(arr);
    cout << "The number of rotations (Better) is: " << result2 << endl;

    int result3 = obj.OptimalFindKRotation(arr);
    cout << "The number of rotations (Optimal) is: " << result3 << endl;

    return 0;
}