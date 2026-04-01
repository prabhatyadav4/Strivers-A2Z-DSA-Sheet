# Deletion in Singly Linked List

## Deletion at beginning (Removal of first node) in a Linked List

Given a head of the linked list, we need to remove the first node from the given linked list.

Examples:

Input :

![Deletion1](https://media.geeksforgeeks.org/wp-content/uploads/20250825115623535943/blobid2_1755951985.webp)

Output : 2 -> 3 -> 1 -> 7 -> NULL

Explanation: After deleting head from the given linked list, we'll be left with just 2 -> 3 -> 1 -> 7.

![Deletion2](https://media.geeksforgeeks.org/wp-content/uploads/20250825115623436503/blobid3_1755951992.webp)

By Shifting head node to next node of head - O(1) Time and O(1) Space

To remove the first node of a linked list:
- store the current head in a temporary variable (temp)
- move the head pointer to the next node
- delete the temporary head node and finally 
- return the new head of the linked list.

## Deletion at end (Removal of last node) in a Linked List

Given the head of a linked list, delete the last node of the given linked list.

Examples:  

Input: ![Deletion3](https://media.geeksforgeeks.org/wp-content/uploads/20250825111114618796/blobid2_1755947119.webp)

Output: ![Deletion4](https://media.geeksforgeeks.org/wp-content/uploads/20250825111114587377/blobid3_1755947241.webp)

Explanation: The last node of the linked list is 5, so 5 is deleted. 

Approach:

To perform the deletion operation at the end of linked list, we need to traverse the list to find the second last node, then set its next pointer to null. If the list is empty then there is no node to delete or has only one node then point head to null.

Step-by-step approach:

- Check if list is empty then return NULL.
- If the list has only one node then delete it and return NULL.
- Traverse the list to find the second last node.
- Set the next pointer of second last node to NULL.

## Delete Node by Position

Given the head of a singly linked list and a position (1-based index), delete the node at that position and return the updated head of the linked list.

Note: Position will be valid (i.e, 1 <= position <= linked list length)

Example:  

Input: position = 1

![Deletion5](https://media.geeksforgeeks.org/wp-content/uploads/20250825105436027695/blobid0_1755951344.webp)

Output: 2-> 3 -> 1-> 7 -> nullptr
Explanation:  After deleting the node at the 1st position (1-base indexing), the linked list is as

![Deletion6](https://media.geeksforgeeks.org/wp-content/uploads/20250825105435994183/blobid1_1755951379.webp)

Approach: Single Traversal Deletion - O(n) Time and O(1) Space

Deletion at a specified position in a linked list involves removing a node from a specific index/position, which can be the first, middle, or last node.

To perform the deletion:
- If the position is 1, we update the head to point to the next node and delete the current head.
- For other positions, we traverse the list to reach the node just before the specified position. 
- If the target node exists, we adjust the next of this previous node to point to next of next nodes, which will result in skipping the target node.