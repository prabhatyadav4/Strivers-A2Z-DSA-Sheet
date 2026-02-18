/*
Lower Bound

Given a sorted array of nums and an integer x, write a program to find the lower bound of x.

The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

If no such index is found, return the size of the array.

Example 1

Input : nums= [1,2,2,3], x = 2

Output:1

Explanation:

Index 1 is the smallest index such that arr[1] >= x.

Example 2

Input : nums= [3,5,8,15,19], x = 9

Output: 3

Explanation:

Index 3 is the smallest index such that arr[3] >= x.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0, high = n - 1;
        int lb = n;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= x){
                lb = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return lb;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {3, 5, 8, 15, 19};
    int target = 9;

    cout << "The lower bound of the target is: " << obj.lowerBound(arr, target);

    return 0;
}