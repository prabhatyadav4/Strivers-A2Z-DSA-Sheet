/*
876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *BruteFindMiddle(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2 + 1;
    temp = head;

    while (temp != nullptr)
    {
        mid = mid - 1;
        if (mid == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node *OptimalFindMiddle(Node *head)
{
    Node *slowptr = head;
    Node *fastptr = head;

    while (fastptr != nullptr && fastptr->next != nullptr)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }

    return slowptr;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *middleNode1 = BruteFindMiddle(head);
    cout << "The middle node value is: " << middleNode1->data << endl;

    Node *middleNode2 = OptimalFindMiddle(head);
    cout << "The middle node value is: " << middleNode2->data << endl;

    return 0;
}