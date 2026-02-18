/*
Floor and Ceil in Sorted Array

Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

Example 1

Input : nums =[3, 4, 4, 7, 8, 10], x= 5

Output: 4 7

Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2

Input : nums =[3, 4, 4, 7, 8, 10], x= 8

Output: 8 8

Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;

        int floor = -1, ceil = -1; 

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == x){
                floor = nums[mid];
                ceil = nums[mid];
                return {floor, ceil};
            }

            if(nums[mid] < x) {
                floor = nums[mid];
                low = mid + 1;
            }
            else{
                ceil = nums[mid];
                high = mid - 1;
            }
        } 

        return {floor, ceil};
    }
};

int main() {
    Solution obj;

    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;

    vector<int> result = obj.getFloorAndCeil(arr, target);

    cout << "The floor and ceil value of the target are: ";
    for(auto x : result){
        cout << x << " ";
    }

    return 0;
}