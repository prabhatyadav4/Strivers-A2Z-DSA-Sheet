/*
Remove Two Consecutive Same

Tom is a string freak. He has got sequences of words arr[] to manipulate.
If in a sequence, two same words come together then Tom destroys each other.
Find the number of words left in the sequence after this pairwise destruction.

Examples:

Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
Output: 3
Explanation: After the first iteration, we'll have: ab bcd ab. We can't further destroy more strings and hence we stop and the result is 3.

Input: arr[] = ["tom", "jerry", "jerry", "tom"]
Output: 0
Explanation: After the first iteration, we'll have: tom tom. After the second iteration: 'empty-array' .Hence, the result is 0.

Constraints:
1 ≤ arr.size() ≤106
1 ≤ |arri| ≤ 50
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int removeConsecutiveSame(vector<string> arr)
{
    stack<string> st;

    for (int i = 0; i < arr.size(); i++)
    {

        if (st.empty())
        {
            st.push(arr[i]);
        }

        else if (st.top() == arr[i])
        {
            st.pop();
        }

        else
        {
            st.push(arr[i]);
        }
    }

    return st.size();
}

int main()
{
    vector<string> arr = {"ab", "ac", "da", "da", "ac", "db", "ea"};

    cout << "The size of string after removing consecutive same is: " << removeConsecutiveSame(arr);

    return 0;
}