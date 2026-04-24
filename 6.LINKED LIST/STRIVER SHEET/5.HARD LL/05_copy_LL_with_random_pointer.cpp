/*
138. Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
- val: an integer representing Node.val
- random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.



Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]


Constraints:
0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Node class definition for the linked list with a random pointer.
class Node
{
public:
    int data;      // Value stored in the node
    Node *next;    // Pointer to the next node in the list
    Node *random;  // Random pointer that can point to any node or null

    // Constructor to initialize a node with a value.
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
        this->random = nullptr;
    }
};

// Helper function to find the corresponding node in the copied list.
// Traverses both original and copied lists in parallel until the original node
// matches the target random pointer node.
Node *find(Node *curr1, Node *curr2, Node *x)
{
    if (x == nullptr)
        return nullptr;  // If random is null, return null

    while (curr1 != x)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr2;  // Return the corresponding copied node
}

// Brute-force approach to copy the linked list with random pointers.
// Time complexity: O(n^2) because `find` is called for each node.
Node *BruteCopyRandomList(Node *head)
{
    // Step 1: Create a dummy head for the copied list.
    Node *headCopy = new Node(-1);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Traverse the original list and create new nodes for the copy (only next pointers).
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    // Remove the dummy head and set headCopy to the actual first copied node.
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Step 2: Set up random pointers using the helper function.
    tailCopy = headCopy;
    temp = head;
    while (temp)
    {
        tailCopy->random = find(head, headCopy, temp->random);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    return headCopy;  // Return the head of the copied list.
}

// Better approach using an unordered_map to directly map original nodes to copied nodes.
Node *BetterCopyRandomList(Node *head)
{
    // Step 1: Create the copied nodes list with next pointers only.
    Node *headCopy = new Node(-1);
    Node *tailCopy = headCopy;
    Node *temp = head;

    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Step 2: Build a mapping from original nodes to copied nodes.
    tailCopy = headCopy;
    temp = head;
    unordered_map<Node *, Node *> mp;
    while (temp)
    {
        mp[temp] = tailCopy;
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    // Step 3: Assign random pointers using the mapping.
    tailCopy = headCopy;
    temp = head;
    while (temp)
    {
        tailCopy->random = mp[temp->random];
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    return headCopy;  // Return the head of the copied list.
}

// Step 1 of the optimal approach: insert copied nodes immediately after original nodes.
void insertCopyInBetween(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *nextElement = temp->next;
        Node *copy = new Node(temp->data);
        copy->next = nextElement;
        temp->next = copy;
        temp = nextElement;
    }
}

// Step 2 of the optimal approach: connect the random pointers of the copied nodes.
void connectRandomPointers(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *copyNode = temp->next;
        if (temp->random)
        {
            copyNode->random = temp->random->next;
        }
        else
        {
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

// Step 3 of the optimal approach: separate the copied list from the original list.
Node *getDeepCopyList(Node *head)
{
    Node *temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (temp != nullptr)
    {
        res->next = temp->next;         // Link copied node to the new list
        res = res->next;
        temp->next = temp->next->next;  // Restore original list
        temp = temp->next;
    }

    Node *newHead = dummyNode->next;
    delete dummyNode;
    return newHead;
}

// Optimal approach: interleave copied nodes, set randoms, then split lists.
Node *OptimalCopyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

// Function to print the linked list with random pointers in the required format.
void printList(Node *head)
{
    vector<Node *> nodes;
    Node *temp = head;

    // Store nodes for index lookup when printing random pointer indices.
    while (temp)
    {
        nodes.push_back(temp);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        cout << temp->data << " (";
        if (temp->random == nullptr)
        {
            cout << "null";
        }
        else
        {
            for (int i = 0; i < (int)nodes.size(); i++)
            {
                if (nodes[i] == temp->random)
                {
                    cout << i;
                    break;
                }
            }
        }
        cout << ") -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    // Creating the example linked list: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(11);
    Node *n4 = new Node(10);
    Node *n5 = new Node(1);

    // Link next pointers.
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Link random pointers.
    n1->random = nullptr;
    n2->random = n1;  // Points to index 0
    n3->random = n5;  // Points to index 4
    n4->random = n3;  // Points to index 2
    n5->random = n1;  // Points to index 0

    cout << "Original List:\n";
    printList(n1);

    // Copy the list using different approaches.
    Node *copiedHead1 = BruteCopyRandomList(n1);
    cout << "\nBRUTE: Copied List:\n";
    printList(copiedHead1);

    Node *copiedHead2 = BetterCopyRandomList(n1);
    cout << "\nBETTER: Copied List:\n";
    printList(copiedHead2);

    Node *copiedHead3 = OptimalCopyRandomList(n1);
    cout << "\nOPTIMAL: Copied List:\n";
    printList(copiedHead3);

    return 0;
}
