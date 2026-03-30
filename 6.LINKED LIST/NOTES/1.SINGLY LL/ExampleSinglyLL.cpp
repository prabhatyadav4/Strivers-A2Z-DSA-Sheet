// Creating an Example Linked List of Size 3 to Understand Working

#include <iostream>
using namespace std;

class Node {
    public:

        int data;
        Node* next;

        Node(int new_data) {
            this->data = new_data;
            this->next = nullptr;
        }
};

int main() {
    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}