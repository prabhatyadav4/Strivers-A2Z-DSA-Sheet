/*
Previous Smaller Element

You are given an integer array arr[ ]. For every element in the array, your task is to determine its Previous Smaller Element (PSE).

The Previous Smaller Element (PSE) of an element x is the first element that appears to the left of x in the array and is strictly smaller than x.

Note: If no such element exists, assign -1 as the PSE for that position.

Examples:

Input: arr[] = [1, 6, 2]
Output: [-1, 1, 1]
Explanation:
For 1, there is no element on the left, so answer is -1.
For 6, previous smaller element is 1.
For 2, previous smaller element is 1.

Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, 1, -1, 0, 3, 4]
Explanation:
For 1, no element on the left, so answer is -1.
For 5, previous smaller element is 1.
For 0, no element on the left smaller than 0, so answer is -1.
For 3, previous smaller element is 0.
For 4, previous smaller element is 3.
For 5, previous smaller element is 4.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> BrutePrevSmaller(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        for (int j = i - 1; j >= 0; j--)
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

vector<int> OptimalPrevsmaller(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 0, 3, 4, 5};
    int n = 6;

    vector<int> ans1 = BrutePrevSmaller(arr, n);

    cout << "BRUTE: The previous smaller elements are: ";
    for (int res : ans1)
    {
        cout << res << " ";
    }
    cout << endl;

    vector<int> ans2 = BrutePrevSmaller(arr, n);

    cout << "OPTIMAL: The previous smaller elements are: ";
    for (int res : ans2)
    {
        cout << res << " ";
    }
    cout << endl;
}