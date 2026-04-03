//  Deletion from the beginning of the circular linked list - O(1) Time and O(1) Space

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

Node *deletionAtFront(Node *last) {
    if(last == nullptr) {
        return nullptr;
    }

    Node *head = last->next;

    if(head == last) {
        delete head;
        last = nullptr;
    }
    else {
        last->next = head->next;
        delete head;
    }

    return last;
}

void printList(Node *last) {
    Node *head = last->next;
    Node *temp = head;

    do {
        cout << temp->data;
        if(temp->next != head) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    Node *last = head->next->next->next;
    last->next = head;

    last = deletionAtFront(last);
    printList(last);

    return 0;
}