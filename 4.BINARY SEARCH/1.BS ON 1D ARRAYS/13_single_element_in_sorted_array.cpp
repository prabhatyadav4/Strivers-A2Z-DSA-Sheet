/*
Single element in sorted array

Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the single number in the array.

Example 1

Input :nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]

Output:4

Explanation: Only the number 4 appears once in the array.

Example 2

Input : nums = [1, 1, 3, 5, 5]

Output:3

Explanation: Only the number 3 appears once in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BruteSingleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(nums[i] != nums[i + 1])  return nums[i];
            }
            else if(i == n - 1){
                if(nums[i] != nums[i - 1])  return nums[i];
            }
            else{
                if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]){
                    return nums[i];
                }
            }
        }
 
        return -1;
    }

    int BetterSingleNonDuplicate(vector<int> &nums){
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }

    int Optimal1SingleNonDuplicate(vector<int> &nums){
        int n = nums.size();

        if(n == 1)  return nums[0];
        if(nums[0] != nums[1])  return nums[0];
        if(nums[n - 1] != nums[n - 2])  return nums[n - 1];

        int low = 1, high = n - 2;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            if(mid % 2 == 1 && nums[mid] == nums[mid - 1] || mid % 2 == 0 && nums[mid] == nums[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return -1;
    }

    int Optimal2SingleNonDuplicate(vector<int> &nums){
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(mid % 2 == 1)    mid--;
            if(nums[mid] == nums[mid + 1])  low = mid + 2;
            else    high = mid;
        }

        return nums[low];
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    int result1 = obj.BruteSingleNonDuplicate(arr);
    cout << "The single element (Brute) is: " << result1 << endl;

    int result2 = obj.BetterSingleNonDuplicate(arr);
    cout << "The single element (Better) is: " << result2 << endl;

    int result3 = obj.Optimal1SingleNonDuplicate(arr);
    cout << "The single element (Optimal1) is: " << result3 << endl;

    int result4 = obj.Optimal2SingleNonDuplicate(arr);
    cout << "The single element (Optimal2) is: " << result4 << endl;

    return 0;
}