/*********************
Name: Britany Sifford
Coding Assignment 8
Purpose: Binary search tree

File: bintree.cpp
**********************/

#include "bintree.h"
#include <iostream>

BinTree::BinTree(){
    root = nullptr;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){
    return count == 0;
}

int BinTree::getCount(){
    return count;
}

int BinTree::getHeight(){
    return getHeight(root);
}

//Public
bool BinTree::contains(int id){
    bool result = false;
    if(id > 0){
        result = contains(id, root);
    }
    return result;
}

//Public
bool BinTree::getRootData(Data* data){
    bool result = false;
    data->id = -1;
    data->information = "";

    if(root != nullptr){
        data->id = root->data.id;
        data->information = root->data.information;
        result = true;
    }
    return result;
}

//Public
void BinTree::displayTree(){ 
    std::cout << "DISPLAY TREE" << std::endl;
    std::cout<< "==============================================" << std::endl;

    if(isEmpty()){
        std::cout << "Tree is empty" << std::endl;
    } else {
        std::cout << "Tree is NOT empty" << std::endl;
    }
    std::cout << "Height: " << getHeight() << std::endl;
    std::cout << "Node Count: " << getCount() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << std::endl;

    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << std::endl; 

    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << std::endl;


    return;
}

void BinTree::clear(){
    clear(root);
    root = nullptr;

}

//Public
bool BinTree::addNode(int id, const string* information){
    bool success = false; //Flag for determining if the vertices was added
    if(id > 0 && information->length() > 0){ //Check for valid data
        DataNode* newNode = new DataNode; //Create a new node
        newNode->data.id = id; //Set the id
        newNode->data.information = *information; //Set the information
        newNode->left = nullptr; //Set the left side to null
        newNode->right = nullptr; //Set the right side to null
        success = addNode(newNode, &root); //Add the node
        if(success){
            count++; //Increment the count
        }
    }
    return success;
}

//Public
bool BinTree::removeNode(int id){
    bool success = false; //Flag for determining if the node was removed
    int tempCount = count; 
    if(root && id > 0){ //Check for valid data
        root = removeNode(id, root);
        if(count < tempCount){ //If the count is less than the temp count then the node was removed
            success = true;
        }
    }

    return success;
}

bool BinTree::getNode(Data* data, int id){
    bool success = false;
    if(id > 0){ //Check for valid id
        success = getNode(data, id, root); //Recursive call to get the node
    }
    return success;
}


void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}



//***********************************************************
//Private
//***********************************************************

//Private
void BinTree::clear(DataNode* temproot){
    if(temproot){ // If it is not empty
        clear(temproot->left); //Clear the left side recursively
        clear(temproot->right); //Clear the right side recursively
        temproot->left = nullptr;  //Set the left side to null
        temproot->right = nullptr;  //Set the right side to null
        delete temproot;  
        count--;
    }
}


bool BinTree::contains(int id, DataNode* temproot){
    bool result = false;
        if(temproot){
            if(id == temproot->data.id){
                result = true;
            } else if(id < temproot->data.id){
                result = contains(id, temproot->left);
            } else if(id > temproot->data.id){
                result = contains(id, temproot->right);
            }
        }
     return result;
    }


//Private
bool BinTree::addNode(DataNode *newNode, DataNode **tempRoot){
    bool success = false;
    if(!(*tempRoot)){ //If the root is empty
        (*tempRoot) = newNode; //Set the root to the new node
        success = true; //Set the flag to true
    } else {
        if(newNode->data.id < (*tempRoot)->data.id){ //If the new node's id is less than the root's id
            success = addNode(newNode, &((*tempRoot)->left)); //Add the node to the left side pass the address
        } else if (newNode->data.id > (*tempRoot)->data.id) { //If the new node's id is greater than the root's id
            success = addNode(newNode, &((*tempRoot)->right)); //Add the node to the right side pass the address
        }
    }
    return success;
}





// Private
DataNode* BinTree::minValueNode(DataNode* node) {
DataNode* current = node;
while (current && current->left != NULL) {
current = current->left;
}
return current;
}

//Private
DataNode* BinTree::removeNode(int id, DataNode *temproot){
    if(temproot){ // if tree or subtree is not empty
        if(temproot->left && id < temproot->data.id){  // If id less than the root go left and if there is a left child
            temproot->left = removeNode(id, temproot->left); // recursively call removeNode on the left subtree
        } else if (temproot->right && id > temproot->data.id){  //If id is more than the root go right and if there is a right child
            temproot->right = removeNode(id, temproot->right); // recursively call removeNode on the right subtree
        } else if (id == temproot->data.id){  //must be equal
            DataNode *temp = new DataNode; //Create a temp node to store value
            if(!temproot->left){//If the current node to delete has no left child
                temp = temproot->right; //Replace the root with the right child
                delete temproot; //Delete the node to be removed
                temproot = temp; //set the new root
                count--; //Decrement count
            } else if (!temproot->right) { //If the current node to delete has no right child
                temp = temproot->left; //Replace the root with the left child
                delete temproot; //Delete the node to be removed
                temproot = temp; //set the new root
                count--; //Decrement count
            } else { //If the current node has both left and right child
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }

    }
    return temproot; 
}



//Private
bool BinTree::getNode(Data *data , int id, DataNode *temproot ){
    bool success = false;
    //Set the data to default values until we find the node
    data->id = -1;
    data->information = "";
    if(temproot){
        if(id < temproot->data.id){ // If its less than the root go left
            success = getNode(data, id, temproot->left);  
        } else if( id > temproot->data.id){ //If its more than the root go right
            success = getNode(data, id, temproot->right);
        } else { //id must be equal
            data->id = temproot->data.id;
            data->information = temproot->data.information;
            success = true;
        }
    }
    return success;
}

int BinTree::getHeight(DataNode *temproot){
    int left = 0; //Left side count
    int right = 0; //Right side count
    int result;
    if(!temproot){
        result = 0;
    } else {    
        right = getHeight(temproot->right) + 1; //Get the right side count
        left = getHeight(temproot->left) + 1; //Get the left side count
        result = (left > right) ? left : right; //Return the larger of the two
    }
    return result;
}


void BinTree::displayPreOrder(DataNode *temproot){
    if (temproot) {
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->left) {
            displayPreOrder(temproot->left);
        }
        if (temproot->right) {
            displayPreOrder(temproot->right);
        }
    }
    return;
}

void BinTree::displayInOrder(DataNode *temproot){
        if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;
}

void BinTree::displayPostOrder(DataNode *temproot){
    if(temproot){
        if(temproot->left){
            displayPostOrder(temproot->left);
        }
        if(temproot->right){
            displayPostOrder(temproot->right);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
    }
    return;
}
