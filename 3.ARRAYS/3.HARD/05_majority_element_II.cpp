/*
Majority Element-II

Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

Example 1

Input: nums = [1, 2, 1, 1, 3, 2]

Output: [1]

Explanation:

Here, n / 3 = 6 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1]

Example 2

Input: nums = [1, 2, 1, 1, 3, 2, 2]

Output: [1, 2]

Explanation:

Here, n / 3 = 7 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1, 2]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> BruteMajorityElementTwo(vector<int>& nums) {
        vector<int> ls;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(ls.size() == 0 || ls[0] != nums[i]){
                int cnt = 0;
                for(int j = 0; j < n; j++){
                    if(nums[j] == nums[i]){
                        cnt++;
                    }
                }
                if(cnt > n/3){
                    ls.push_back(nums[i]);
                }
            }
            if(ls.size() == 2){
                break;
            }
        }
        return ls;
    }

    vector<int> BetterMajorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        unordered_map<int,int> mpp;
        int minimum = (n/3) + 1;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == minimum){
                ls.push_back(nums[i]);
            } 
            if(ls.size() == 2)  break;
        }

        return ls;
    }

    vector<int> OptimalMajorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1)    cnt1++;
            else if(nums[i] == el2)    cnt2++;
            else{
                cnt1--, cnt2--;
            }
        }

        vector<int> ls;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(el1 == nums[i])   cnt1++;
            if(el2 == nums[i])   cnt2++;
        }
        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini)     ls.push_back(el1);
        if(cnt2 >= mini)     ls.push_back(el2);

        sort(ls.begin(), ls.end());

        return ls;
    }

};

int main() {
    
    Solution obj;
    vector<int> arr = {1,1,1,3,3,2,2,2};

    vector<int> res1 = obj.BruteMajorityElementTwo(arr);
    cout << "The majority elements (Brute) are: ";
    for(auto &val : res1){
        cout << val << " ";
    }

    vector<int> res2 = obj.BetterMajorityElementTwo(arr);
    cout << "\nThe majority elements (Better) are: ";
    for(auto &val : res2){
        cout << val << " ";
    }

    vector<int> res3 = obj.OptimalMajorityElementTwo(arr);
    cout << "\nThe majority elements (Optimal) are: ";
    for(auto &val : res3){
        cout << val << " ";
    }

    return 0;
}