// Iterative Approach for Forward Traversal

#include <iostream>
using namespace std;

class Node {
    public:

        int data;
        Node *next;
        Node *prev;

        Node(int value) {
            this->data = value;
            this->next = nullptr;
            this->next = nullptr;
        }
};

void forwardTraversalIterative(Node *head) {
    Node *curr = head;

    while(curr != nullptr) {
        cout << curr->data;
        if(curr->next != nullptr) {
            cout << " <-> ";
        }
        curr = curr->next;
    }

    cout << endl;
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Forward Traversal (Iterative) : ";

    forwardTraversalIterative(head);

    return 0;
}