This repository contains three data structures implemented in C++:  The implementations are designed to be efficient and easy to use.

Int Stack
---------

The int stack is a simple stack that stores integers. It supports the following operations:

-   `push`: adds an integer to the top of the stack.
-   `pop`: removes the integer at the top of the stack.
-   `peek`: returns the integer at the top of the stack without removing it.
-   `isEmpty`: returns true if the stack is empty, false otherwise.
-   `getSize`: returns the number of integers in the stack.

ADT Stack
---------

The ADT stack is an abstract data type that can store any type of data. Can be instantiated with any data type. It supports the same operations as the int stack, but with generic data types:

-   `push`: adds an element to the top of the stack.
-   `pop`: removes the element at the top of the stack.
-   `peek`: returns the element at the top of the stack without removing it.
-   `isEmpty`: returns true if the stack is empty, false otherwise.
-   `getSize`: returns the number of elements in the stack.

Doubly-Linked List
------------------

The doubly-linked list is a linked list that allows traversal in both directions. It supports the following operations:

-   `addNode`: inserts an element at a given position in the list.
-   `deleteNode`: removes an element from the list.
-   `getNode`: returns the element at a given position in the list.
-   `exists`: returns true if the element exists in the list, false otherwise.
-   `getCount`: returns the number of elements in the list.
-   `printList`: prints the entire list.
-   `clearList`: removes all elements from the list.

Usage
-----

To use any of these data structures in your project, simply include the appropriate header file and instantiate the desired class