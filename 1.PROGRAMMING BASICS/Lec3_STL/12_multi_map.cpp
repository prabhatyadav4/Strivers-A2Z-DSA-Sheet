#include <iostream>
#include <map>
using namespace std;

void explainMultiMap() {

    // ----------------------------------------------------
    // 1. Creating a multimap
    // ----------------------------------------------------
    // multimap is like map BUT:
    // ✔ Allows duplicate KEYS
    // ✔ Stores keys in sorted order
    // ✔ No operator[] (because duplicate keys make it ambiguous)
    //
    // All operations: O(log N)

    multimap<int, int> mpp;

    // ----------------------------------------------------
    // 2. Inserting elements
    // ----------------------------------------------------
    mpp.insert({1, 100});
    mpp.insert({2, 200});
    mpp.insert({1, 300});   // duplicate key allowed
    mpp.emplace(2, 400);    // duplicate key allowed
    mpp.emplace(3, 500);

    // ----------------------------------------------------
    // 3. Iterating through multimap
    // ----------------------------------------------------
    cout << "Elements in multimap (sorted with duplicates):\n";
    for (auto &p : mpp) {
        cout << p.first << " -> " << p.second << endl;
    }

    // ----------------------------------------------------
    // 4. Searching with find()
    // ----------------------------------------------------
    // find() returns FIRST occurrence of the key.
    auto it = mpp.find(1);
    if (it != mpp.end()) {
        cout << "\nFirst occurrence of key 1: "
             << it->first << " -> " << it->second << endl;
    }

    // ----------------------------------------------------
    // 5. Getting ALL values of a key using equal_range()
    // ----------------------------------------------------
    cout << "\nAll values for key 2:\n";
    auto range = mpp.equal_range(2);   // pair of iterators

    for (auto itr = range.first; itr != range.second; itr++) {
        cout << itr->first << " -> " << itr->second << endl;
    }

    // ----------------------------------------------------
    // 6. lower_bound() and upper_bound()
    // ----------------------------------------------------
    auto lb = mpp.lower_bound(2); // first element with key >= 2
    auto ub = mpp.upper_bound(2); // first element with key > 2

    cout << "\nlower_bound(2): " 
         << lb->first << " -> " << lb->second << endl;

    cout << "upper_bound(2): ";
    if (ub != mpp.end())
        cout << ub->first << " -> " << ub->second << endl;
    else
        cout << "No element > 2\n";

    // ----------------------------------------------------
    // 7. Erasing elements
    // ----------------------------------------------------
    // erase(key) removes ALL entries with that key
    mpp.erase(1);

    cout << "\nAfter erasing all keys = 1:\n";
    for (auto &p : mpp) {
        cout << p.first << " -> " << p.second << endl;
    }

    // erase(iterator)
    auto it2 = mpp.find(2);
    if (it2 != mpp.end()) {
        mpp.erase(it2);
    }

    cout << "\nAfter erasing one element with key = 2:\n";
    for (auto &p : mpp) {
        cout << p.first << " -> " << p.second << endl;
    }

    // ----------------------------------------------------
    // 8. Other operations
    // ----------------------------------------------------
    cout << "\nSize: " << mpp.size() << endl;
    cout << "Is empty? " << (mpp.empty() ? "Yes" : "No") << endl;
}

int main() {
    explainMultiMap();
    return 0;
}