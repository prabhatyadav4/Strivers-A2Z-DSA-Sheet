/*
313. Longest Substring With At Most K Distinct Characters
Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

Example 1:
Input : s = "aababbcaacc" , k = 2

Output : 6

Explanation : The longest substring with at most two distinct characters is "aababb".

The length of the string 6.

Example 2:
Input : s = "abcddefg" , k = 3

Output : 4

Explanation : The longest substring with at most three distinct characters is "bcdd".

The length of the string 4.

Constraints:
1 <= s.length <= 105
1 <= k <= 26
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int BruteKDistinctChar(string &s, int k)
{
    int n = s.length();

    if (k == 0 || n == 0)
    {
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_set<char> st;

        for (int j = i; j < n; j++)
        {

            st.insert(s[j]);

            if (st.size() <= k)
            {
                ans = max(ans, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return ans;
}

int BetterKDistinctChar(string &s, int k)
{
    int n = s.length();

    if (k == 0 || n == 0)
    {
        return 0;
    }

    int l = 0, r = 0, ans = 0;
    unordered_map<char, int> freq;

    while (r < n)
    {
        freq[s[r]]++;

        if (freq.size() > k)
        {
            freq[s[l]]--;

            if (freq[s[l]] == 0)
            {
                freq.erase(s[l]);
            }

            l++;
        }

        if (freq.size() <= k)
        {
            ans = max(ans, r - l + 1);
        }

        r++;
    }

    return ans;
}

int OptimalKDistinctChar(string &s, int k)
{
    int n = s.length();

    if (k == 0 || n == 0)
    {
        return 0;
    }

    int freq[26] = {0};

    int l = 0, r = 0, distinct = 0, ans = 0;

    while (r < n)
    {
        int rightIdx = s[r] - 'a';

        if (freq[rightIdx] == 0)
        {
            distinct++;
        }

        freq[rightIdx]++;

        if (distinct > k)
        {
            int leftIdx = s[l] - 'a';
            freq[leftIdx]--;

            if (freq[leftIdx] == 0)
            {
                distinct--;
            }

            l++;
        }

        if (distinct <= k)
        {
            ans = max(ans, r - l + 1);
        }

        r++;
    }

    return ans;
}

int main()
{

    string s = "eceba";
    int k = 2;

    int ans1 = BruteKDistinctChar(s, k);
    cout << "BRUTE: The longest substring is of size: " << ans1 << endl;

    int ans2 = BetterKDistinctChar(s, k);
    cout << "BETTER: The longest substring is of size: " << ans2 << endl;

    int ans3 = OptimalKDistinctChar(s, k);
    cout << "OPTIMAL: The longest substring is of size: " << ans3 << endl;

    return 0;
}