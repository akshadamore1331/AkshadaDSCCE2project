# AkshadaDSCCE2project
# E-Waste Collection System

## DSA CCE-II | Unit III | C++

### Project Overview

The E-Waste Collection System is a menu-driven C++ application
that manages electronic waste collection records using a
Singly Linked List.

It allows users to add, display, search, update, and delete
e-waste records.

The project demonstrates the practical application of
dynamic memory allocation and linked list operations.



## Problem Statement

Develop a menu-driven C++ program to manage e-waste
collection records using a Singly Linked List.

Each record contains:
- E-Waste ID
- Item Name
- Quantity
- Recycling Status

The system should support the following operations:

1. Add a new record.
2. Display all records.
3. Search for a record using its ID.
4. Update the recycling status.
5. Delete a record using its ID.
6. Exit the program.



## Objectives

- Understand the concept of a Singly Linked List.
- Implement insertion and deletion operations.
- Perform searching and traversal.
- Use pointers and dynamic memory allocation.
- Apply data structures to a real-world problem.



## Data Structure Used

### Singly Linked List

A Singly Linked List consists of nodes connected
through pointers.

Each node contains:

- `id`: Unique identifier of the record.
- `itemName`: Name of the electronic item.
- `quantity`: Quantity of the item.
- `status`: Recycling status.
- `next`: Pointer to the next node.

The `head` pointer stores the address of the first node.

### Node Representation

    [ID | Item Name | Quantity | Status | Next]

### Example

    head
     |
     v
    [101 | Laptop | 2 | Pending | Next]
                                      |
                                      v
    [102 | Mobile | 5 | Recycled | NULL]

---

## Algorithm

### 1. Add Record

1. Create a new node dynamically.
2. Read the ID, item name, quantity, and status.
3. Set the next pointer to NULL.
4. If the list is empty, make the new node the head.
5. Otherwise, traverse to the last node.
6. Link the last node to the new node.

### 2. Display Records

1. Check whether the list is empty.
2. If empty, display a message.
3. Otherwise, start from the head.
4. Display each node's data.
5. Move to the next node until NULL is reached.

### 3. Search Record

1. Read the ID to search.
2. Start traversal from the head.
3. Compare each node's ID with the given ID.
4. If a match is found, display the record.
5. Otherwise, display "Record not found."

### 4. Update Record

1. Read the ID to update.
2. Traverse the linked list.
3. Find the node with the matching ID.
4. Read the new recycling status.
5. Update the status.
6. If no match exists, display a message.

### 5. Delete Record

1. Read the ID to delete.
2. Initialize the current pointer to head.
3. Maintain a previous pointer.
4. Search for the matching node.
5. If the node is the first node, update head.
6. Otherwise, connect the previous node to the next node.
7. Delete the removed node from memory.
8. If no match exists, display a message.

---

## Program Logic

The program uses a menu-driven approach.

A `do-while` loop repeatedly displays the menu
until the user chooses Exit.

A `switch` statement calls the appropriate function
based on the selected menu option.

The linked list is traversed using pointers.

Dynamic memory allocation creates nodes when records
are added, while the `delete` operator releases memory
when a record is removed.

---

## Time Complexity

Let `n` be the number of records.

| Operation | Time Complexity |
|-----------|-----------------|
| Add Record | O(n) |
| Display Records | O(n) |
| Search Record | O(n) |
| Update Record | O(n) |
| Delete Record | O(n) |

The insertion operation takes O(n) because the program
traverses the list to find the last node.

## Applications

- Electronic waste collection centres.
- Recycling management.
- College e-waste drives.
- Electronic scrap inventory management.
- Environmental awareness projects.

---

## Limitations

- Records are stored in memory and are lost when
  the program terminates.
- Item names and statuses cannot contain spaces
  in the current implementation.
- The program does not prevent duplicate IDs.
- The program does not use a database.

---

## Conclusion

The E-Waste Collection System demonstrates how a
Singly Linked List can be used to manage records
dynamically.

The project provides practical experience with
pointers, dynamic memory allocation, traversal,
searching, insertion, deletion, and updating records.

It also illustrates how data structures can be
applied to an environmental problem such as
electronic waste management.
