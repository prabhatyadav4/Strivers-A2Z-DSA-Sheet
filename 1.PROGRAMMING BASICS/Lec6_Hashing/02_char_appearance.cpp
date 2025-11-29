#include <iostream>
using namespace std;

int main(){
    string s;
    // Read input string
    cin >> s;
    // Pre-compute character frequencies
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++){
        // Increment count for current character
        hash[s[i]]++;
    }
    int q;
    // Read number of queries
    cin >> q;
    while(q--){
        char c;
        // Read character for query
        cin >> c;
        // Fetch and print frequency
        cout << hash[c] << endl;
    }

    return 0;
} 