/*********************
Name: Britany Sifford
Coding Assignment 7
Purpose: Hash Table 

File: linkedlist.cpp
**********************/


#include "linkedlist.h"

//Constructor
LinkedList::LinkedList(){
   head = nullptr;
}

//Destructor
LinkedList::~LinkedList() {
    clearList();
}

//Getters

//getnode
bool LinkedList::getNode(int id, Data* item){
   bool success = false;
   Node* current = head;

   item->id = -1;
   item->data = "";

   while(current != nullptr){
      if(current->data.id == id){
         item->id = current->data.id;
         item->data = current->data.data;
         success = true;
      }
         current = current->next;
   }


   return success;
}



//getcount
int LinkedList::getCount(){
   int count = 0;
   Node* current = head;
   while (current != nullptr) {
       count++;
       current = current->next;
   }
   return count;
}

//exists
bool LinkedList::exists(int id){
   bool success = false;
   Node* current = head;

   while(current != nullptr){
      if(current->data.id == id){
         success = true;
      }
         current = current->next;
   }
   return success;
}
 
//Setters

//***********************
//deletenode
bool LinkedList::deleteNode(int id) {
   bool success = false;
      Node* current = head;
      while (current != nullptr) {
         if (current->data.id == id) {
               if (current == head) {
                  if (head->next == nullptr) { // only one node in the list
                    delete head;
                    head = nullptr;
                   } else {
                    deleteHead();
                  }
                  success = true;
               } else if (current->next == nullptr) {
                  deleteTail(current);
                  success = true;
               } else {
                  deleteMiddleNode(current);
                  success = true;
               }
         }
         current = current->next;
      }
   return success;
}
//***********************

//clearlist
bool LinkedList::clearList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    return true;
}


//printlist
void LinkedList::printList(){
   Node* current = head;
   if(current == nullptr){ //Check if the list is empty
      std::cout << "EMPTY" << std::endl;
   } else {
        // Traverse head to tail
        while (current != nullptr) {
            std::cout << current->data.id << "-->";
            current = current->next;
        }
    }
    return;
}


//Setters
//************************************************
bool LinkedList::addNode(int id, string* data){
   bool success = false;

      Node* current = head;  
      
      if(id < 0 && !data->empty()){
         success = false;
      } else {
         // Check if the list is empty;
         if(head == nullptr){
            head = createNode(id, *data);
            success = true;
         } else {
            //Find where to insert
            while(current->next != nullptr && current->data.id < id){
                current = current->next;
            }
             //Check for duplicate id only allocate memory if it is not a duplicate
            if(current->data.id == id){
                success = false;
            } else {
               //Create the new node
                Node* newNode = createNode(id, *data);

               if (id < current->data.id){
                  if(current == head){
                    addHead(newNode);
                  } else {
                    addMiddleNode(newNode, current);
                  }
                success = true;
               } else if (id > current->data.id) {
                addTail(newNode, current);
                success = true;
               }
            }

         }
      }
           
   return success;
}
//*************************************************




//Private Methods
Node* LinkedList::createNode(int id, string& data) {
    Node* newNode = new Node;
    if (newNode != nullptr) {
        newNode->data.id = id;
        newNode->data.data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
    }
    return newNode;
}


// Add Node Methods
void LinkedList::addHead(Node* newNode) {
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = nullptr;
    head = newNode;
}

void LinkedList::addTail(Node* newNode, Node* current) {
    newNode->next = nullptr;
    newNode->prev = current;
    current->next = newNode;
}


void LinkedList::addMiddleNode(Node* newNode, Node* current) {
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

//Delete Node Methods
void LinkedList::deleteHead() {
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

void LinkedList::deleteTail(Node* current) {
    current->prev->next = nullptr;
    delete current;
}

void LinkedList::deleteMiddleNode(Node* current) {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}