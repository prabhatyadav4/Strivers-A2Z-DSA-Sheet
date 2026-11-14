/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool BruteIsPalindrome(string s)
{
    string filtered = "";

    for (char ch : s)
    {
        if (isalnum(ch))
        {
            filtered += tolower(ch);
        }
    }

    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());

    return filtered == reversed;
}

bool OptimalIsPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (!isalnum(s[i]))
        {
            i++;
            continue;
        }

        if (!isalnum(s[j]))
        {
            j--;
            continue;
        }

        char a = tolower(s[i]);
        char b = tolower(s[j]);

        if (a != b)
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << "Brute: " << BruteIsPalindrome(s1) << endl;
    cout << "Optimal: " << OptimalIsPalindrome(s1) << endl;

    cout << "Brute: " << BruteIsPalindrome(s2) << endl;
    cout << "Optimal: " << OptimalIsPalindrome(s2) << endl;

    cout << "Brute: " << BruteIsPalindrome(s3) << endl;
    cout << "Optimal: " << OptimalIsPalindrome(s3) << endl;

    return 0;
}