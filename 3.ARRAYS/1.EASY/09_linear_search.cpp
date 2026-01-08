/*
Linear Search

Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. 
If the target is not found in the array, return -1.

Example 1

Input: nums = [2, 3, 4, 5, 3], target = 3

Output: 1

Explanation:

The first occurence of 3 in nums is at index 1

Example 2

Input: nums = [2, -4, 4, 0, 10], target = 6

Output: -1

Explanation:

The value 6 does not occur in the array, hence output is -1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        //your code goes here
        for(int i = 0; i < target; i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;

    vector<int> arr = {6,7,8,4,1};
    int target = 4;

    cout << "The first occurence of " << target <<" in nums is at index " << obj.linearSearch(arr, target);

    return 0;
}