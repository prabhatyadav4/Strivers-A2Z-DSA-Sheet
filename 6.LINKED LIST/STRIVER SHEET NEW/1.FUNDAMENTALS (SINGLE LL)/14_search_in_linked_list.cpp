/*
1039. Search in Linked List

You are given the head of a singly linked list and an integer key.

Return true if the key exists in the linked list, otherwise return false.

Example 1:
Input: head = [1, 2, 3, 4], key = 3
Output: true
Explanation: The linked list is 1 → 2 → 3 → 4. The key 3 is present in the list.

Example 2:
Input: head = [7, 8, 9, 10, 11], key = 5
Output: false

Explanation: The key 5 is not present in the list.

Constraints:
The number of nodes in the linked list is in the range 1 <= n <= 10⁵.
The value of each node is in the range 1 <= Node.val <= 10⁵.
1 <= key <= 10⁵
*/

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

bool searchKey(Node *head, int key)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Element present in present in LL (true or false): " << boolalpha << searchKey(head, 4) << endl;

    return 0;
}