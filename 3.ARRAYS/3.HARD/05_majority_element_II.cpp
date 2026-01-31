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
using namespace std;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
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
};

int main() {
    
    Solution obj;
    vector<int> arr = {1,1,1,3,3,2,2,2};

    vector<int> res = obj.majorityElementTwo(arr);
    cout << "The majority elements are: ";
    for(auto &val : res){
        cout << val << " ";
    }

    return 0;
}