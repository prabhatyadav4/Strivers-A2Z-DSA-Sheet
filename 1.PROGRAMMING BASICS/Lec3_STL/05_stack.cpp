#include <iostream>
#include <stack>
using namespace std;

void explainStack() {

    stack<int> st;

    // -------------------------------------
    // 1. Inserting elements
    // -------------------------------------

    st.push(1);        // {1}
    st.push(2);        // {1, 2}
    st.push(3);        // {1, 2, 3}
    st.push(4);        // {1, 2, 3, 4}
    st.emplace(5);     // {1, 2, 3, 4, 5}

    // -------------------------------------
    // 2. Accessing and popping elements
    //    Note: pop() does NOT return value
    // -------------------------------------

    cout << "Top element: " << st.top() << endl; // 5
    st.pop();                                     // removes 5

    cout << "Top after 1 pop: " << st.top() << endl; // 4
    st.pop();                                         // removes 4

    // -------------------------------------
    // 3. Stack size and empty check
    // -------------------------------------

    cout << "Current size: " << st.size() << endl;     // 3 elements left
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    // -------------------------------------
    // 4. Swap operation
    // -------------------------------------

    stack<int> st1, st2;
    st1.push(100);
    st1.push(200);

    cout << "Before swap, st1 top: " << st1.top() << endl; // 200

    st1.swap(st2);  // exchanges contents

    cout << "After swap, st1 empty? " << (st1.empty() ? "Yes" : "No") << endl;
    cout << "After swap, st2 top : " << st2.top() << endl; // 200
}

int main() {
    explainStack();
    return 0;
}