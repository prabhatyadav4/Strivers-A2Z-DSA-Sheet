/*
Second smallest Element

Given an array of integers nums, return the second-smallest element in the array. If the second-smallest element does not exist, return -1.

Example 1

Input: nums = [8, 8, 7, 6, 5]

Output: 7

Explanation:

The smallest value in nums is 8, the second smallest is 7

Example 2

Input: nums = [10, 10, 10, 10, 10]

Output: -1

Explanation:

The only value in nums is 10, so there is no second smallest value, thus -1 is returned
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int secondSmallestElement(vector<int>& nums) {
        //your code goes here
        if(nums.size() < 2) return -1;
        int smallest = INT_MAX;
        int ssmallest = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < smallest){
                ssmallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] != smallest && nums[i] < ssmallest){
                ssmallest = nums[i];
            }
        }

        if(ssmallest == INT_MAX) return -1;
        return ssmallest;
    }
};

int main(){

    Solution obj;

    vector<int> arr = {1,2,4,7,7,5};

    cout << "Second Smallest Element: " << obj.secondSmallestElement(arr);

    return 0;
    
}