// Problem: Delete a node at a given 1-based position from a doubly linked list.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node *deleteNode(Node *head, int k)
{
    if (head == nullptr || k <= 0)
    {
        return head;
    }

    Node *temp = head;

    for (int i = 1; i < k; i++)
    {
        if (temp == nullptr)
        {
            return head;
        }

        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return head;
    }

    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head = deleteNode(head, 3);

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
        {
            cout << "<->";
        }

        temp = temp->next;
    }

    return 0;
}