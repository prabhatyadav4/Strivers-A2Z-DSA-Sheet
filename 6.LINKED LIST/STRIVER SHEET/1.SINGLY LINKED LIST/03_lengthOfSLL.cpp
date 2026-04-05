/*
Find the length of the Linked List

You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.

Example 1

Input: head = [1, 2, 3, 4, 5]

Output: 5

Example 2

Input: head = [8, 6]

Output: 2
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
    int getLength(ListNode *head)
    {
        // Your code goes here
        int count = 0;
        while (head != nullptr)
        {
            count++;
            head = head->next;
        }

        return count;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "The length of Linked List is: " << obj.getLength(head);

    return 0;
}