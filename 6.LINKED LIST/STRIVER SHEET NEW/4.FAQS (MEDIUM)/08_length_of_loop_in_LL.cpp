/*
769. Length of loop in LL

Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.

A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.

Note that pos is not passed as a parameter.

Example 1:
Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

Output: 4

Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

Example 2:
Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

Output: 0

Explanation: No loop is present in the linked list.

Constraints:
0 <= number of nodes in the cycle <= 105
0 <= ListNode.val <= 104
pos is -1 or a valid index in the linked list
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

int findLengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int count = 1;
            Node *current = slow->next;

            while (current != slow)
            {
                count++;
                current = current->next;
            }

            return count;
        }
    }

    return 0;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;

    cout << "The Length of loop is: " << findLengthOfLoop(head);

    return 0;
}