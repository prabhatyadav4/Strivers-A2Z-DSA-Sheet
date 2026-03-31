# Insertion in Singly Linked List

## Insert a Node at Front of a Linked List

Given a head of the linked list, Insert a new node at the beginning/start/front of the linked list.

Example:

Input: x = 1

![Insert1](https://media.geeksforgeeks.org/wp-content/uploads/20250823154205312088/111.webp)

Output: 1 -> 2 -> 3 -> 4 -> 5

Explanation: We can see that 1 is inserted at the beginning of the linked list.

![Insert2](https://media.geeksforgeeks.org/wp-content/uploads/20250823154235057502/222-.webp)

Approach:

To insert a new node at the front, we create a new node and point its next reference to the current head of the linked list. Then, we update the head to be this new node. This operation is efficient because it only requires adjusting a few pointers.

Algorithm:

- Make the first node of Linked List linked to the new node
- Remove the head from the original first node of Linked List
- Make the new node as the Head of the Linked List.

## Insert Node at the End of a Linked List

Given a head of the linked list, we need to insert a new node at the end of the linked list.

Examples:

Input: x = 6

![Insert3](https://media.geeksforgeeks.org/wp-content/uploads/20250825154319352044/blobid2_1755948542.webp)

Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

Explanation: We can see that 6 is inserted at the end of the linkedlist.

![Insert4](https://media.geeksforgeeks.org/wp-content/uploads/20250825154319241053/blobid3_1755948555.webp)

Approach: 

Inserting at the end involves traversing the entire list until we reach the last node. We then set the last node's next reference to point to the new node, making the new node the last element in the list.

Following is the approach to add a new node at the end of the linked list:

- Create a new node and set its next pointer as NULL since it will be the last node.
- Store the head reference in a temporary variable
- If the Linked List is empty, make the new node as the head and return
- Else traverse till the last node
- Change the next pointer of the last node to point to the new node

## Insert a node at a specific position in a linked list

Given a head of singly linked list, a position pos, and val, Insert that data into a linked list at the given position. 

Examples:

Input: val = 3, pos = 3

![Insert5](https://media.geeksforgeeks.org/wp-content/uploads/20250902103645118650/Screenshot-2025-09-02-102354.png)

Output: 1 -> 2 -> 3 -> 4

Explanation: Node  inserted at position 3.

![Insert6](https://media.geeksforgeeks.org/wp-content/uploads/20250902103604087938/frame_3090.webp)

Approach: Using Iterative Method - O(n) time and O(1) space:

The idea is simple: create a new node, then find the spot where it should be placed. Walk through the list until you reach the node just before that position. Link the new node’s next to the following node, and adjust the previous node’s next to point to the new node. 

Step By Step Implementations:

- Initialize a variable , say curr points to head and allocate the memory to the new node with the given val.
- Traverse the Linked list using curr pointer upto position-1 nodes.
- If curr's next is not null , then next pointer of the new node points to the next of curr node.
- The next pointer of current node points to the new node.
- Return the head of linked list.