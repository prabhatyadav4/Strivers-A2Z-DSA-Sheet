/*
Number of Greater Elements to the Right

You are given an integer array arr[] of length n and an array of queries indices[] containing positions in arr.

For each query i, determine the number of elements in arr that are strictly greater than arr[indices[i]] and appear to its right (after position indices[i]).

Return an array of answers where the jth value corresponds to the result for indices[j].

Example 1

Input: arr = [3, 4, 2, 7, 5, 8, 10, 6], indices = [0, 5]

Output: [6, 1]

Explanation:
For index 0 → arr[0] = 3, elements greater than 3 to its right are [4, 7, 5, 8, 10, 6] → count = 6.
For index 5 → arr[5] = 8, greater elements to the right are [10] → count = 1.
Example 2

Input: arr = [1, 2, 3, 4, 1], indices = [0, 3]

Output: [3, 0]

Explanation:
For index 0 → arr[0] = 1, greater elements to the right are [2, 3, 4] → count = 3.
For index 3 → arr[3] = 4, no elements greater than 4 exist to the right → count = 0.

Constraints
1 ≤ n ≤ 104
1 ≤ arr[i] ≤ 105
1 ≤ queries ≤ 100
0 ≤ indices[i] ≤ n - 1
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> count_NGE(vector<int> arr, vector<int> indices)
{

    int n = arr.size();
    vector<int> ans;

    for (int idx : indices)
    {

        stack<int> st;

        for (int i = idx + 1; i < n; i++)
        {
            st.push(arr[i]);
        }

        int count = 0;

        while (!st.empty())
        {
            if (st.top() > arr[idx])
            {
                count++;
            }

            st.pop();
        }

        ans.push_back(count);
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices = {0, 5};

    vector<int> ans = count_NGE(arr, indices);

    cout << "Number of Greater Elements are: ";

    cout << "[ ";
    for (int ele : ans)
    {
        cout << ele << " ";
    }
    cout << "]";

    return 0;
}