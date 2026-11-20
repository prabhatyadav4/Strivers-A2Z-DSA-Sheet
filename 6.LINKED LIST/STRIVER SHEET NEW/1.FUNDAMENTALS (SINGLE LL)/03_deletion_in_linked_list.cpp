// Problem: Delete a node from the linked list at a given 1-based position.

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
        this->data = val;
        this->next = nullptr;
    }
};

Node *deleteNode(Node *head, int position)
{
    if (head == nullptr || position <= 0)
    {
        return head;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        if (temp == nullptr)
        {
            return head;
        }

        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        return head;
    }

    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int position = 4;

    head = deleteNode(head, position);

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