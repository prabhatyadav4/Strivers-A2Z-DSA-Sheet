/*
57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Two intervals are considered overlapping if they share at least one point.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.



Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> BruteInsert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);

    sort(intervals.begin(), intervals.end());

    int n = intervals.size();

    vector<vector<int>> merged;

    for (int i = 0; i < n; i++)
    {
        if (merged.empty() || merged.back()[1] < intervals[i][0])
        {
            merged.push_back(intervals[i]);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }

    return merged;
}

vector<vector<int>> OptimalInsert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();

    vector<vector<int>> result;

    int i = 0;

    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    result.push_back(newInterval);

    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result1 = BruteInsert(intervals, newInterval);

    cout << "BRUTE: Merged Intervals: ";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << "[" << result1[i][0] << ", " << result1[i][1] << "] ";
    }
    cout << endl;

    vector<vector<int>> result2 = OptimalInsert(intervals, newInterval);

    cout << "OPTIMAL: Merged Intervals: ";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << "[" << result2[i][0] << ", " << result2[i][1] << "] ";
    }
    cout << endl;

    return 0;
}