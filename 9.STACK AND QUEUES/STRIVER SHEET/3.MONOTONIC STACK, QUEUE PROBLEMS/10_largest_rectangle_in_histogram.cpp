/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4


Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int BruteLargestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {

        int minHeight = INT_MAX;

        for (int j = i; j < n; j++)
        {
            minHeight = min(minHeight, heights[j]);
            int width = j - i + 1;
            int area = minHeight * width;
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int OptimalLargestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        right[i] = (st.empty() ? n : st.top());

        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && heights[st.top()] > heights[i])
        {
            st.pop();
        }

        left[i] = (st.empty() ? -1 : st.top());

        st.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }

    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};

    int ans1 = BruteLargestRectangleArea(heights);
    cout << "BRUTE: The largest area in the histogram is: " << ans1 << endl;

    int ans2 = OptimalLargestRectangleArea(heights);
    cout << "OPTIMAL: The largest area in the histogram is: " << ans2 << endl;

    return 0;
}