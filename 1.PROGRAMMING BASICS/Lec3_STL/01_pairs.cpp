#include <iostream>
using namespace std;

void explainPairs() {

    // ------------------------------
    // 1. Simple pair
    // ------------------------------
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;   // Output: 1 3


    // ------------------------------
    // 2. Nested pair
    // ------------------------------
    pair<int, pair<int, int>> q = {1, {3, 4}};
    cout << q.first << " "           // 1
         << q.second.first << " "     // 3
         << q.second.second << endl;  // 4


    // ------------------------------
    // 3. Array of pairs
    // ------------------------------
    pair<int, int> arr[] = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    cout << arr[0].first  << " "   // 1
         << arr[1].second << endl; // 3
}

int main() {
    explainPairs();
    return 0;
}
