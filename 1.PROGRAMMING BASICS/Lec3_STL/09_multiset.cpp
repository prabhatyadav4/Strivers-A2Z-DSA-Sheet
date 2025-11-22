#include <iostream>
#include <set>
using namespace std;

void explainMultiSet() {

    // -------------------------------------
    // 1. Creating a multiset
    // -------------------------------------
    // A multiset stores elements in sorted order,
    // BUT allows duplicates (unlike set).

    multiset<int> ms;

    ms.insert(1);   // {1}
    ms.insert(1);   // {1, 1}
    ms.insert(1);   // {1, 1, 1}

    cout << "Initial multiset: ";
    for (int x : ms) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 2. Erasing by value
    // -------------------------------------
    // erase(value) removes ALL occurrences of that value.

    ms.erase(1);     // removes all 1s → empty multiset

    cout << "After erase(1): ";
    for (int x : ms) cout << x << " ";
    cout << "(empty)" << endl;


    // Insert again for next operations
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);


    // -------------------------------------
    // 3. count(x)
    // -------------------------------------
    int cnt = ms.count(1);  
    cout << "Count of 1: " << cnt << endl;  // prints 3


    // -------------------------------------
    // 4. Erasing a single element
    // -------------------------------------
    // erase(iterator) removes only ONE element.

    auto it = ms.find(1);  // iterator to first 1
    if (it != ms.end()) ms.erase(it); // removes only one 1

    cout << "After erasing one 1: ";
    for (int x : ms) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 5. Erasing a RANGE
    // -------------------------------------
    // Erase first 2 occurrences of 1

    auto start = ms.begin();          // first element
    auto end = next(ms.begin(), 2);   // move iterator 2 steps ahead

    ms.erase(start, end); // removes two 1s

    cout << "After erasing first 2 elements: ";
    for (int x : ms) cout << x << " ";
    cout << "(should be empty)" << endl;


    // -------------------------------------
    // All other functions are same as std::set
    // -------------------------------------
}

int main() {
    explainMultiSet();
    return 0;
}