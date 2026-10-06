/*
56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.


Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> BruteMerge(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    if (n <= 1)
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        if (!result.empty() && intervals[i][1] <= result.back()[1])
        {
            continue;
        }

        int start = intervals[i][0];
        int end = intervals[i][1];

        int j = i + 1;
        while (j < n && intervals[j][0] <= end)
        {
            end = max(end, intervals[j][1]);
            j++;
        }

        result.push_back({start, end});
        i = j - 1;
    }

    return result;
}

vector<vector<int>> OptimalMerge(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    if (n <= 1)
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        if (result.empty() || result.back()[1] < intervals[i][0])
        {
            result.push_back(intervals[i]);
        }
        else
        {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result1 = BruteMerge(intervals);

    cout << "BRUTE: Merged intervals: ";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << "[" << result1[i][0] << ", " << result1[i][1] << "] ";
    }
    cout << endl;

    vector<vector<int>> result2 = OptimalMerge(intervals);

    cout << "OPTIMAL: Merged intervals: ";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << "[" << result2[i][0] << ", " << result2[i][1] << "] ";
    }
    cout << endl;

    return 0;
}