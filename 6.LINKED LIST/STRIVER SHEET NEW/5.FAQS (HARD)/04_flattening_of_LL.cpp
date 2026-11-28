/*
Flatten Linked List

In a linked list, every node has two pointers: next and bottom. The heads of n linked lists are connected using the next pointer, while the bottom pointer points to the next node in the current linked list.

Each linked list is sorted in non-decreasing order of data, and the head nodes are also sorted in non-decreasing order.

Given the head of the first linked list, flatten the linked lists into a single sorted linked list such that every node is connected using only the bottom pointers.

Examples:

Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.

Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.

Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50

Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 30 and so on.
So, after flattening the linked list the sorted list will be
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.

Constraints:
0 ≤ n ≤ 104
head.size() = n
1 ≤ head[i].size() ≤ 50
1 ≤ head[i][j] ≤ 5*105
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int val)
    {
        data = val;
        next = nullptr;
        bottom = nullptr;
    }
};

// Approach 1: Recursion and Merging
// Time: O(N * N * M)
// Space: O(N) recursive stack

Node *merge(Node *head1, Node *head2)
{
    Node dummy(-1);
    Node *temp = &dummy;

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            temp->bottom = head1;
            head1 = head1->bottom;
        }
        else
        {
            temp->bottom = head2;
            head2 = head2->bottom;
        }

        temp = temp->bottom;
    }

    temp->bottom = (head1) ? head1 : head2;

    return dummy.bottom;
}

Node *flattenI(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    head->next = flattenI(head->next);

    head = merge(head, head->next);

    return head;
}

// Approach 2: Sorting
// Time: O(N*M * log(N*M))
// Space: O(N*M)

Node *flattenII(Node *head)
{
    vector<int> values;

    Node *temp = head;

    while (temp != nullptr)
    {
        values.push_back(temp->data);

        Node *bottomTemp = temp->bottom;

        while (bottomTemp != nullptr)
        {
            values.push_back(bottomTemp->data);
            bottomTemp = bottomTemp->bottom;
        }

        temp = temp->next;
    }

    sort(values.begin(), values.end());

    Node *newHead = nullptr;
    Node *tail = nullptr;

    for (int val : values)
    {
        Node *newNode = new Node(val);

        if (newHead == nullptr)
        {
            newHead = newNode;
        }
        else
        {
            tail->bottom = newNode;
        }

        tail = newNode;
    }

    return newHead;
}

// Approach 3: Min Heap
// Time: O(N*M * log(N))
// Space: O(N)

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *flattenIII(Node *head)
{
    if (head == nullptr)
        return nullptr;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    Node *tempHead = head;

    while (tempHead != nullptr)
    {
        pq.push(tempHead);
        tempHead = tempHead->next;
    }

    Node dummy(-1);
    Node *temp = &dummy;

    while (!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();

        if (curr->bottom != nullptr)
        {
            pq.push(curr->bottom);
        }

        temp->bottom = curr;
        temp = curr;

        temp->next = nullptr;
    }

    temp->bottom = nullptr;

    return dummy.bottom;
}

// Create linked list
Node *createList()
{
    Node *head = new Node(5);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    return head;
}

// Print flattened linked list
void printList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->bottom != nullptr)
            cout << " -> ";

        temp = temp->bottom;
    }

    cout << endl;
}

int main()
{
    // Approach 1: Recursion and Merging
    Node *head1 = createList();

    cout << "Approach 1 - Recursion and Merging:" << endl;
    head1 = flattenI(head1);
    printList(head1);

    cout << endl;

    // Approach 2: Sorting
    Node *head2 = createList();

    cout << "Approach 2 - Sorting:" << endl;
    head2 = flattenII(head2);
    printList(head2);

    cout << endl;

    // Approach 3: Min Heap
    Node *head3 = createList();

    cout << "Approach 3 - Min Heap:" << endl;
    head3 = flattenIII(head3);
    printList(head3);

    return 0;
}