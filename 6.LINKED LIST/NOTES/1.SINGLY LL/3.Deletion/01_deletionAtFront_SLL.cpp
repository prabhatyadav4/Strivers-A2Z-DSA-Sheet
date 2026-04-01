// Deletion at beginning (Removal of first node) in a Linked List

#include <iostream>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

Node* deleteNode(Node* head) {
    if(head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

void printList(Node* curr) {
    while(curr != nullptr) {
        cout << curr->data;

        if(curr->next != nullptr) {
            cout << " -> ";
        }

        curr = curr->next;
    }
    
    cout << endl;
}

int main() {
    Node* head = new Node(8);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(7);

    head = deleteNode(head);

    printList(head);

    return 0;
}