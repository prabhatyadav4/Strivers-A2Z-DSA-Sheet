/*
4 Sum

Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

a, b, c, d are all distinct valid indices of nums.

nums[a] + nums[b] + nums[c] + nums[d] == target.

Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.

Example 1

Input: nums = [1, -2, 3, 5, 7, 9], target = 7

Output: [[-2, 1, 3, 5]]

Explanation:

nums[1] + nums[0] + nums[2] + nums[3] = 7

Example 2

Input: nums = [7, -7, 1, 2, 14, 3], target = 9

Output: []

Explanation:

No quadruplets are present which add upto 9
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> bruteFourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    for(int l = k+1; l < n; l++){
                        long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                        if(sum == target){
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    vector<vector<int>> betterFourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                set<long long> hashset;
                for(int k = j+1; k < n; k++){
                    long long sum = nums[i] + nums[j] + nums[k];
                    long long fourth = target - (sum);
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    vector<vector<int>> optimalFourSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])   continue;
            for(int j = i+1; j < n; j++){
                if(j > (i+1) && nums[j] == nums[j-1])   continue;
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++, l--;
                        while(k < l && nums[k] == nums[k-1])    k++;
                        while(k < l && nums[l] == nums[l+1])    l--;
                    }
                    else if(sum < target)   k++;
                    else   l--;
                }
            }
        }

        return ans;
    }

};

int main() {
    Solution obj;

    vector<int> arr = {-1,0,1,2,-1,-4,-2,-2};

    vector<vector<int>> res1 = obj.bruteFourSum(arr, 0);
    cout << "The Four Elements (Brute) are: " << endl;;
    for(auto &row : res1){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> res2 = obj.betterFourSum(arr, 0);
    cout << "\nThe Four Elements (Better) are: " << endl;
    for(auto &row : res2){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> res3 = obj.optimalFourSum(arr, 0);
    cout << "\nThe Four Elements (Optimal) are: " << endl;
    for(auto &row : res3){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}