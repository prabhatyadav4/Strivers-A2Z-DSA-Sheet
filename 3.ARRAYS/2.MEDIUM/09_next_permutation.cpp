/*
Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:

[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integers.

More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.



If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).



You must rearrange the numbers in-place and use only constant extra memory.


Example 1

Input: nums = [1,2,3]

Output: [1,3,2]

Explanation:

The next permutation of [1,2,3] is [1,3,2].

Example 2

Input: nums = [3,2,1]

Output: [1,2,3]

Explanation:

[3,2,1] is the last permutation. So we return the first: [1,2,3].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:

    // 1. Brute Force Approach
    
    /*
        Steps: 
        1. generate all permutations
        2. sort all permutations
        3. find current permutation
        4. return next permutation
    */

    // 2. Better Approach

    void BetterNextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }

    // 3. Optimal Approach

    void OptimalNextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: Find the break point
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                index = i;
                break;
            }
        }

        // If no break point, reverse whole array
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find element just greater than nums[index]
        for(int i = n - 1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 3: Reverse right half
        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {2,4,1,7,5,0};
    vector<int> arr2 = arr1;

    obj.BetterNextPermutation(arr1);
    cout << "The Next Lexicographically arrangement (Better) is: ";
    for(int x : arr1){
        cout << x << " ";
    }

    obj.OptimalNextPermutation(arr2);
    cout << "\nThe Next Lexicographically arrangement (Optimal) is: ";
    for(int x : arr2){
        cout << x << " ";
    }

    return 0;
}