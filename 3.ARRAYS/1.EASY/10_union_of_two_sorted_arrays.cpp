/*
Union of two sorted arrays

Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.



The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.


Example 1

Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation:

The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Example 2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation:

The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

    vector<int> BruteunionArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums1[i]);
        }

        for(int i = 0; i < m; i++){
            st.insert(nums2[i]);
        }

        vector<int> temp;

        for(auto it : st){
            temp.push_back(it);
        }

        return temp;
    }

    vector <int> OptimalunionArray(vector <int> &a, vector <int> &b) {
    // Write your code here
        int n = a.size();
        int m = b.size();

        int i = 0;
        int j = 0; 

        vector<int> unionArr;

        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                if(unionArr.size() == 0 || unionArr.back() != a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else {
                if(unionArr.size() == 0 || unionArr.back() != b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }

        while(i < n) {
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }

        while(j < m) {
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }

        return unionArr;
    }

};

int main() {

    Solution obj;

    vector<int> a = {1,1,2,3,3,4,5,6};
    vector<int> b = {1,2,2,3,4,6,7};
    vector<int> c = {1,1,2,3,3,4,5,6};
    vector<int> d = {1,2,2,3,4,6,7,8};

    vector<int> UnionArray1 = obj.BruteunionArray(a,b);
    cout << "Union Array (Brute): ";
    for(auto x : UnionArray1){
        cout << x << " ";
    }

    vector<int> UnionArray2 = obj.OptimalunionArray(c,d);
    cout << "\nUnion Array (Optimal): ";
    for(auto y : UnionArray2){
        cout << y << " ";
    }

    return 0;
}