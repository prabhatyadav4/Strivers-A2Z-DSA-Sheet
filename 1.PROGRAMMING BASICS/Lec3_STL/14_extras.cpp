#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Custom comparator for sorting pair<int,int>
// Sort by SECOND element ascending
// If second is same → sort by FIRST element descending
// ------------------------------------------------------------
bool comp(pair<int,int> p1, pair<int,int> p2) {

    if (p1.second != p2.second)
        return p1.second < p2.second;     // smaller second comes first

    return p1.first > p2.first;           // if tie → larger first comes first
}

void explainExtra() {

    // ------------------------------------------------------------
    // 1. Sorting arrays and vectors
    // ------------------------------------------------------------
    int a[] = {5, 3, 8, 1, 6};
    int n = 5;

    sort(a, a + n);                // full array sort
    sort(a + 1, a + 4);            // partial sort

    vector<int> v = {4, 1, 7, 2};
    sort(v.begin(), v.end());      // vector sort

    sort(a, a + n, greater<int>());   // sort in descending order


    // ------------------------------------------------------------
    // 2. Sorting array of pairs with custom comparator
    // ------------------------------------------------------------
    pair<int,int> p[] = {{1, 2}, {2, 1}, {4, 2}};
    int m = 3;

    // Sort using our custom comparator "comp"
    sort(p, p + m, comp);

    cout << "Sorted pairs:\n";
    for (auto &x : p)
        cout << x.first << " " << x.second << endl;


    // ------------------------------------------------------------
    // 3. __builtin_popcount (for counting set bits)
    // ------------------------------------------------------------
    int num = 7;                        // 7 → 111 → 3 bits set
    int cnt = __builtin_popcount(num);

    long long num2 = 165786578687LL;
    int cnt2 = __builtin_popcountll(num2);

    cout << "\nSet bits in 7: " << cnt << endl;
    cout << "Set bits in " << num2 << ": " << cnt2 << endl;


    // ------------------------------------------------------------
    // 4. next_permutation
    // ------------------------------------------------------------
    cout << "\nPermutations of 123:\n";
    string s = "123";

    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));


    // ------------------------------------------------------------
    // 5. max_element
    // ------------------------------------------------------------
    int a2[] = {10, 25, 7, 3};
    int mx = *max_element(a2, a2 + 4);

    cout << "\nMaximum element in a2: " << mx << endl;
}


int main() {
    explainExtra();
    return 0;
}