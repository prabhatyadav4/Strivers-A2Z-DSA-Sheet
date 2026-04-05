/*
Search in Linked List

You are given the head of a singly linked list and an integer key.

Return true if the key exists in the linked list, otherwise return false.


Example 1

Input: head = [1, 2, 3, 4], key = 3

Output: true

Explanation: The linked list is 1 → 2 → 3 → 4. The key 3 is present in the list.

Example 2

Input: head = [7, 8, 9, 10, 11], key = 5

Output: false

Explanation: The key 5 is not present in the list.
*/

#include <iostream>
using namespace std;

class ListNode
{

public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
public:
    bool searchKey(ListNode *head, int key)
    {
        // Your code goes here
        while (head != nullptr)
        {
            if (head->data == key)
            {
                return true;
            }
            head = head->next;
        }

        return false;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Key found: " << ((obj.searchKey(head, 30) == 1) ? "True" : "False");

    return 0;
}