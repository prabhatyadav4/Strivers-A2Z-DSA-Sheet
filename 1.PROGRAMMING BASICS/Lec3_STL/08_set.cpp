#include <iostream>
#include <set>
using namespace std;

void explainSet() {

    // -------------------------------------
    // 1. Creating a set
    // -------------------------------------
    // A set stores UNIQUE elements in SORTED order.
    // Duplicate values are ignored.

    set<int> st;

    st.insert(1);   // {1}
    st.emplace(2);  // {1, 2}
    st.insert(2);   // duplicate → ignored
    st.insert(3);   // {1, 2, 3}
    st.insert(4);   // {1, 2, 3, 4}

    cout << "Initial set: ";
    for (int x : st) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 2. Finding elements
    // -------------------------------------
    // find(x) returns iterator to x if found,
    // otherwise returns st.end()

    auto it = st.find(3);
    cout << "Finding 3: " 
         << (it != st.end() ? "Found" : "Not Found") << endl;

    auto it_not_found = st.find(6);
    cout << "Finding 6: " 
         << (it_not_found != st.end() ? "Found" : "Not Found") << endl;


    // -------------------------------------
    // 3. Erasing elements
    // -------------------------------------
    // erase(x) removes value if found

    st.erase(5);  // no effect (5 not found)

    int cnt = st.count(1);  
    cout << "Count of 1: " << cnt << endl;

    // erase(iterator)
    auto it2 = st.find(3);
    if (it2 != st.end()) {
        st.erase(it2);  // removes 3
    }

    cout << "After erasing 3: ";
    for (int x : st) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 4. Erasing a RANGE
    // -------------------------------------
    // erase(start, end) removes [start, end)

    auto it1 = st.find(2); // points to 2
    auto it3 = st.find(4); // points to 4

    st.erase(it1, it3);  // removes only 2

    cout << "After erasing range [2,4): ";
    for (int x : st) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 5. lower_bound() and upper_bound()
    // -------------------------------------

    auto lb = st.lower_bound(2); // first element >= 2
    if (lb != st.end())
        cout << "lower_bound(2): " << *lb << endl;
    else
        cout << "lower_bound(2): No element >= 2" << endl;

    auto ub = st.upper_bound(3); // first element > 3
    if (ub != st.end())
        cout << "upper_bound(3): " << *ub << endl;
    else
        cout << "upper_bound(3): No element > 3" << endl;
}

int main() {
    explainSet();
    return 0;
}