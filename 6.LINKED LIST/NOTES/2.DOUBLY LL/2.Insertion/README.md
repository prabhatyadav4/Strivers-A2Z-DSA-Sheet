# Insertion in Doubly Linked List

## Insert a Node at Front/Beginning of Doubly Linked List

Given a Doubly Linked List, insert a new node at the beginning/start/front of the linked list.

**Examples:**

Input: Linked List = 2 <-> 3 <-> 4  , New Node  = 1

Output: 1 <-> 2 <-> 3 <-> 4 

Explanation: Node 1 is inserted at the beginning and is the new head of the doubly linked list.

Input: Linked List = NULL, New Node = 10

Output: 10 

Explanation: Node 1 is the only node in the doubly linked list.

**Approach:**

- To insert a new node at the beginning/front of doubly linked list, we create a new node with its previous pointer as NULL and next pointer to the current head of the doubly linked list.
- Then, we check if the linked list is not empty then we update the previous pointer of the current head to the new node.
- Finally, we return the new node as the head of the linked list.

![Insertion1](https://media.geeksforgeeks.org/wp-content/uploads/20240806180443/Insertion-at-the-Beginning-in-Doubly-Linked-List.webp)

**Steps to insert a node at the beginning of doubly linked list:**

- Create a new node, say new_node with the given data and set its previous pointer to null, new_node->prev = NULL.
- Set the next pointer of new_node to the current head, new_node->next = head.
- If the linked list is not empty, update the previous pointer of the current head to new_node, head->prev = new_node.
- Return new_node as the head of the updated linked list.

**Time Complexity**: O(1)

**Auxiliary Space**: O(1)

## Insert a Node at the end of Doubly Linked List

Given a Doubly Linked List, insert a new node at the end of the linked list.

**Examples:**

Input: Linked List = 1 <-> 2 <-> 3, NewNode = 4

Output: 1 <-> 2 <-> 3 <-> 4

Input: Linked List = NULL, NewNode = 1

Output: 1

**Approach:**

Inserting at the end involves traversing the entire list until we reach the last node. We then set the last node’s next reference to point to the new node and new node's previous reference to point to the last node. Thus, making the new node the last element in the list.

![Insertion2](https://media.geeksforgeeks.org/wp-content/uploads/20240807153259/Insertion-at-the-End-in-Doubly-Linked-List.webp)

Steps to insert a new node at the end:

- If the linked list is empty, we set the new node as the head of linked list and return it as the new head of the linked list.
- Otherwise, traverse the entire list until we reach the last node, say curr.
- Then, set the last node’s next to new node and new node’s prev to last node, making the new node the last element in the list.

**Time Complexity**: O(n), where n is the number of nodes in the linked list.

**Auxiliary Space**: O(1)

## Insert a Node at a specific position in Doubly Linked List

Given a Doubly Linked List, insert a new node at a specific position in the linked list.

**Examples:**

Input: Linked List = 1 <-> 2 <-> 4, newData = 3, position = 3

Output:  1 <-> 2 <-> 3 <-> 4

Explanation: New node with data = 3 is inserted at position 3

Input: Linked List = 2 <-> 3, newData = 1, position = 1

Output: 1 <-> 2 <-> 3

Explanation: New node with data = 1 is inserted at position 1

**Approach:**

The idea is to traverse the linked list to find the node at position - 1, say current node. If the position is valid, create a new node with the given data and update its pointers: Set the next pointer of new node to next of current node and previous pointer of new node to current node. Similarly, update next pointer of current node to the new node and prev pointer of new node’s next to the new node.

![Insertion3](https://media.geeksforgeeks.org/wp-content/uploads/20240807121739/Insertion-at-a-Specific-Position-in-Doubly-Linked-List.webp)

To insert a new node at a specific position,

- If position = 1, create a new node and make it the head of the linked list and return it.
- Otherwise, traverse the list to reach the node at position – 1, say curr.
- If the position is valid, create a new node with given data, say new_node.
- Update the next pointer of new node to the next of current node and prev pointer of new node to current node, new_node->next = curr->next and new_node->prev = curr.
- Similarly, update next pointer of current node to the new node, curr->next = new_node.
- If the new node is not the last node, update prev pointer of new node’s next to the new node, new_node->next->prev = new_node.

**Time Complexity**: O(n), where n is the number of nodes in doubly linked list

**Auxiliary Space**: O(1)