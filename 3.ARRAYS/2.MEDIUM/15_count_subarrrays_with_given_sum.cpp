/*
Count subarrays with given sum

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Example 1

Input: nums = [1, 1, 1], k = 2

Output: 2

Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.

Example 2

Input: nums = [1, 2, 3], k = 3

Output: 2

Explanation: In the given array [1, 2, 3], there are two subarrays that sum up to 3: [1, 2] and [3]. Hence, the output is 2.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int BruteSubarraySum(vector<int> &nums, int k){
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int x = i; x <= j; x++){
                    sum += nums[x];
                }
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }

    int BetterSubarraySum(vector<int> &nums, int k){
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;

    int bruteAns = obj.BruteSubarraySum(arr, k);
    cout << "Number of subarrays that sum up to 3: " << bruteAns;

    int betterAns = obj.BruteSubarraySum(arr, k);
    cout << "\nNumber of subarrays that sum up to 3: " << betterAns;

    return 0;
}