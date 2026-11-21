// Problem: Delete the Kth node from a singly linked list.
// Positions are 1-based.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *deleteKth(Node *head, int k)
{
    if (head == nullptr || k <= 0)
        return head;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;

    for (int i = 1; i < k - 1; i++)
    {
        if (temp == nullptr)
            return head;

        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
        return head;

    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = deleteKth(head, 3);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
