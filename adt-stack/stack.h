

#ifndef STACK_H
#define STACK_H

#include "data.h"

#define TOP_MIN -1 // Top can never be lower than -1
#define MIN_STACK_SIZE 2 // Stack size must be greater than 2 
#define DEFAULT_STACK_SIZE 10 // If any number less than 2 is passed in we have a default size



class Stack {

public:
    //Constructor
    Stack(int size);

    //Destructor
    ~Stack();

    bool push(int, string&);
    bool peek(Data&);
    bool pop(Data&);
    bool isEmpty();
    int getSize();
    
private:
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
