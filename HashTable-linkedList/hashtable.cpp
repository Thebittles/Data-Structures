/*********************
Name: Britany Sifford
Coding Assignment 7
Purpose: Hash Table 

File: hashtable.cpp
**********************/


#include "hashtable.h"

//Public

//Hast table with separate chaining
HashTable::HashTable() {
     count = 0;
     hashtable = new LinkedList[HASHTABLESIZE]; // Create the hashtable array
}

HashTable::~HashTable() {
    delete[] hashtable; // Delete the hashtable array
}


//Methods

bool HashTable::insertEntry(int id, string* data){
    bool result = false;
    if(id > 0 && *data!=""){
     int index = hash(id); //Get the index of the hash table where we will add the data
     if(hashtable[index].addNode(id, data)){
        count++;
        result = true;
     }; //Add the data to the linked list at the index
  }
    return result;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i].getCount() != 0) {
            cout << "Entry " << i + 1<< ": ";
            hashtable[i].printList();
            cout << endl;
            
        } else {
            cout << "Entry " << i + 1<< ": " << "Empty" << endl;
        }
    }
}

string HashTable::getData(int id){
    string result = "";   // If no string is found, return an empty string
    if (id > -1){ // Make sure we have a valid id
        int index = hash(id); // Find the hash table index where the data is stored
        Data data; // Create a data object to store the data
        if (hashtable[index].getNode(id, &data)){ // Figure out if the id exists in the list
            result = data.data; // Set the result to the data string
        }
    }
    return result;
}



bool HashTable::removeEntry(int id){
    bool result = false;
    if (id > -1){ // Make sure we have a valid id
        int index = hash(id); // Find the hash table index where the data is stored
        if (hashtable[index].deleteNode(id)){ // Figure out if the id exists in the list & remove node from list
            count--; // Decrement the count
            result = true;
        }
    }
    return result;
}


// Private
int HashTable::hash(int id)
{
    return id % HASHTABLESIZE;
}






// you should not use the linked list exists() in the hash table for the same reason you don't use it in the linked list itself, it increases processing by 2x for no reason. just use the linked list methods as they are designed and they will tell you if they are successful or not.

