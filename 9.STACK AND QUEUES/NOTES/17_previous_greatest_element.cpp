/*
Previous Greater Element (PGE)

You are given an integer array arr[].
For every element in the array, find its Previous Greater Element (PGE).

The Previous Greater Element (PGE) of an element x is the first element
that appears to the left of x in the array and is strictly greater than x.

If no such element exists, return -1.

Examples:

Input:
arr[] = [1, 6, 2]

Output:
[-1, -1, 6]

Explanation:
For 1, there is no element on the left.
For 6, there is no greater element on the left.
For 2, the previous greater element is 6.

------------------------------------------------------------

Input:
arr[] = [1, 5, 0, 3, 4, 5]

Output:
[-1, -1, 5, 5, 5, -1]

Explanation:
For 1, no greater element exists on the left.
For 5, no greater element exists on the left.
For 0, previous greater element is 5.
For 3, previous greater element is 5.
For 4, previous greater element is 5.
For 5, no greater element exists on the left.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ---------------- Brute Force ----------------

vector<int> BrutePrevGreater(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

// ---------------- Optimal (Monotonic Stack) ----------------

vector<int> OptimalPrevGreater(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st; // Stores indexes

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

// ---------------- Driver Code ----------------

int main()
{
    vector<int> arr = {1, 5, 0, 3, 4, 5};
    int n = arr.size();

    vector<int> ans1 = BrutePrevGreater(arr, n);

    cout << "BRUTE: Previous Greater Elements are: ";
    for (int x : ans1)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<int> ans2 = OptimalPrevGreater(arr, n);

    cout << "OPTIMAL: Previous Greater Elements are: ";
    for (int x : ans2)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}