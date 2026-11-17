/*
Remove Duplicates from Sorted Array

Problem statement
You are given a sorted integer array 'arr' of size 'n'.

You need to remove the duplicates from the array such that each element appears only once.

Return the length of this new array.

Note:
Do not allocate extra space for another array. You need to do this by modifying the given input array in place with O(1) extra memory.


For example:
'n' = 5, 'arr' = [1 2 2 2 3].
The new array will be [1 2 3].
So our answer is 3.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int BruteRemoveDuplicates(vector<int> &arr, int n)
{
	set<int> st;

	for (int i = 0; i < n; i++)
	{
		st.insert(arr[i]);
	}

	int i = 0;

	for (auto it : st)
	{
		arr[i] = it;
		i++;
	}

	return i;
}

int OptimalRemoveDuplicates(vector<int> &arr, int n)
{
	if (n == 0)
	{
		return 0;
	}

	int i = 0;

	for (int j = 1; j < n; j++)
	{
		if (arr[i] != arr[j])
		{
			i++;
			arr[i] = arr[j];
		}
	}

	return i + 1;
}

int main()
{
	vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 4};
	vector<int> optimalArr = arr;

	cout << "BRUTE: The number of distinct elements in the sorted is: " << BruteRemoveDuplicates(arr, arr.size()) << endl;

	cout << "OPTIMAL: The number of distinct elements in the sorted is: " << OptimalRemoveDuplicates(optimalArr, optimalArr.size()) << endl;

	return 0;
}