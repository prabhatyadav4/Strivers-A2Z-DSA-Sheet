/*
160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.



Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.

Example 2:

Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Example 3:

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.


Constraints:
The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure for linked list
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

// Brute Force: Compare each node of head1 with all nodes of head2
// Time: O(m*n), Space: O(1)
Node *BruteIntersectionNode(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    // Traverse head1 and for each node, traverse head2
    while (head1 != nullptr)
    {
        Node *temp = head2;
        while (temp != nullptr)
        {
            // Check if nodes point to same memory location
            if (temp == head1)
                return head1;
            temp = temp->next;
        }
        head1 = head1->next;
    }

    return nullptr;
}

// Better: Use hash set to store all nodes of head1
// Time: O(m+n), Space: O(m)
Node *BetterIntersectionNode(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    unordered_set<Node *> st;

    // Store all nodes of head1 in hash set
    while (head1 != nullptr)
    {
        st.insert(head1);
        head1 = head1->next;
    }

    // Check if any node from head2 exists in hash set
    while (head2 != nullptr)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }

    return nullptr;
}

// Calculate difference in lengths of two lists
int getDifference(Node *head1, Node *head2)
{
    int len1 = 0, len2 = 0;

    while (head1 != nullptr || head2 != nullptr)
    {
        if (head1 != nullptr)
        {
            len1++;
            head1 = head1->next;
        }

        if (head2 != nullptr)
        {
            len2++;
            head2 = head2->next;
        }
    }

    return len1 - len2;
}

// Optimal1: Skip extra nodes in longer list, then traverse both together
// Time: O(m+n), Space: O(1)
Node *Optimal1IntersectionNode(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    int difference = getDifference(head1, head2);

    // Skip extra nodes in longer list
    if (difference < 0)
    {
        while (difference++ != 0)
            head2 = head2->next;
    }
    else
    {
        while (difference-- != 0)
            head1 = head1->next;
    }

    // Traverse both lists and find intersection
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

// Optimal2: Two pointer approach - swap pointers after reaching end
// Time: O(m+n), Space: O(1)
Node *Optimal2IntersectionNode(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;

    // When temp1 reaches end, move to head2; when temp2 reaches end, move to head1
    // Both pointers will meet at intersection point or nullptr
    while (temp1 != temp2)
    {
        temp1 = temp1 == nullptr ? head2 : temp1->next;
        temp2 = temp2 == nullptr ? head1 : temp2->next;
    }

    return temp1; // intersection or nullptr
}

int main()
{
    // Create first linked list: 4 -> 1 -> 8 -> 4 -> 5
    Node *head1 = new Node(4);
    head1->next = new Node(1);
    head1->next->next = new Node(8);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Create second linked list: 5 -> 6 -> 1 -> (intersects with first list at node 8)
    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);
    head2->next->next->next = head1->next->next; // Intersection point

    // Test all four approaches
    Node *ansNode = BruteIntersectionNode(head1, head2);
    if (ansNode == nullptr)
        cout << "BRUTE: No intersection\n";
    else
        cout << "BRUTE: The intersectAion point is " << ansNode->data << endl;

    ansNode = BetterIntersectionNode(head1, head2);
    if (ansNode == nullptr)
        cout << "BETTER: No intersection\n";
    else
        cout << "BETTER: The intersection point is " << ansNode->data << endl;

    ansNode = Optimal1IntersectionNode(head1, head2);
    if (ansNode == nullptr)
        cout << "OPTIMAL1: No intersection\n";
    else
        cout << "OPTIMAL1: The intersection point is " << ansNode->data << endl;

    ansNode = Optimal2IntersectionNode(head1, head2);
    if (ansNode == nullptr)
        cout << "OPTIMAL2: No intersection\n";
    else
        cout << "OPTIMAL2: The intersection point is " << ansNode->data << endl;

    return 0;
}