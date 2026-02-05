/*
Merge Overlapping Subintervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

You can return the intervals in any order.

Example 1

Input: intervals = [[1,5],[3,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Intervals [1,5] and [3,6] overlap, so they are merged into [1,6].

Example 2

Input: intervals = [[5,7],[1,3],[4,6],[8,10]]

Output: [[1,3],[4,7],[8,10]]

Explanation: Intervals [4,6] and [5,7] overlap and are merged into [4,7].
*/

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

class Solution {
    public: 

    vector<vector<int>> BruteMergeOverlap(vector<vector<int>> &nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            int start = nums[i][0];
            int end = nums[i][1];

            if(!ans.empty() && end <= ans.back()[1]){
                continue;
            }

            for(int j = i+1; j < n; j++){
                if(nums[j][0] <= end){
                    end = max(end, nums[j][1]);
                }
                else break;
            }

            ans.push_back({start, end});
        }

        return ans;
    }

    vector<vector<int>> OptimalMergeOverlap(vector<vector<int>> &intervals){
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> arr = {{1,5},{3,6},{8,10},{15,18}};

    vector<vector<int>> res1 = obj.BruteMergeOverlap(arr);
    cout << "The merged intervals (Brute) are: ";
    for (auto val : res1) {
        cout << "[" << val[0] << "," << val[1] << "] ";
    }

    vector<vector<int>> res2 = obj.OptimalMergeOverlap(arr);
    cout << "\nThe merged intervals (Optimal) are: ";
    for(auto val : res2){
        cout << "[" << val[0] << "," << val[1] << "] ";
    }

    return 0;
}