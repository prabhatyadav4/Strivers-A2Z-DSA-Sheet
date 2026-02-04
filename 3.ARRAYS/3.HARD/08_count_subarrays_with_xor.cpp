/*
Count subarrays with given xor K

Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

Example 1

Input : nums = [4, 2, 2, 6, 4], k = 6

Output : 4

Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

Example 2

Input :nums = [5, 6, 7, 8, 9], k = 5

Output : 2

Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:

    int BruteSubarrayWithXorK(vector<int> &nums, int target){
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int XoR = 0;
                for(int k = i; k <= j; k++){
                    XoR ^= nums[k];
                }
                if(XoR == target)   count++;
            }
        }

        return count;
    }

    int BetterSubarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int XoR = 0;
            for(int j = i; j < n; j++){
                XoR = XoR ^ nums[j];
                if(XoR == k)    count++;
            }
        }

        return count;
    }

    int OptimalSubarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        int XoR = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        for(int i = 0; i < n; i++){
            XoR = XoR ^ nums[i];
            int required = XoR ^ k;
            count += mpp[required];
            mpp[XoR]++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4,2,2,6,4};
    int target = 6;

    cout << "Count of subarray with XoR (Brute) is: " << obj.BruteSubarrayWithXorK(arr, target);
    cout << "\nCount of subarray with XoR (Better) is: " << obj.BetterSubarraysWithXorK(arr, target); 
    cout << "\nCount of subarray with XoR (Optimal) is: " << obj.OptimalSubarraysWithXorK(arr, target); 

    return 0;
}