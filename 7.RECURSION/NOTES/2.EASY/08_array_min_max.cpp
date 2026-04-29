/*
Min and Max in Array

Given an array arr[]. Your task is to find the minimum and maximum elements in the array.

Examples:

Input: arr[] = [1, 4, 3, 5, 8, 6]
Output: [1, 8]
Explanation: minimum and maximum elements of array are 1 and 8.

Input: arr[] = [12, 3, 15, 7, 9]
Output: [3, 15]
Explanation: minimum and maximum element of array are 3 and 15.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getMinMaxRec(vector<int> &arr, int index) {
    if(index == 0) return {arr[0], arr[0]};

    vector<int> result = getMinMaxRec(arr, index - 1);

    // Check Min
    if(arr[index] < result[0])  result[0] = arr[index];
    // Check Max
    if(arr[index] > result[1])  result[1] = arr[index];

    return result;
}

int main() {
    vector<int> arr = {1, 4, 3, -5, 8, 6};
    vector<int> result = getMinMaxRec(arr, arr.size() - 1);
    cout << "Min Element: " << result[0] << " Max Element: " << result[1] << endl;

    return 0;
}