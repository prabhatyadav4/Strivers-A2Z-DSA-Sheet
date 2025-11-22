#include <iostream>
#include <vector>
using namespace std;

// Function to demonstrate vector operations
void explainVector() {

    // ------------------------------
    // 1. Vector creation & insertion
    // ------------------------------

    vector<int> v;
    v.push_back(1);       // push_back() inserts normally
    v.emplace_back(2);    // emplace_back() is faster (constructs in place)

    // Vector of pairs
    vector<pair<int,int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    // Vector with repeated values
    vector<int> vA(5, 100);   // {100,100,100,100,100}

    vector<int> vB(5);        // {0,0,0,0,0} (default initialized)

    vector<int> vC(5, 20);    // {20,20,20,20,20}

    vector<int> vD(vC);       // Copy vector


    // ------------------------------
    // 2. Iterators
    // ------------------------------

    vector<int>::iterator it = vA.begin();
    cout << "Iterator examples:\n";
    cout << *(it) << endl;   // prints first element

    it++;                    // move to next element
    cout << *(it) << endl;

    it = it + 2;             // jump 2 steps
    cout << *(it) << endl;

    // Other iterator types
    vector <int> :: iterator itEnd = vA.end();  // points to after last element
    auto itREnd = vA.rend();    // reverse end
    auto itRBegin = vA.rbegin(); // reverse begin


    // ------------------------------
    // 3. Accessing elements
    // ------------------------------

    cout << "\nAccessing elements:\n";
    cout << vA[0] << " ";        // no bounds check
    cout << vA.at(0) << " ";     // bounds check
    cout << vA.back() << "\n";   // last element


    // ------------------------------
    // 4. Display vector values
    // ------------------------------

    cout << "\nDisplay vector:\n";

    // Using iterator
    for(vector<int> :: iterator t = vA.begin(); it != vA.end(); it++)
        cout << *it << " ";
    
    cout << "\n";

    for (auto it = vA.begin(); it != vA.end(); it++)
        cout << *it << " ";

    cout << "\n";

    // Using range-based loop
    for (auto x : vA)
        cout << x << " ";

    cout << "\n";


    // ------------------------------
    // 5. Erase elements
    // ------------------------------

    vector<int> vE = {10, 20, 30, 40, 50};

    vE.erase(vE.begin() + 1);                // Erase element at index 1 → removes 20
    vE.erase(vE.begin() + 1, vE.begin() + 3); // Erase range → removes 30,40


    // ------------------------------
    // 6. Insert operations
    // ------------------------------

    vector<int> vF(2, 100);      // {100,100}
    vF.insert(vF.begin(), 300);  // {300,100,100}
    vF.insert(vF.begin() + 1, 2, 10); // insert 10 twice → {300,10,10,100,100}

    vector<int> copy(2, 50);     // {50,50}
    vF.insert(vF.begin(), copy.begin(), copy.end()); // insert another vector at start


    // ------------------------------
    // 7. pop_back(), size(), swap(), clear()
    // ------------------------------

    cout << "\nSize of vF = " << vF.size() << endl;
    vF.pop_back();              // remove last element

    vector<int> x = {10, 20};
    vector<int> y = {30, 40};
    x.swap(y);                  // swap vectors

    vF.clear();
    cout << "Is vF empty? " << vF.empty() << endl;
}


// ------------------------------
// Main function
// ------------------------------

int main() {
    explainVector();
    return 0;
}