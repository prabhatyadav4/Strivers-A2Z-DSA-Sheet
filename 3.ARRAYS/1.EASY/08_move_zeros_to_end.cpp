/* Move Zeros to End

Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.

This must be done in place, without making a copy of the array.

Example 1

Input: nums = [0, 1, 4, 0, 5, 2]

Output: [1, 4, 5, 2, 0, 0]

Explanation:

Both the zeroes are moved to the end and the order of the other elements stay the same

Example 2

Input: nums = [0, 0, 0, 1, 3, -2]

Output: [1, 3, -2, 0, 0, 0]

Explanation:

All 3 zeroes are moved to the end and the order of the other elements stay the same
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void moveZeroesBrute(int n, vector<int> &nums){

        vector<int> temp;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        int nz = temp.size();

        for(int i = 0; i < nz; i++){
            nums[i] = temp[i];
        }

        for(int i = nz; i < n; i++){
            nums[i] = 0;
        }

        return;
    }

    void moveZeroesOptimal(vector<int>& nums) {
        int j = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        if(j == -1) return;

        for(int i = j+1; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,5,0,6,0,9,8,0,5};
    vector<int> arr = {1,0,2,3,2,0,0,4,5,1};

    int n = nums.size();

    obj.moveZeroesBrute(n, nums);

    cout << "New Array (Brute): ";

    for(int y : nums){
        cout << y << " ";
    }

    obj.moveZeroesOptimal(arr);
    
    cout << "\nNew Array (Optimal): ";
    for(int x : arr){
        cout << x << " ";
    }


    return 0;
}