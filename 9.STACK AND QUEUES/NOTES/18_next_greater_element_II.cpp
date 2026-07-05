/*
503. Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

Constraints:
1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> BruteNextGreaterElementsII(vector<int> &nums, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;

            if (nums[index] > nums[i])
            {
                ans[i] = nums[index];
                break;
            }
        }
    }

    return ans;
}

vector<int> BetterNextGreaterElementsII(vector<int> &nums, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++)
    {
        int index = i % n;

        while (!st.empty() && nums[st.top()] < nums[index])
        {
            ans[st.top()] = nums[index];
            st.pop();
        }

        if (i < n)
        {
            st.push(index);
        }
    }

    return ans;
}

vector<int> OptimalNextGreaterElementsII(vector<int> &nums, int n)
{
    vector<int> ans(n, - 1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int index = i % n;

        while (!st.empty() && nums[st.top()] <= nums[index])
        {
            st.pop();
        }

        if (i < n && !st.empty())
        {
            ans[index] = nums[st.top()];
        }

        st.push(index);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int n = 4;

    vector<int> ans1 = BruteNextGreaterElementsII(arr, n);

    cout << "BRUTE: The next larger elements are: ";
    for (int res : ans1)
    {
        cout << res << " ";
    }
    cout << endl;

    vector<int> ans2 = BetterNextGreaterElementsII(arr, n);

    cout << "BETTER: The next larger elements are: ";
    for (int res : ans2)
    {
        cout << res << " ";
    }
    cout << endl;

    vector<int> ans3 = OptimalNextGreaterElementsII(arr, n);

    cout << "OPTIMAL: The next larger elements are: ";
    for (int res : ans3)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}