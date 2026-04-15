/*
Find Pairs with Given Sum in Doubly Linked List

Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.
Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.

Example 1
Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7
Output: [[1, 6], [2, 5]]

Explanation:
1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

Example 2
Input: head = [1, 5, 6], target = 6
Output: [[1, 5]]

Explanation:
1 + 5 = 6 is the only valid pair.


Constraints:
0 <= number of nodes <= 105
1 <= Node.val <= 105
1 <= target <= 105
The linked list is sorted in strictly increasing order
The linked list is contains distinct values
*/

#include <iostream>
#include <vector>
using namespace std;

// Node structure for doubly linked list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Brute force approach: O(n^2) time, O(1) space
// Compares each node with all subsequent nodes to find pairs
vector<vector<int>> BruteFindPairsWithGivenSum(Node *head, int target)
{
    vector<vector<int>> ans;

    if (head == nullptr)
        return ans;

    // Outer loop: iterate through each node
    Node *temp1 = head;

    while (temp1 != nullptr)
    {
        // Inner loop: check all nodes after temp1
        Node *temp2 = temp1->next;

        while (temp2 != nullptr && temp1->data + temp2->data <= target)
        {
            // Found a valid pair
            if (temp1->data + temp2->data == target)
            {
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return ans;
}

// Helper function: find the last node (tail) of the linked list
Node *findTail(Node *head)
{
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    return tail;
}

// Optimal approach: Two-pointer technique, O(n) time, O(1) space
// Uses left pointer at head and right pointer at tail
vector<vector<int>> OptimalFindPairsWithGivenSum(Node *head, int target)
{
    vector<vector<int>> ans;

    if (head == nullptr)
        return ans;

    // Initialize two pointers
    Node *left = head;
    Node *right = findTail(head);

    // Move pointers towards each other
    while (left != right && left->prev != right)
    {
        int sum = left->data + right->data;

        if (sum == target)
        {
            // Found a valid pair, move both pointers
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            // Sum is too small, move left pointer right
            left = left->next;
        }
        else
        {
            // Sum is too large, move right pointer left
            right = right->prev;
        }
    }

    return ans;
}

// Utility function: print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    cout << "[";
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << ", ";
        }
        temp = temp->next;
    }
    cout << "]" << endl;
}

int main()
{
    // Create doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;

    int target = 7;

    // Test brute force approach
    vector<vector<int>> result1;
    cout << "Example 1: BRUTE" << endl;
    cout << "Input: head = ";
    printList(head);
    cout << "Target: " << target << endl;
    cout << "Output: ";
    result1 = BruteFindPairsWithGivenSum(head, target);
    for (auto &p : result1)
    {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << endl;

    // Test optimal approach
    vector<vector<int>> result2;
    cout << "Example 2: OPTIMAL" << endl;
    cout << "Input: head = ";
    printList(head);
    cout << "Target: " << target << endl;
    cout << "Output: ";
    result2 = OptimalFindPairsWithGivenSum(head, target);
    for (auto &p : result2)
    {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << endl;

    return 0;
}