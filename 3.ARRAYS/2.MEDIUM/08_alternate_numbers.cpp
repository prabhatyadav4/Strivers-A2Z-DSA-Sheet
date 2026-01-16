/*
Alternate Numbers

Problem statement
There is an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.

Without altering the relative order of positive and negative numbers, you must return an array of alternative positive and negative values.

Note:

Start the array with a positive number. 
For example

Input:
A = [1, 2, -4, -5], N = 4
Output:
1 -4  2 -5
Explanation: 
Positive elements = 1, 2
Negative elements = -4, -5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> alternateNumbers(vector<int>& a) {

    vector<int> pos, neg;
    int n = a.size();

    // Separate positive and negative numbers
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }

    // Case 1: More positives than negatives
    if(pos.size() > neg.size()) {

        // Place alternating elements
        for(int i = 0; i < neg.size(); i++){
            a[2*i]   = pos[i];
            a[2*i+1] = neg[i];
        }

        // Place remaining positives
        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size(); i++){
            a[index++] = pos[i];
        }
    }
    // Case 2: More negatives or equal
    else {

        // Place alternating elements
        for(int i = 0; i < pos.size(); i++){
            a[2*i]   = pos[i];
            a[2*i+1] = neg[i];
        }

        // Place remaining negatives
        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++){
            a[index++] = neg[i];
        }
    }

    return a;
}

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4, 2, 5};

    cout << "The Alternate Numbers are: ";
    for(int x : alternateNumbers(arr)){
        cout << x << " ";
    }

    return 0;
}