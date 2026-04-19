/*
Flattening of LL

Given a special linked list containing n head nodes where every node in the linked list contains two pointers:
‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer.

Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.


Example:
Input:
5 -> 14
10 -> 4
12 -> 20 -> 13
7 -> 17

Output:
4 5 7 10 12 13 14 17 20

Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node class representing each element in the linked list with data, next, and child pointers
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
        this->child = nullptr;
    }
};

// Function to convert a vector of integers into a linked list using the child pointer
Node *vectorToLL(vector<int> &ans)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    for (int i = 0; i < ans.size(); i++)
    {
        temp->child = new Node(ans[i]);
        temp = temp->child;
    }

    Node *head = dummy->child;
    delete dummy;
    return head;
}

// Brute force approach: Collect all node values into a vector, sort it, and reconstruct the list
Node *BruteFlattenLinkedList(Node *head)
{
    if (head == nullptr)
        return head;

    vector<int> ans;
    Node *temp1 = head;

    // Traverse through each level (next pointers) and collect all child nodes' data
    while (temp1 != nullptr)
    {
        Node *temp2 = temp1;

        while (temp2 != nullptr)
        {
            ans.push_back(temp2->data);
            temp2 = temp2->child;
        }

        temp1 = temp1->next;
    }

    sort(ans.begin(), ans.end());

    return vectorToLL(ans);
}

// Helper function to merge two sorted linked lists using the child pointer
Node *mergeLists(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *res = dummy;

    // Merge the two lists by comparing data values
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;  // Ensure next pointer is null as we're flattening
    }
    // Append the remaining list
    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    Node *head = dummy->child;
    delete dummy;
    return head;
}

// Optimal approach: Recursively flatten by merging current list with the flattened next list
Node *OptimalFlattenLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // Recursively flatten the next part and merge with current
    Node *mergedHead = OptimalFlattenLinkedList(head->next);
    head = mergeLists(head, mergedHead);

    return head;
}

// Function to print the flattened linked list using child pointers
void printList(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data;
        if (temp->child != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->child;
    }
    cout << endl;
}

int main()
{
    // Create the sample linked list as per the example
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // Uncomment to use brute force approach
    // head = BruteFlattenLinkedList(head);
    // cout << "Flattened Linked List: ";
    // printList(head);

    // Use optimal approach
    head = OptimalFlattenLinkedList(head);
    cout << "Flattened Linked List: ";
    printList(head);

    return 0;
}