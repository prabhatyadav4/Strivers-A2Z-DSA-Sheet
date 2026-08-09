/*
Next Smaller Element

Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.

The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.

If there is no smaller element to the right, then the NSE is -1.


Example 1

Input: arr = [4, 8, 5, 2, 25]

Output: [2, 5, 2, -1, -1]

Explanation:
- For 4, the next smaller element is 2.

- For 8, the next smaller element is 5.

- For 5, the next smaller element is 2.

- For 2, there is no smaller element to its right → -1.

- For 25, no smaller element exists → -1.

Example 2

Input: arr = [10, 9, 8, 7]

Output: [9, 8, 7, -1]

Explanation:
Each element’s next right neighbor is smaller.

Constraints
1 <= arr.length <= 105
-109 <= arr[i] <= 109
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        ans[i] = (st.empty() ? -1 : st.top());

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};

    vector<int> ans = nextSmallerElement(arr);

    cout << "The next smaller element are: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}