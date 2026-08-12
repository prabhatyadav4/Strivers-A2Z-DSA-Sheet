/*
907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444


Constraints:
1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int BruteSumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {

        int mini = arr[i];

        for (int j = i; j < n; j++)
        {

            mini = min(mini, arr[j]);

            sum = (sum + mini) % mod;
        }
    }

    return sum;
}

vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        ans[i] = (st.empty() ? n : st.top());

        st.push(i);
    }

    return ans;
}

vector<int> findPSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        ans[i] = (st.empty() ? -1 : st.top());

        st.push(i);
    }

    return ans;
}

int OptimalSumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;

    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    for (int i = 0; i < n; i++)
    {

        int left = i - pse[i];
        int right = nse[i] - i;

        long long freq = left * right * 1LL;
        int val = (freq * arr[i] * 1LL) % mod;

        sum = (sum + val) % mod;
    }

    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 5};

    int ans1 = BruteSumSubarrayMins(arr);
    cout << "BRUTE: The sum of minimum value in each subarray is: " << ans1;

    int ans2 = OptimalSumSubarrayMins(arr);
    cout << "\nOPTIMAL: The sum of minimum value in each subarray is: " << ans2;

    return 0;
}