/*********************
Name: Britany Sifford
Coding Assignment 7
Purpose: Hash Table

File: hashtable.h
**********************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

//Bringing in linked list for seperate chaining
 #include "linkedlist.h"


#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

#define HASHTABLESIZE 15

class HashTable {
    
    public:
        //Constructor
        HashTable();
        //Destructor
        ~HashTable();

         bool insertEntry(int, string*);
         string getData(int); 
         bool removeEntry(int);
         int getCount(); 
         void printTable();
    
    private:
        LinkedList* hashtable;
        int hash(int);
        int count;
};

#endif // HASHTABLE_H