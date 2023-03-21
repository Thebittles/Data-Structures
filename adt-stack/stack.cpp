
#include "stack.h"

//Constructor
Stack::Stack(int s){
    if(s < MIN_STACK_SIZE){
        s = DEFAULT_STACK_SIZE;
    }
    this->top = TOP_MIN;
    this->size = s;
    this->stack = new Data*[size];
}


// Destructor
Stack::~Stack(){
    while(top >= 0){ //deallocate the stack
        delete stack[top--];
    }
    delete[] stack; // delete the stack
}


//Getters
int Stack::getSize(){
    return size;
}

bool Stack::isEmpty(){
    return (top == TOP_MIN);
}



bool Stack::peek(Data& dataItem) { 
    bool result = false;
    dataItem = Data{ -1, "" };
    if (top > TOP_MIN) { // check if stack is empty
        dataItem = *stack[top];
        result = true;
    }
    return result;
}


//Setters
bool Stack::push(int id, string& info) {
    bool result = false;
    if (top < size - 1 && id > 0 && !info.empty()) {
        top++;
        stack[top] = new Data{id, info};
        result = true;
    }
    return result;
}



bool Stack::pop(Data& dataItem) {
    bool result = false;
    dataItem = { -1, "" };
    if (top > TOP_MIN) {
        dataItem = *stack[top]; //Get the data from the top of the stack & put it in the struct Data passed from the caller.
        delete stack[top--]; // Delete the allocated memory from the top of the stack Decrement the stack counter
        result = true;
    } 
    return result;
}
