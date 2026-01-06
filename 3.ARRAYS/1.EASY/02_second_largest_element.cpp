/*
Second Largest Element

Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

Example 1

Input: nums = [8, 8, 7, 6, 5]

Output: 7

Explanation:

The largest value in nums is 8, the second largest is 7

Example 2

Input: nums = [10, 10, 10, 10, 10]

Output: -1

Explanation:

The only value in nums is 10, so there is no second largest value, thus -1 is returned
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        if(nums.size() < 2) return -1;
        int largest = INT_MIN;
        int slargest = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest){
                slargest = largest;
                largest = nums[i];
            }
            else if(nums[i] < largest && nums[i] > slargest){
                slargest = nums[i];
            }
        }

        if(slargest == INT_MIN) return -1;
        return slargest;
    }
};

int main(){

    Solution obj;

    vector<int> arr = {1,2,4,7,7,5};

    cout << "Second Largest Element: " << obj.secondLargestElement(arr);

    return 0;
    
}