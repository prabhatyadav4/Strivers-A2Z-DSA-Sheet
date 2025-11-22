#include <iostream>
#include <unordered_set>
using namespace std;

void explainUset() {

    // -------------------------------------
    // 1. Creating an unordered_set
    // -------------------------------------
    // Stores UNIQUE elements (like set),
    // BUT order is NOT sorted. (Hash table)
    // Average O(1) operations.

    unordered_set<int> st;

    st.insert(5);
    st.insert(1);
    st.insert(3);
    st.insert(3);   // duplicate → ignored
    st.insert(2);

    cout << "Elements in unordered_set (random order): ";
    for (int x : st) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 2. Checking presence (find)
    // -------------------------------------
    auto it = st.find(3);
    cout << "Finding 3: " 
         << (it != st.end() ? "Found" : "Not Found") 
         << endl;

    auto it2 = st.find(10);
    cout << "Finding 10: " 
         << (it2 != st.end() ? "Found" : "Not Found") 
         << endl;


    // -------------------------------------
    // 3. Erasing
    // -------------------------------------
    // erase(value) removes it if present

    st.erase(1);
    cout << "After erasing 1: ";
    for (int x : st) cout << x << " ";
    cout << endl;

    // erase(iterator)
    auto it3 = st.find(5);
    if (it3 != st.end()) st.erase(it3);

    cout << "After erasing 5 (via iterator): ";
    for (int x : st) cout << x << " ";
    cout << endl;


    // -------------------------------------
    // 4. count(x)
    // -------------------------------------
    cout << "Count of 3: " << st.count(3) << endl;
    cout << "Count of 100: " << st.count(100) << endl;


    // -------------------------------------
    // 5. Note about bounds
    // -------------------------------------
    // lower_bound() and upper_bound() DO NOT WORK
    // with unordered_set because it's NOT sorted.

    cout << "Note: lower_bound() and upper_bound() do NOT work in unordered_set." << endl;


    // -------------------------------------
    // 6. Other functions same as set
    // -------------------------------------
    cout << "Size: " << st.size() << endl;
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;
}

int main() {
    explainUset();
    return 0;
}