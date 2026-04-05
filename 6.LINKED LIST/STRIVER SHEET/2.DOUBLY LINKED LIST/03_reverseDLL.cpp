/*
Reverse a Doubly Linked List

You are given the head of a doubly linked list.

Reverse the list in-place and return the new head of the reversed list.

Example 1

Input: head = [10, 20, 30]

Output:﻿ [30, 20, 10]

Example 2

Input: head = [1, 3, 5, 7, 9]

Output: [9, 7, 5, 3, 1]
*/

#include <iostream>
#include <stack>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

class Solution
{
public:
    ListNode *BruteReverseDLL(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        stack<int> st;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

    ListNode *OptimalReverseDLL(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;

            head = curr;
            curr = temp;
        }

        return head;
    }

    void printList(ListNode *head)
    {
        ListNode *curr = head;

        while (curr != nullptr)
        {
            cout << curr->data;
            if (curr->next != nullptr)
            {
                cout << " <-> ";
            }
            curr = curr->next;
        }

        cout << endl;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->prev = head;
    head->next->next = new ListNode(4);
    head->next->next->prev = head->next;

    cout << "Original Linked List: ";
    obj.printList(head);

    cout << "Reversed Linked List: ";
    // head = obj.BruteReverseDLL(head);
    head = obj.OptimalReverseDLL(head);

    obj.printList(head);

    return 0;
}