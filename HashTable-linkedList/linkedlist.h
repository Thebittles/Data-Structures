/*********************
Name: Britany Sifford
Coding Assignment 7
Purpose: Hash Table 

File: linkedlist.h
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h" // Bring in data and our node
#include <iostream>

class LinkedList {
    public:
        //Constructor
        LinkedList();
        //Destructor
        ~LinkedList();

        //Getters
        bool getNode(int, Data*);
        int getCount();
        bool exists(int);

        //Setters
        bool addNode(int, string*);
        bool deleteNode(int);
        void printList();
        bool clearList();

    private:
        Node *head;
        Node *createNode(int, string&);
        //Add node
        void addHead(Node*);
        void addMiddleNode(Node*, Node*);
        void addTail(Node*, Node*);

        //Delete node
        void deleteHead();
        void deleteMiddleNode(Node*);
        void deleteTail(Node*);
};



#endif //LINKED_LIST_H