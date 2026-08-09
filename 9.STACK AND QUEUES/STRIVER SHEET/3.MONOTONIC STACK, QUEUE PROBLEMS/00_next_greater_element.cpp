/*
Next Greater Element

Given an array arr of size n containing elements, find the next greater element for each element in the array in the order of their appearance.

The next greater element of an element in the array is the nearest element on the right that is greater than the current element.

If there does not exist a next greater element for the current element, then the next greater element for that element is -1.

Example 1

Input: arr = [1, 3, 2, 4]

Output: [3, 4, 4, -1]

Explanation: In the array, the next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4 is -1, since it does not exist.

Example 2

Input: arr = [6, 8, 0, 1, 3]

Output: [8, -1, 1, 3, -1]

Explanation: In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on the right and hence -1.


Constraints
1 ≤ n ≤ 105
0 ≤ arr[i] ≤ 109
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> ans = nextGreaterElement(arr);

    cout << "Next Greater Elements are: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}