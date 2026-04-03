//  Traversing a circular linked list iteratively

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

void printList(Node *head) {

    if(head == nullptr) return;

    Node *curr = head;

    do {
        cout << curr->data;
        if(curr->next != head) {
            cout << " -> ";
        }
        curr = curr->next;
    } while(curr != head);

    cout << endl;
}

int main() {
    Node *head = new Node(11);
    head->next = new Node(12);
    head->next->next = new Node(13);
    head->next->next->next = new Node(14);
    head->next->next->next->next = head;

    printList(head);

    return 0;
}