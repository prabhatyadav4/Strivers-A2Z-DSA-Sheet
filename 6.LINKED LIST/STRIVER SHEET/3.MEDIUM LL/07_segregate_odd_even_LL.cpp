/*
328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
*/

#include <iostream>
#include <vector>
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

Node *BruteOddEvenList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    vector<int> arr;
    Node *temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        arr.push_back(temp->data);

    temp = head->next;

    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        arr.push_back(temp->data);

    int i = 0;
    temp = head;

    while (temp != nullptr)
    {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }

    return head;
}

Node *OptimalOddEvenList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

    return head;
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "BRUTE: The reordered list is: ";
    head = BruteOddEvenList(head);
    printList(head);

    cout << "OPTIMAL: The reordered list is: ";
    head = OptimalOddEvenList(head);
    printList(head);

    return 0;
}