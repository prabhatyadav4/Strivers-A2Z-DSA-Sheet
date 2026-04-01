// Search an element in a Linked List - Recursive Approach

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

bool searchKey(Node* head, int key) {
    if(head == nullptr) return false;

    if(head->data == key)   return true;

    return searchKey(head->next, key);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int key = 3;

    searchKey(head, key) ? cout << "True" : cout << "False";

    return 0;
}