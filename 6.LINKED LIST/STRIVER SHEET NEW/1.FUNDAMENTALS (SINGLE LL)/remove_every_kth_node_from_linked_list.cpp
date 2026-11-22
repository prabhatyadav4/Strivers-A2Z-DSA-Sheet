/*
Remove Every k'th in Linked List

Given a singly linked list head ,  your task is to remove every kth node from the linked list.

Note: If head is equal to null the driver code will print -1.

Examples:
Input: 1->2->3->4->5->6->null , k = 2
Output: 1->3->5->null
Explanation: After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5.

Constraints:
1 ≤ size of linked list, Node.data ≤ 106
1 ≤ k ≤ head.size()
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

Node *deleteEveryKthNode(Node *head, int K)
{
    if (head == nullptr || K == 1)
    {
        return head;
    }

    Node *temp = head;

    int count = 1;

    while (temp != nullptr && temp->next != nullptr)
    {
        if ((count + 1) % K == 0)
        {
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
        }
        else
        {
            temp = temp->next;
        }

        count++;
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head = deleteEveryKthNode(head, 2);

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