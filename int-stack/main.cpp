
#include "main.h"

int main(int argc, char **argv)
{

    Stack stack1;
    int item;          // Variable to store items removed from the stack
    srand(time(NULL)); // Seeding for rand function

    for (int i = 0; i < TEST_LOOP; ++i){
        
        int random_num = rand() % (MAX_VALUE * SCALER) - MAX_VALUE; // gets a random number between -100 and 100 to add to stack
        
        switch (rand() % NUM_METHODS){ // Getting random method to test

        case 0:
            try {
                item = stack1.pop();
                cout << item << " was popped off the stack." << endl;
            } catch (int e) {
                cout << "Error: Stack underflow - No elements to pop " << e << endl;
                }
            break;

        case 1:
            if (stack1.push(random_num)) {
                cout << "Success: Item added to stack: " << random_num << endl;
            } else {
                cout << "Failure: Item was not added to the stack" << endl;
            }
            break;

        case 2:
            if(stack1.isEmpty()){
                cout << "Stack is Empty" << endl;
            } else {
                cout << "Stack is NOT Empty" <<endl;
            }
            break;

        case 3:
            try {
                item = stack1.peek();
                cout << "Top element of the stack: " << item << endl;
            } catch (int e) {
                cout << "Error: Stack underflow - " << e << endl;
            }
            break;

        }
    }

    return 0;
}