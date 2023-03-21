


#include "stack.h"


Stack::Stack(){
    top = MIN;
}

Stack::~Stack(){
}


//Getters
bool Stack::isEmpty(){
    return (top == MIN);
}


int Stack::pop(){
    if(top <= MIN){ 
        throw 1; 
    } 
    return stack[top--];
}


int Stack::peek(){
    if(top <= MIN){
        throw 1;
    }
   return stack[top];
}

//Setters
bool Stack::push(int x){ 
    bool result = false;
    if(top < (STACK_SIZE - 1)){
        stack[++top] = x;
        result = true;
    } 
    return result;
}