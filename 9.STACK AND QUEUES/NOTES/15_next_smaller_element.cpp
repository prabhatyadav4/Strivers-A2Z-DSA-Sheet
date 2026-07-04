/*
Next Smaller Element

You are given an integer array arr[ ]. For every element in the array, your task is to determine its Next Smaller Element (NSE).

The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x.

If no such element exists, assign -1 as the NSE for that position.

Examples:

Input: arr[] = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation:
The first element smaller than 4 having index > 0 is 2.
The first element smaller than 8 having index > 1 is 5.
The first element smaller than 5 having index > 2 is 2.
There are no elements smaller than 4 having index > 3.
There are no elements smaller than 4 having index > 4.

Input: arr[] = [13, 7, 6, 12]
Output: [7, 6, -1, -1]
Explanation:
The first element smaller than 13 having index > 0 is 7.
The first element smaller than 7 having index > 1 is 6.
There are no elements smaller than 6 having index > 2.
There are no elements smaller than 12 having index > 3.

Input: arr[] = [4, 1]
Output: [1, -1]
Explanation: 4 will be updated to 1 and 1 will be updated to -1.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> BruteNextSmallerElement(vector<int> &arr, int n)
{

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

vector<int> BetterNextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && ans[st.top()] > arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

vector<int> OptimalNextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && ans[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = 5;

    vector<int> ans1 = BruteNextSmallerElement(arr, n);

    cout << "BRUTE: The next smaller elements are: ";
    for (int res : ans1)
    {
        cout << res << " ";
    }
    cout << endl;

    vector<int> ans2 = BruteNextSmallerElement(arr, n);

    cout << "BETTER: The next smaller elements are: ";
    for (int res : ans2)
    {
        cout << res << " ";
    }
    cout << endl;

    vector<int> ans3 = BruteNextSmallerElement(arr, n);

    cout << "OPTIMAL: The next smaller elements are: ";
    for (int res : ans3)
    {
        cout << res << " ";
    }
    cout << endl;
}