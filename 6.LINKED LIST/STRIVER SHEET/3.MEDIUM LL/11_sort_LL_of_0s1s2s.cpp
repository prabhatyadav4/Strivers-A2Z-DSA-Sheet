/*
Sort a Linked List of 0's 1's and 2's

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

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

Node *BruteSortList0s1s2s(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while (temp != nullptr)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;

        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }

    return head;
}

Node *OptimalSortList0s1s2s(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *dummyZero = new Node(-1);
    Node *dummyOne = new Node(-1);
    Node *dummyTwo = new Node(-1);

    Node *zero = dummyZero;
    Node *one = dummyOne;
    Node *two = dummyTwo;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (dummyOne->next) ? (dummyOne->next) : (dummyTwo->next);
    one->next = dummyTwo->next;
    two->next = nullptr;

    Node *newHead = dummyZero->next;

    delete dummyZero;
    delete dummyOne;
    delete dummyTwo;

    return newHead;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printList(head);

    // head = BruteSortList0s1s2s(head);
    // cout << "BRUTE: Sorted Linked List: ";
    // printList(head);

    head = OptimalSortList0s1s2s(head);
    cout << "OPTIMAL: Sorted Linked List: ";
    printList(head);

    return 0;
}