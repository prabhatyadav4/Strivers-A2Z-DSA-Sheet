/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

bool BruteIsPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *temp = head;
    stack<int> st;

    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (st.top() != temp->data)
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }

    return true;
}

Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *curr = head, *prev = nullptr, *front = nullptr;

    while (curr != nullptr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

bool OptimalIsPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *slow = head, *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseList(slow->next);

    Node *first = head;
    Node *second = newHead;

    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            reverseList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseList(newHead);

    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    if (BruteIsPalindrome(head))
    {
        cout << "BRUTE: The Linked List is Palindrome." << endl;
    }
    else
    {
        cout << "BRUTE: The Linked List is not Palindrome." << endl;
    }

    if (OptimalIsPalindrome(head))
    {
        cout << "OPTIMAL: The Linked List is Palindrome." << endl;
    }
    else
    {
        cout << "OPTIMAL: The Linked List is not Palindrome." << endl;
    }

    return 0;
}