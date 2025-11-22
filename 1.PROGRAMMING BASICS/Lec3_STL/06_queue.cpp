#include <iostream>
#include <queue>
using namespace std;

void explainQueue() {

    queue<int> q;

    // -------------------------------------
    // 1. Inserting elements
    // -------------------------------------

    q.push(1);        // {1}
    q.push(2);        // {1, 2}
    q.emplace(4);     // {1, 2, 4}

    // -------------------------------------
    // 2. Modifying the last element
    // -------------------------------------

    q.back() += 5;    // last element becomes 4 + 5 = 9 → {1, 2, 9}

    cout << "Back element: " << q.back() << endl;   // prints 9

    // -------------------------------------
    // 3. Accessing front element
    // -------------------------------------

    cout << "Front element: " << q.front() << endl; // prints 1

    // -------------------------------------
    // 4. Pop operation
    // -------------------------------------

    q.pop();   // removes 1 → {2, 9}

    cout << "Front after pop: " << q.front() << endl; // prints 2

    // -------------------------------------
    // 5. Other functions (same as stack)
    // -------------------------------------

    cout << "Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    queue<int> q1, q2;
    q1.push(10);
    q1.push(20);

    q1.swap(q2);  // swap contents

    cout << "After swap, q2 front: " << q2.front() << endl; // prints 10
}

int main() {
    explainQueue();
    return 0;
}