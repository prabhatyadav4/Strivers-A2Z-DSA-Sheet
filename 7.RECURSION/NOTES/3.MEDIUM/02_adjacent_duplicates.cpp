/*
Recursively Remove Adjacent Duplicates

Given a string s, remove all its adjacent duplicate characters recursively, until there are no adjacent duplicate characters left.

Note: If the resultant string becomes empty, return an empty string.

Examples:
Input: s = "geeksforgeek"
Output: "gksforgk"
Explanation:  g(ee)ksforg(ee)k -> gksforgk

Input: s = "abccbccba"
Output: ""
Explanation: ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

Input: s = "abcd"
Output: "abcd"
Explanation: There are no adjacent duplicate characters

Constraints:
1<= s.size() <= 105
*/

#include <iostream>
#include <string>
using namespace std;

// [Naive Approach] Using Recursion - O(n ^ 2) Time and O(n ^ 2) Space
string removeDuplicates(string &s) {
    int n = s.length();
    string sb = "";
    for(int i = 0; i < n; i++) {
        bool repeated = false;
        while(i + 1 < n && s[i] == s[i + 1]) {
            repeated = true;
            i++;
        }

        if(!repeated) sb += s[i];
    }

    if(sb.length() == n)    return sb;

    return removeDuplicates(sb);
}

// [Expected Approach] Using Recursion - O(n ^ 2) Time and O(n) Space
void removeUtils(string &s, int n) {
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && s[i] == s[i + 1]) {
            while(i + 1 < n && s[i] == s[i + 1]) {
                i++;
            }
        }
        else {
            s[k++] = s[i];
        }
    }
    s.erase(k);
    if(k != n)  removeUtils(s, k);
}

string removeDup(string s) {
    removeUtils(s, s.size());
    return s;
}

int main() {
    string s1 = "geeksforgeeks";
    string s2 = "aabbbcccd";

    cout << "Naive Approach: " << endl;
    cout << "Original String: " << s1 << endl;
    cout << "After removing duplicates: " << removeDuplicates(s1) << endl;

    cout << "\nExpected Approach: " << endl;
    cout << "Original String: " << s2 << endl;
    cout << "After removing duplicates: " << removeDup(s2) << endl;

    return 0;
}