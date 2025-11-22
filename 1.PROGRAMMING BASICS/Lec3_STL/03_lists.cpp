#include <iostream>
#include <list>
using namespace std;

void explainList() {

    list<int> ls;

    // ------------------------------
    // 1. Inserting elements
    // ------------------------------

    ls.push_back(2);     // Insert at end → {2}
    ls.emplace_back(4);  // Insert at end (faster) → {2, 4}

    ls.push_front(5);    // Insert at front → {5, 2, 4}
    ls.emplace_front(10); // Insert at front (faster) → {10, 5, 2, 4}

    // ------------------------------
    // 2. Display list
    // ------------------------------

    cout << "List elements: ";
    for (auto it : ls)
        cout << it << " ";

    cout << "\n";

    // ------------------------------
    // 3. Other operations (same as vector)
    // ------------------------------

    cout << "Front: " << ls.front() << endl;   // first element
    cout << "Back: "  << ls.back()  << endl;   // last element

    ls.pop_front();   // removes 10
    ls.pop_back();    // removes 4

    cout << "\nAfter pop operations: ";
    for (auto it : ls)
        cout << it << " ";

    cout << "\n";

    // Insert (only at a given iterator)
    auto it = ls.begin();
    advance(it, 1);       // move iterator to position 1
    ls.insert(it, 99);    // insert 99 at 2nd position

    cout << "After insert: ";
    for (auto x : ls)
        cout << x << " ";

    cout << "\n";

    // ------------------------------
    // 4. Clear list
    // ------------------------------

    ls.clear();
    cout << "List empty? " << (ls.empty() ? "Yes" : "No") << endl;
}

int main() {
    explainList();
    return 0;
}