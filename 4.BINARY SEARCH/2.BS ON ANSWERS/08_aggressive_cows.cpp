/*
Aggressive Cows

Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

Example 1

Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

Output: 3

Explanation:

The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.

In no manner can we increase the minimum distance beyond 3.

Example 2

Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]

Output: 5

Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6]. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canWePlace(vector<int> &nums, int k, int d){
       int count = 1;
       int lastPos = nums[0];
       
       for(int i = 1; i < nums.size(); i++){
            if(nums[i] - lastPos >= d){
                count++;
                lastPos = nums[i];
            }
            if(count >= k){
                return true;
            }
       }

       return false;
    }

    int BruteAggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        int maxDist =  nums[n - 1] - nums[0];

        for(int d = 1; d <= maxDist; d++){
            if(canWePlace(nums, k, d)){
                ans = d;
            }
            else{
                return d - 1;
            }
        }

        return ans;
    }

    int OptimalAggressiveCows(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums.back() - nums.front();

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canWePlace(nums, k, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};

int main() {
    Solution obj;

    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    int result1 = obj.BruteAggressiveCows(stalls, cows);
    cout << "The maximum possible minimum distance (Brute) between any two cows will be: " << result1 << endl;

    int result2 = obj.OptimalAggressiveCows(stalls, cows);
    cout << "The maximum possible minimum distance (Optimal) between any two cows will be: " << result2 << endl;

    return 0;
}