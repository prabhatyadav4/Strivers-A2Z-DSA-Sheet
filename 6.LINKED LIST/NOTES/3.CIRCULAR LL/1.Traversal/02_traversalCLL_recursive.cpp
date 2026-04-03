//  Traversing a circular linked list recursively

#include <iostream>
using namespace std;

class Node {
    public:

        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            this->next = nullptr;
        }
};

void printList(Node *curr, Node *head) {
    if(head == nullptr) return;

    cout << curr->data;

    if(curr->next != head) {
        cout << " -> ";
    }

    if(curr->next == head) {
        return;
    }

    printList(curr->next, head);
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    printList(head, head);

    return 0;
}