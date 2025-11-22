#include <iostream>
#include <deque>
using namespace std;

void explainDeque() {

    deque<int> dq;

    // -------------------------------------
    // 1. Inserting elements
    // -------------------------------------

    dq.push_back(1);        // {1}
    dq.emplace_back(2);     // {1, 2}

    dq.push_front(4);       // {4, 1, 2}
    dq.emplace_front(3);    // {3, 4, 1, 2}

    // -------------------------------------
    // 2. Display deque
    // -------------------------------------

    cout << "Deque: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // -------------------------------------
    // 3. pop operations
    // -------------------------------------

    dq.pop_back();          // removes 2 → {3, 4, 1}
    dq.pop_front();         // removes 3 → {4, 1}

    cout << "After pops: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // -------------------------------------
    // 4. Accessing elements
    // -------------------------------------

    cout << "Front: " << dq.front() << endl; // 4
    cout << "Back : " << dq.back()  << endl; // 1

    // -------------------------------------
    // 5. Insert at specific position
    // -------------------------------------

    auto it = dq.begin();
    dq.insert(it + 1, 10);  // insert 10 at index 1 → {4, 10, 1}

    cout << "After insert: ";
    for (auto x : dq)
        cout << x << " ";
    cout << "\n";

    // -------------------------------------
    // 6. Other operations (same as vector)
    // -------------------------------------

    cout << "Size: " << dq.size() << endl;

    dq.clear();
    cout << "Deque empty? " << (dq.empty() ? "Yes" : "No") << endl;
}

int main() {
    explainDeque();
    return 0;
}