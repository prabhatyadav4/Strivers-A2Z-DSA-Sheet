#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countFrequencies(vector<int> &nums){
    // Create an unordered_map to store the frequency of each number.
    unordered_map<int,int> freq;
    // Iterate through the input vector 'nums' to populate the frequency map.
    for(int num : nums){
        freq[num]++;
    }
    // Create a vector of vectors to store the result (number and its frequency).
    vector<vector<int>> result;
    // Iterate through the frequency map.
    for(auto &p : freq){
        // For each key-value pair (number, frequency), add it as a sub-vector to the result.
        result.push_back({p.first, p.second});
    }
    // Return the vector containing number-frequency pairs.
    return result;
}

int main(){
    // Example usage: Define an input vector of integers.
    vector<int> nums = {1,2,2,1,3};
    // Call the countFrequencies function to get the frequencies.
    vector<vector<int>> output = countFrequencies(nums);
    cout << "Frequencies\n";
    // Print the frequencies in a readable format.
    for(auto &pair : output){
        cout << "[" << pair[0] << "," << pair[1] << "]\n";
    }
    return 0;
}