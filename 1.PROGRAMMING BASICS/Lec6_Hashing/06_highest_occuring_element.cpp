#include <bits/stdc++.h>
using namespace std;

int highestOccuringElement(vector<int> &nums){
    // Create an unordered_map to store the frequency of each number.
    unordered_map<int, int> freq;
    // Iterate through the input vector 'nums' to populate the frequency map.
    for(int num : nums){
        freq[num]++;
    }

    // Initialize maxFreq to 0 to keep track of the maximum frequency found so far.
    int maxFreq = 0;
    // Initialize result to INT_MAX. This will store the element with the highest frequency.
    // If multiple elements have the same highest frequency, the smallest element will be chosen.
    int result = INT_MAX;

    // Iterate through the frequency map to find the element with the highest frequency.
    for(auto &p : freq){
        // 'element' is the number (key) and 'count' is its frequency (value).
        int element = p.first;
        int count = p.second;
        // If the current element's count is greater than maxFreq, update maxFreq and result.
        // If the current element's count is equal to maxFreq, but the element itself is smaller,
        // update result to choose the smallest element among those with the highest frequency.
        if(count > maxFreq || (count == maxFreq && element < result)){
            maxFreq = count;
            result = element;
        }
    }
    // Return the element with the highest frequency (or the smallest among them if ties).
    return result;
}

int main(){
    // Example usage: Define an input vector of integers.
    vector<int> nums = {1,2,2,3,3,3};
    // Call the highestOccuringElement function to get the result.
    int answer = highestOccuringElement(nums);
    cout << "Highest occuring element: " << answer << endl;

    return 0;
}