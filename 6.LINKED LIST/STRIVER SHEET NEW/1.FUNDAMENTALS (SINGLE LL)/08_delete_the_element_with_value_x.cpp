// Problem: Delete the first node containing value X.

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

Node *deleteValueX(Node *head, int X)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->data == X)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->next->data == X)
        {
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
            return head;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);

    head = deleteValueX(head, 3);

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