


#ifndef STACK_STACK_H
#define STACK_STACK_H


#define MIN -1 // Top can never be lower than -1

#define STACK_SIZE 10 // Number of elements allowed in the stack 

#include <iostream>
using std::cout;
using std::endl;

class Stack {

    public:
    //Constructor
    Stack();

    //Destructor
    ~Stack();


    //Setters
    bool push(int);

    //Getters
    bool isEmpty();
    int pop();
    int peek();

    private:
        int top;
        int stack[STACK_SIZE];

};

#endif //STACK_STACK_H
