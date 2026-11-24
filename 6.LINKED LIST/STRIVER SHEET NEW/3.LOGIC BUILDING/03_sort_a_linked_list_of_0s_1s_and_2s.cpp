/*
778. Sort a Linked List of 0's 1's and 2's

Given the head of a singly linked list consisting of only 0, 1 or 2.

Sort the given linked list and return the head of the modified list.

Do it in-place by changing the links between the nodes without creating new nodes.

Example 1:
Input: linkedList = [1, 0, 2, 0 , 1]

Output: [0, 0, 1, 1, 2]

Explanation: The values after sorting are [0, 0, 1, 1, 2].

Example 2:
Input: linkedList = [1, 1, 1, 0]

Output: [0, 1, 1, 1]

Explanation: The values after sorting are [0, 1, 1, 1].

Constraints:
0 <= number of nodes in the Linked List <= 105
0 <= ListNode.val <= 2
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

Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            count0++;
        }

        else if (temp->data == 1)
        {
            count1++;
        }

        else
        {
            count2++;
        }

        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (count0 > 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 > 0)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    head = sortList(head);

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
        {
            cout << "->";
        }

        temp = temp->next;
    }

    return 0;
}