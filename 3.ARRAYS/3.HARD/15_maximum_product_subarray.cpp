/*
Maximum Product Subarray in an Array

Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1

Input: nums = [4, 5, 3, 7, 1, 2]

Output: 840

Explanation:

The largest product is given by the whole array itself

Example 2

Input: nums = [-5, 0, -2]

Output: 0

Explanation:

The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int BruteMaxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = i; j <= n; j++){
                int product = 1; 
                for(int k = i; k < j; k++){
                    product = product * nums[k];
                }
                maximum = max(maximum, product);
            }
        }

        return maximum;
    }

    int BetterMaxProduct(vector<int>& nums){
        int n = nums.size();
        int maximum = INT_MIN;

        for(int i = 0; i < n; i++){
            int product = 1; 
            for(int j = i; j < n; j++){
                product = product * nums[j];
                maximum = max(maximum, product);
            }
        }

        return maximum;
    }

    int OptimalMaxProduct(vector<int>& nums){
        int n = nums.size();
        int pre = 1, suff = 1;
        int maximum = INT_MIN;

        for(int i = 0; i < n; i++){
            if(pre == 0)    pre = 1;
            if(suff == 0)   suff = 1;

            pre *= nums[i];
            suff *= nums[n-i-1];

            maximum = max(maximum, max(suff, pre));
        }

        return maximum;
    }

    int OptimalKadaneMaxProduct(vector<int>& nums) {
    int maxi = nums[0];
    int mini = nums[0];
    int ans = nums[0];

    for(int i = 1; i < nums.size(); i++) {

        if(nums[i] < 0)
            swap(maxi, mini);

        maxi = max(nums[i], maxi * nums[i]);
        mini = min(nums[i], mini * nums[i]);

        ans = max(ans, maxi);
    }

    return ans;
}

};

int main() {
    Solution obj;

    vector<int> arr = {2, 3, -2, 4};

    int result1 = obj.BruteMaxProduct(arr);

    cout << "The largest product of subarray (Brute) is: " << result1 << endl;

    int result2 = obj.BetterMaxProduct(arr);

    cout << "The largest product of subarray (Better) is: " << result2 << endl;

    int result3 = obj.OptimalMaxProduct(arr);

    cout << "The largest product of subarray (Optimal) is: " << result3 << endl;

    int result4 = obj.OptimalKadaneMaxProduct(arr);

    cout << "The largest product of subarray (Optimal) is: " << result4 << endl;

    return 0;
}