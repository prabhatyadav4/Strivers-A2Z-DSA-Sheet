#include <iostream>
#include <map>
using namespace std;

int main(){
    // Declare an integer variable 'n' to store the size of the array.
    int n;
    cin >> n;
    // Declare an integer array 'arr' of size 'n'.
    int arr[n];
    // Declare a map 'mpp' to store the frequency of each number.
    map<int, int> mpp;
    // Loop to read array elements and populate the map with their frequencies.
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mpp[arr[i]]++;
    } 
    // Declare an integer variable 'q' to store the number of queries.
    int q;
    cin >> q;
    // Loop to process each query.
    while(q--){
        // Declare an integer variable 'number' to store the number to be searched.
        int number;
        cin >> number;
        // Loop through the map and print each key-value pair (number and its frequency).
        for(auto it : mpp){
            cout <<  it.first << " -> " << it.second << endl;
        }
    }
    return 0;
}