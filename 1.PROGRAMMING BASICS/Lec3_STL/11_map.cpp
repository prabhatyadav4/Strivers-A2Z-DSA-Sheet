#include <iostream>
#include <map>
using namespace std;

void explainMap() {

    // ----------------------------------------------------
    // 1. Creating std::map
    // ----------------------------------------------------
    // map stores KEY-VALUE pairs in SORTED order (by key).
    // All operations: O(log N)
    // No duplicate keys allowed.

    map<int, int> mpp;

    // ----------------------------------------------------
    // 2. Inserting elements
    // ----------------------------------------------------
    mpp[1] = 2;            // Insert key=1, value=2
    mpp.emplace(3, 1);     // Insert using emplace
    mpp.insert({2, 4});    // Insert using pair

    // ----------------------------------------------------
    // 3. Accessing map using operator[]
    // ----------------------------------------------------
    // NOTE: mpp[5] creates a NEW KEY with default value 0
    // if it does not exist.
    cout << "mpp[1] = " << mpp[1] << endl;
    cout << "mpp[5] (creates key 5) = " << mpp[5] << endl;

    // Now map contains: {1,2}, {2,4}, {3,1}, {5,0}


    // ----------------------------------------------------
    // 4. Iterating through map
    // ----------------------------------------------------
    cout << "\nElements in map (sorted by key):\n";
    for (auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // ----------------------------------------------------
    // 5. Searching for a key (find)
    // ----------------------------------------------------
    auto it = mpp.find(3);
    if (it != mpp.end()) {
        cout << "\nFound key 3, value = " << it->second << endl;
    } else {
        cout << "\nKey 3 not found\n";
    }

    auto it2 = mpp.find(10);
    cout << "Searching for key 10: "
         << (it2 != mpp.end() ? "Found" : "Not Found") << endl;


    // ----------------------------------------------------
    // 6. lower_bound() and upper_bound()
    // ----------------------------------------------------
    // lower_bound(x): first element with key >= x
    // upper_bound(x): first element with key > x

    auto lb = mpp.lower_bound(2);
    if (lb != mpp.end())
        cout << "\nlower_bound(2) → key: " << lb->first 
             << ", value: " << lb->second << endl;

    auto ub = mpp.upper_bound(3);
    if (ub != mpp.end())
        cout << "upper_bound(3) → key: " << ub->first 
             << ", value: " << ub->second << endl;


    // ----------------------------------------------------
    // 7. Erasing elements
    // ----------------------------------------------------
    mpp.erase(5);             // erase key 5
    mpp.erase(2);             // erase key 2

    cout << "\nAfter erasing keys 5 and 2:\n";
    for (auto &x : mpp) {
        cout << x.first << " -> " << x.second << endl;
    }


    // ----------------------------------------------------
    // 8. Other functions
    // ----------------------------------------------------
    cout << "\nSize: " << mpp.size() << endl;
    cout << "Is empty? " << (mpp.empty() ? "Yes" : "No") << endl;
}

int main() {
    explainMap();
    return 0;
}