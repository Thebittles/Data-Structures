/*********************
Name: Britany Sifford
Coding Assignment 7
Purpose: Hash Table 

File: main.cpp
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // Creating a new hash table
    HashTable table;


    // show it is empty by calling getCount and printTable
      cout << "Showing table is empty after creation..." << endl;
      cout << "Count: " << table.getCount() << endl;
      cout << endl;


        cout << "Try Printing empty table..." << endl;
    cout << endl;
    table.printTable();
    cout << endl;

    //Trying to get data from an empty table
    cout << "Trying to get data from an empty table" << endl;
    for(int i = 0; i < testdatasize; i++) {
        int randomID = rand() % MAXID + 1;
        cout << "Random ID: " << randomID << " - Data: " << table.getData(randomID) << endl;
    }
    cout << endl;


    //Trying to delete data from an empty table
    cout << "Trying to delete data from an empty table" << endl;
        for(int i = 0; i < testdatasize; i++) {
        int randomID = rand() % testdatasize + 1;
        if(table.removeEntry(ids[randomID])) {
            cout << "Removed id " << ids[randomID] << endl;
        } else {
            cout << "Failed to remove id " << ids[randomID] << endl;
        }
    }
    cout << endl;

    // try and put ALL the test data into the table and show what happens
    cout << "Adding Test Data to table " << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (table.insertEntry(ids[i], &strs[i])) { //Inserting the data into the table
            cout << "Added " << ids[i] << " : " << strs[i] << endl;
        } else {
            cout << "Failed to add " << ids[i] << " : " << strs[i] << endl;
        }
    }

    // Calling get count and print table to show the data was added
    cout << endl;
    cout << "Data has been added to the table" << endl;
    cout << "Count: " << table.getCount() << endl;

    cout << endl; 
    cout << "Printing table after adding data..." << endl;
    cout << endl;
    table.printTable();


    cout << endl << endl;
    cout << "Trying to get data from table with random ids" << endl;
    //Trying to get random ids from the table
    for(int i = 0; i < testdatasize; i++) {
        int randomID = rand() % MAXID + 1;
        cout << "Random ID: " << randomID << " - Data: " << table.getData(randomID) << endl;
    }

    cout << endl << endl;
    cout << "Getting known data from table with known ids" << endl;
    //Getting known ids from the table
        for(int i = 0; i < testdatasize; i++) {
        int randomID = rand() % testdatasize + 1;
        cout << "Data for id " << ids[randomID] << " : " << table.getData(ids[randomID]) << endl;
    }

    cout << endl << endl;
       cout << "Count: " << table.getCount() << endl;
    cout << "Trying to remove random ids and data from table" << endl;
    //Trying to remove random ids from the table
    for(int i = 0; i < testdatasize; i++) {
        int randomID = rand() % MAXID + 1;
        if(table.removeEntry(randomID)) {
            cout << "Removed id " << randomID << endl;
        } else {
            cout << "Failed to remove id " << randomID << endl;
        }
    }
       cout << "Count: " << table.getCount() << endl;

    
    cout << endl;
    cout << "Count: " << table.getCount() << endl;
    //Trying to remove known ids from the table
    for(int i = 0; i < testdatasize; i++) {
        int randomID = rand() % testdatasize + 1;
        if(table.removeEntry(ids[randomID])) {
            cout << "Removed id " << ids[randomID] << endl;
        } else {
            cout << "Failed to remove id " << ids[randomID] << endl;
        }
    }
       cout << "Count: " << table.getCount() << endl;
    
    cout << endl;
    //Calling get count and print table to show the data was removed
    table.printTable();
    cout << "Count: " << table.getCount() << endl;

    
    
    return 0;
}
