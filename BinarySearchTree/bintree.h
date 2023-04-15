/*********************
Name: Britany Sifford
Coding Assignment 8
Purpose: Binary search tree

File: bintree.h
**********************/


#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"

class BinTree {
public:
    // Constructor
    BinTree();

    // Destructor
    ~BinTree();

   //Public methods
   bool isEmpty();
   int getCount();
   bool getRootData(Data*);
   void displayTree();
   void clear(); 
   bool addNode(int, const string*); 
   bool removeNode(int); 
   bool getNode(Data*, int);
   bool contains(int); 
   int getHeight();
   void displayPreOrder(); 
   void displayPostOrder();
   void displayInOrder(); 




private:
    DataNode *root;
    int count;

   //Private Methods
   void clear(DataNode*);
   bool addNode(DataNode*, DataNode**);
   DataNode* minValueNode(DataNode*);
   DataNode* removeNode(int, DataNode*); 
   bool getNode(Data*, int, DataNode*);
   bool contains(int, DataNode*);
   int  getHeight(DataNode*);
   void displayPreOrder(DataNode*);
   void displayPostOrder(DataNode*);
   void displayInOrder(DataNode*);
};

 #endif /* BINTREE_BINTREE_H */
