// Problem: Delete the head node of a singly linked list.

// Time Complexity: O(1)
// Space Complexity: O(1)

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

Node *deleteHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;

    delete temp;

    return head;
}

int main()
{
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);

    head = deleteHead(head);

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