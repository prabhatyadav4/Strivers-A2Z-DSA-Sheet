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
#include <stack>
#include <vector>
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

int BetterLargestRectangleArea(vector<int> &heights)
{

    int n = heights.size();
    vector<int> right(n);
    vector<int> left(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            right[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        right[st.top()] = n;
        st.pop();
    }

    // compute previous smaller element indices
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            left[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        left[st.top()] = -1;
        st.pop();
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }

    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int ans1 = BruteLargestRectangleArea(heights);

    cout << "BRUTE: The area of the largest rectangle in the histogram: " << ans1;

    int ans2 = BetterLargestRectangleArea(heights);

    cout << "\nBETTER: The area of the largest rectangle in the histogram: " << ans2;

    return 0;
}