/*
133. N meetings in one room

Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time. A meeting starting at the same time another meeting ends is considered overlapping.

Example 1:
Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]

Output : 4

Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).

Example 2:
Input : Start = [10, 12, 20] , End = [20, 25, 30]

Output : 1

Explanation : Given the start and end time, only one meeting can be held in meeting room.

Constraints:
1 <= N <= 105
0 <= start[i] < end[i] <= 105
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMeetings1(const vector<int> &start, const vector<int> &end)
{
    int n = start.size();

    vector<pair<int, int>> meetings(n);

    for (int i = 0; i < n; i++)
    {
        meetings[i] = {end[i], start[i]};
    }

    sort(meetings.begin(), meetings.end());

    int lastEndTime = -1;

    int count = 0;

    for (const auto &meeting : meetings)
    {
        int currentEnd = meeting.first;
        int currentStart = meeting.second;

        if (currentStart > lastEndTime)
        {
            count++;
            lastEndTime = currentEnd;
        }
    }

    return count;
}

/*
Examples:

Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9]
Output: [1, 2, 4, 5]
Explanation: We can attend the 1st meeting from (1 to 2),
then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7),
and the last meeting we can attend is the 5th from (8 to 9).
It can be shown that this is the maximum number of meetings we can attend.
*/

struct Meeting
{
    int start;
    int end;
    int pos;
};

static bool comp(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

vector<int> maxMeetings2(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Meeting> meetings(n);

    for (int i = 0; i < n; i++)
    {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }

    sort(meetings.begin(), meetings.end(), comp);

    vector<int> result;
    int lastEndTime = -1;

    for (int i = 0; i < n; i++)
    {
        if (meetings[i].start > lastEndTime)
        {
            result.push_back(meetings[i].pos);
            lastEndTime = meetings[i].end;
        }
    }

    sort(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "EASY: The maximum number of meetings are: " << maxMeetings1(start, end) << endl;

    vector<int> result = maxMeetings2(start, end);

    cout << "HARD: The maximum number of meetings are: [ ";

    for (auto ans : result)
    {
        cout << ans << " ";
    }

    cout << "]";

    return 0;
}