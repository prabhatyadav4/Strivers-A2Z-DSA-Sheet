/*
Book Allocation Problem

Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.

Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

Example 1

Input: nums = [12, 34, 67, 90], m=2

Output: 113

Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2

Input: nums = [25, 46, 28, 49, 24], m=4

Output: 71

Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
    public: 

    int countStudents(vector<int> &arr, int pages) {
        int n = arr.size();
        int students = 1;
        long long pagesStudent = 0;

        for(int i = 0; i < n; i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }
            else{
                students++;
                pagesStudent = arr[i];
            }
        }

        return students;
    }

    int BruteFindPages(vector<int> &arr, int n, int m) {
        if(m > n)   return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0LL);

        for(int pages = low; pages <= high; pages++){
            if(countStudents(arr, pages) <= m){
                return pages;
            }
        }

        return low;
    }

    int OptimalFindPages(vector<int> &arr, int n, int m){
        if(m > n)   return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0LL);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int studentsReq = countStudents(arr, mid);
            
            if(studentsReq <= m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;

    int result1 = obj.BruteFindPages(arr, n, m);
    cout << "The maximum number of pages (Brute) is: " << result1 << endl;

    int result2 = obj.OptimalFindPages(arr, n, m);
    cout << "The maximum number of pages (Optimal) is: " << result2 << endl;

    return 0;
}