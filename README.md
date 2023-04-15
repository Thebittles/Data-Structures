# This repository contains data structures implemented in C++:  The implementations are designed to be efficient and easy to use.

To use any of these data structures in your project, simply include the appropriate header file and instantiate the desired class

 ## 1. Int Stack

The int stack is a simple stack that stores integers. It supports the following operations:

-   `push`: adds an integer to the top of the stack.
-   `pop`: removes the integer at the top of the stack.
-   `peek`: returns the integer at the top of the stack without removing it.
-   `isEmpty`: returns true if the stack is empty, false otherwise.
-   `getSize`: returns the number of integers in the stack.

---------
## 2. ADT Stack

The ADT stack is an abstract data type that can store any type of data. Can be instantiated with any data type. It supports the same operations as the int stack, but with generic data types:

-   `push`: adds an element to the top of the stack.
-   `pop`: removes the element at the top of the stack.
-   `peek`: returns the element at the top of the stack without removing it.
-   `isEmpty`: returns true if the stack is empty, false otherwise.
-   `getSize`: returns the number of elements in the stack.

## 3. Doubly-Linked List
------------------

The doubly-linked list is a linked list that allows traversal in both directions. It supports the following operations:

-   `addNode`: inserts an element at a given position in the list.
-   `deleteNode`: removes an element from the list.
-   `getNode`: returns the element at a given position in the list.
-   `exists`: returns true if the element exists in the list, false otherwise.
-   `getCount`: returns the number of elements in the list.
-   `printList`: prints the entire list.
-   `clearList`: removes all elements from the list.


------------------

## 4. HashTable-Linked List
Separate Chaining Hash Table Class

This is an implementation of a separate chaining hash table class in C++. The hash table class contains an array of linked lists, using a hash function based on modulo arithmetic. This implementation uses a "has a" relationship between the hash table and the linked list classes.

Features
The public methods of the hash table class are as follows:

 - `bool insertEntry(int id, string* data)`: Inserts a new entry into the hash table with the given ID and data string. Returns true on success and false on failure.
- `string getData(int id)`: Returns the data string associated with the given ID. Returns an empty string if the ID does not exist in the table.
- `bool removeEntry(int id)`: Removes the entry with the given ID from the hash table. Returns true on success and false on failure.
- `int getCount()` : Returns the number of entries currently in the hash table.
- `void printTable()`: Displays the contents of the hash table. Each entry of the table is shown, along with the IDs of the entries in its linked list.

------------------

## 5. Binary Tree with Linked List

This is an implementation of a binary tree data structure with a "linked list" approach. The tree is represented as a collection of Node pointers, where each node has a left and right pointer. This implementation allows the tree to grow to any size, and nodes can be created and deleted within the tree.

Features The public methods are as follows :

- `BinTree()`: the constructor for initializing root to null and count to 0
- `~BinTree()`: the destructor, which calls the clearTree() method

- `isEmpty()`: returns true if the tree is empty, false otherwise
- `getCount()`: returns the number of nodes in the tree
- `getRootData(Data*)`: pass (by reference) an "empty" Data struct from main() and fill it with root's data if the tree is not empty
- `displayTree()`: displays all stats for the tree, including the height and the contents of the tree in pre-order, post-order, and in-order traversal order.
- `clear()`: deallocates the tree and sets it back to "empty."
- `addNode(int, const string*)`: adds a node with the given id and string data to the tree. Returns true if the node was added successfully, false otherwise. Duplicate ids are allowed.
- `removeNode(int)`: removes the node with the given id from the tree. Returns true if the node was removed successfully, false otherwise.
- `getNode(Data*, int)`: fills the given Data struct with the data of the node with the given id. Returns true if the node was found, false otherwise.
- `contains(int)`: returns true if the tree contains a node with the given id, false otherwise.
- `getHeight()`: dynamically calculates the height of the tree (i.e., the number of levels in the tree). 
- `displayPreOrder()`: performs a pre-order traversal of the tree and prints the contents of each node as it is visited.

- `displayPostOrder()`: performs a post-order traversal of the tree and prints the contents of each node as it is visited.

- `displayInOrder()`: performs an in-order traversal of the tree and prints the contents of each node as it is visited.

For each of the above methods, there is a corresponding private overload method that implements recursion to traverse the tree. These private methods are:

- `clear(DataNode*)`
- `addNode(DataNode*, DataNode**)`
- `removeNode(int, DataNode*)`
- `getNode(Data*, int, DataNode*)`
- `contains(int, DataNode*)`
- `getHeight(DataNode*)`
- `displayPreOrder(DataNode*)`
- `displayPostOrder(DataNode*)`
- `displayInOrder(DataNode*)`


------------------
