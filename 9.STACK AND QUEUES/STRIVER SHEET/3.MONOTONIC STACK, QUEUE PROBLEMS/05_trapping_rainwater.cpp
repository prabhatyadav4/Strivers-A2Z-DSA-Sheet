/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 1. Left Max & Right Max

int BruteTrap(vector<int> height)
{
    int n = height.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int lmax = 0;
        int rmax = 0;

        for (int j = 0; j <= i; j++)
        {
            lmax = max(lmax, height[j]);
        }

        for (int j = i; j < n; j++)
        {
            rmax = max(rmax, height[j]);
        }

        ans += min(lmax, rmax) - height[i];
    }

    return ans;
}

// Complexity->     Time: O(N²)     Space: O(1)

// 2. Prefix & Suffix Arrays

int BetterTrap(vector<int> height)
{
    int n = height.size();
    int ans = 0;

    vector<int> lmax(n);
    vector<int> rmax(n);

    lmax[0] = height[0];

    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], height[i]);
    }

    rmax[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], height[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

// Complexity->     Time: O(N)      Space: O(N)

// 3.Two Pointer

int OptimalTrap(vector<int> height)
{
    int n = height.size();
    int ans = 0;
    int l = 0;
    int r = n - 1;
    int lmax = 0;
    int rmax = 0;

    while (l < r)
    {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);

        if (lmax < rmax)
        {
            ans += lmax - height[l];
            l++;
        }
        else
        {
            ans += rmax - height[r];
            r--;
        }
    }

    return ans;
}

// Complexity->     Time: O(N)      Space: O(1)

// 4. Monotonic Stack

int StackTrap(vector<int> height)
{
    int n = height.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && height[i] > height[st.top()])
        {
            int mid = st.top();
            st.pop();

            if (st.empty())
            {
                break;
            }

            int left = st.top();

            int width = i - left - 1;

            int boundedHeight = min(height[left], height[i]) - height[mid];

            ans += width * boundedHeight;
        }

        st.push(i);
    }

    return ans;
}

// Complexity->     Time: O(N)      Space: O(N)

int main()
{
    vector<int> height1 = {
        0, 1, 0, 2, 1, 0,
        1, 3, 2, 1, 2, 1};

    vector<int> height2 = {
        4, 2, 0, 3, 2, 5};

    cout << "Example 1:" << endl;

    cout << "Brute Force      : "
         << BruteTrap(height1) << endl;

    cout << "Prefix + Suffix  : "
         << BetterTrap(height1) << endl;

    cout << "Two Pointer      : "
         << OptimalTrap(height1) << endl;

    cout << "Monotonic Stack  : "
         << StackTrap(height1) << endl;

    cout << "\nExample 2:" << endl;

    cout << "Brute Force      : "
         << BruteTrap(height2) << endl;

    cout << "Prefix + Suffix  : "
         << BetterTrap(height2) << endl;

    cout << "Two Pointer      : "
         << OptimalTrap(height2) << endl;

    cout << "Monotonic Stack  : "
         << StackTrap(height2) << endl;

    return 0;
}