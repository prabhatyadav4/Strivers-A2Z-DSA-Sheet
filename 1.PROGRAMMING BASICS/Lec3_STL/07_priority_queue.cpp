#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void explainPQ() {

    // -------------------------------------
    // 1. Max-Heap Priority Queue (default)
    // -------------------------------------
    // Largest element stays at the top.

    priority_queue<int> pq;

    pq.push(5);      // {5}
    pq.push(2);      // {5, 2}
    pq.push(8);      // {8, 2, 5}
    pq.emplace(10);  // {10, 8, 5, 2}

    cout << "Max-Heap Top: " << pq.top() << endl;   // prints 10
    pq.pop();                                        // removes 10

    cout << "After pop, New Top: " << pq.top() << endl; // prints 8


    // -------------------------------------
    // 2. Min-Heap Priority Queue
    // -------------------------------------
    // Smallest element stays at the top.

    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(5);      // {5}
    minPQ.push(2);      // {2, 5}
    minPQ.push(8);      // {2, 5, 8}
    minPQ.emplace(10);  // {2, 5, 8, 10}

    cout << "Min-Heap Top: " << minPQ.top() << endl;  // prints smallest → 2


    // -------------------------------------
    // 3. Other operations
    // -------------------------------------
    // size(), empty(), swap() work same as queue/stack

    cout << "Size of minPQ: " << minPQ.size() << endl;
    cout << "Is minPQ empty? " << (minPQ.empty() ? "Yes" : "No") << endl;
}

int main() {
    explainPQ();
    return 0;
}