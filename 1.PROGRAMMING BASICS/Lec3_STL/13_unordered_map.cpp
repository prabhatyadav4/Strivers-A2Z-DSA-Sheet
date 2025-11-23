#include <iostream>
#include <unordered_map>
using namespace std;

void explainUnorderedMap() {

    // ----------------------------------------------------
    // 1. Creating an unordered_map
    // ----------------------------------------------------
    // unordered_map stores KEY-VALUE pairs
    // but NOT in sorted order (hash table).
    // Average time complexity: O(1)
    // Worst case: O(N)
    // Duplicate keys NOT allowed.

    unordered_map<int, string> mpp;

    // ----------------------------------------------------
    // 2. Inserting elements
    // ----------------------------------------------------
    mpp[1] = "One";             // creates key 1
    mpp[2] = "Two";             // creates key 2
    mpp.emplace(3, "Three");    // emplace
    mpp.insert({4, "Four"});    // insert

    // ----------------------------------------------------
    // 3. Iterating (order is RANDOM)
    // ----------------------------------------------------
    cout << "Elements in unordered_map (random order):\n";
    for (auto &p : mpp) {
        cout << p.first << " -> " << p.second << endl;
    }

    // ----------------------------------------------------
    // 4. Access using operator[]
    // ----------------------------------------------------
    cout << "\nmpp[1] = " << mpp[1] << endl;

    // mpp[10] CREATES the key if it doesn't exist
    cout << "mpp[10] (auto-created) = " << mpp[10] << endl;


    // ----------------------------------------------------
    // 5. Checking if a key exists (find)
    // ----------------------------------------------------
    auto it = mpp.find(2);
    cout << "\nFinding key 2: "
         << (it != mpp.end() ? "Found" : "Not Found") << endl;

    auto it2 = mpp.find(100);
    cout << "Finding key 100: "
         << (it2 != mpp.end() ? "Found" : "Not Found") << endl;


    // ----------------------------------------------------
    // 6. count(key)
    // ----------------------------------------------------
    // For unordered_map, count(x) is either 0 or 1
    cout << "\nCount of key 3: " << mpp.count(3) << endl;
    cout << "Count of key 200: " << mpp.count(200) << endl;


    // ----------------------------------------------------
    // 7. Erasing
    // ----------------------------------------------------
    mpp.erase(1);       // remove key 1

    cout << "\nAfter erasing key 1:\n";
    for (auto &p : mpp) {
        cout << p.first << " -> " << p.second << endl;
    }

    // erase(iterator)
    auto it3 = mpp.find(3);
    if (it3 != mpp.end()) {
        mpp.erase(it3);
    }

    cout << "\nAfter erasing key 3 using iterator:\n";
    for (auto &p : mpp) {
        cout << p.first << " -> " << p.second << endl;
    }


    // ----------------------------------------------------
    // 8. lower_bound() and upper_bound() DO NOT WORK
    // ----------------------------------------------------
    cout << "\nNote: lower_bound() and upper_bound() do NOT work "
         << "with unordered_map because it is NOT sorted.\n";


    // ----------------------------------------------------
    // 9. Other functions
    // ----------------------------------------------------
    cout << "\nSize: " << mpp.size() << endl;
    cout << "Is empty? " << (mpp.empty() ? "Yes" : "No") << endl;
}


int main() {
    explainUnorderedMap();
    return 0;
}