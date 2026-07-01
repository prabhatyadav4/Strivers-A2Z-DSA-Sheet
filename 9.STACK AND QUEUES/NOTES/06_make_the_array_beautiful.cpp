/*
Make the array beautiful

Given an array of negative and non-negative integers. You need to make the array beautiful.

An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or positive.

You can do the following operation any number of times until the array becomes beautiful.
    If two adjacent are different i.e. one of them is negative and other is positive, remove them.
    Return the beautiful array after performing the above operation.
    An empty array is also a beautiful array.
    There can be multiple beautiful output arrays. For consistencty with the test cases, scan the array from left to right for removing two adjacent.

Note: 0 is considered a positive number in this context.

Examples:
Input: arr[] = [4, 2,-2, 1]
Output: [4, 1]
Explanation: As at indices 1 and 2 , 2 and -2 have different sign, they are removed. And the the final array is: [4, 1].

Input: arr[] = [2,-2, -1, 1]
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have different sign, so they are removed. Now the array is 1 -1.Now 1 and -1 are also removed as they have different sign. So the final array is empty.


Constraints:
1 ≤ arr.size() ≤ 105
-105 ≤ arr[i] ≤ 105
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> makeBeautiful(vector<int> arr)
{
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {

        // Stack is empty
        if (st.empty())
        {
            st.push(arr[i]);
        }

        // Array is non-negative
        else if (arr[i] >= 0)
        {
            if (st.top() >= 0)
            {
                st.push(arr[i]);
            }
            else
            {
                st.pop();
            }
        }

        // Array is negative
        else
        {
            if (st.top() < 0)
            {
                st.push(arr[i]);
            }
            else
            {
                st.pop();
            }
        }
    }

    vector<int> ans(st.size());

    int i = st.size() - 1;

    while (!st.empty())
    {
        ans[i] = st.top();
        i--;
        st.pop();
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 5, -4, 6, -2, -8, 9};

    vector<int> ans = makeBeautiful(arr);

    cout << "The Beautiful Array is: ";

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}