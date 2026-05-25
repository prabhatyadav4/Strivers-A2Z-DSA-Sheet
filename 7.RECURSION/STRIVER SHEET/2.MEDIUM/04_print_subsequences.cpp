/*
Print Subsequences

Problem statement
Given a string (lets say of length n), print all the subsequences of the given string.

Subsequences contain all the strings of length varying from 0 to n. But the order of characters should remain same as in the input string.

Note :
The order of subsequences are not important. Print every subsequence in new line.

Constraints
1 <= |S| <= 15
where |S| represents the length of the input string

Time limit: 1 sec

Sample Input:
abc
Sample Output:
"" (the double quotes just signifies an empty string, don't worry about the quotes)
c
b
bc
a
ac
ab
abc
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void solve(vector<char> &v, int n, int i, vector<char> &temp)
{
    if (i >= n)
    {
        for (char ch : temp)
        {
            cout << ch;
        }
        cout << endl;
        return;
    }

    temp.push_back(v[i]);
    solve(v, n, i + 1, temp);
    temp.pop_back();
    solve(v, n, i + 1, temp);
}

void printSubsequences(char input[])
{
    vector<char> v;
    int n = strlen(input);

    for (int i = 0; i < n; i++)
    {
        v.push_back(input[i]);
    }

    vector<char> temp;

    solve(v, n, 0, temp);

}

int main()
{
    char input[] = "abc";

    cout << "The possible subsequences of strings are: ";

    printSubsequences(input);

    return 0;
}