

#include "main.h"

int main(int argc, char **argv) {
    srand(time(NULL));

        int exitCode = 0; // 0 for success will flip to 1 if error encountered

        if (argc != 2) { // Check to make sure more than one argument has been passed into command line
         cout << "Error: This program requires a positive integer and one argument.  " << endl;
         exitCode = 1;
        } else if (atoi(argv[1]) < MIN_STACK_SIZE){// Convert the string arg to int and check to make sure it is positive and greater than 2 ()
            cout << "Error: integer argument must be positive and greater than 2 " << endl;
         exitCode = 1;
        }
        
    if(exitCode != 1){ // If no errors have occurred proceed to test the stack 

        //Create stack
        Stack stack(atoi(argv[1]));

        //Variables for testing
        Data dataItem;
        std::string strtemp; // Will be used for adding data to struct 

        /* ****** Empty Tests ********* */
        cout << "Testing operations on empty stack. " << endl;

        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is NOT empty" << endl;
        }

        try {
             cout << "Stack size: " << stack.getSize() << endl;
        } catch (...) {
            cout << "Error: Unable to get size" << endl;
        }


        
        //Testing peek and pop on empty stack
        if(stack.peek(dataItem)){
            cout << "Peeked: " << endl;
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
            cout << "Stack Underflow: Unable to peek - stack is empty." << endl;
        }


        if(stack.pop(dataItem)){
            cout << "Popped: " << endl;
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
            cout << "Stack Underflow: Unable to pop - stack is empty." << endl;
        }

        cout << endl;// creating space
        cout << endl;

        /* ****** Full Stack Tests ********* */
        cout << "Testing on a full stack" << endl;


        cout << "Filling stack" << endl;
        //Filling stack
        for(int i = 0; i < stack.getSize()*MULTIPLIER; i++){
            int id = rand()%2 ? -(i + 1) : i+1; // Getting random number for id
            rand_string(&strtemp);

            if(stack.push(id, strtemp)){
                cout << "Pushed: " << id << ": " << strtemp << endl;
            } else {
                cout << "Error: Item not pushed: " << id << ": " << strtemp << endl;
            }
        }

        cout << endl;// creating space
        cout << endl;

        //Peek on full stack
        cout << "Peek on fullstack: " << endl;
        if(stack.peek(dataItem)){
            cout << "Peeked: ";
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
            cout << "Error: Unable to peek." << endl;
        }
        //Pop on stack
        cout << "Pop on fullstack: " << endl;
        if(stack.pop(dataItem)){
            cout << "Popped: ";
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
            cout << "Error: Unable to pop " << endl;
        }



        /* ***Emptying and Empty Test***** */

        cout << "Emptying and Empty Tests: " << endl;
        // testing popping and peeking whole stack
        for (int i = 0; i < stack.getSize()*MULTIPLIER; i++) {
            if(stack.peek(dataItem)){
            cout << "Peeked: ";
            cout << dataItem.id << ": " << dataItem.information << endl;
            } else {
                cout << "Peek underflow error: stack is empty" << endl;
            }
            if(stack.pop(dataItem)){
                cout << "Popped: ";
                cout << dataItem.id << ": " << dataItem.information << endl;
            } else { 
                cout << "Pop underflow error: stack is empty" << endl;
            }
            
        }
        //Testing isEmpty on emptied stack
        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is NOT empty" << endl;
        }

        //Testing peek and pop on emptied stack
        if(stack.peek(dataItem)){
            cout << "Peeked: " << endl;
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
            cout << "Stack Underflow: Unable to peek - stack is empty." << endl;
        }


        if(stack.pop(dataItem)){
            cout << "Popped: " << endl;
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
            cout << "Stack Underflow: Unable to pop - stack is empty." << endl;
        }


        /* ********** Mid-Fill Tests ********** */
        cout << endl;
        cout << "Mid-Fill Test: " << endl;

        for (int i = 0; i< int(stack.getSize() / 2); i++) {
            int id = rand()%2 ? -(i + 1) : i+1; 
            rand_string(&strtemp);

            if(stack.push(id, strtemp)){
                cout << "Pushed: " << id << ": " << strtemp << endl;
            } else {
                cout << "Error: Item not pushed: " << id << ": " << strtemp << endl;
            }
        }


        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is NOT empty" << endl;
        }


        if(stack.peek(dataItem)){
            cout << "Peeked: ";
            cout << dataItem.id << ": " << dataItem.information << endl;
        } else {
                cout << "Peek underflow error: stack is empty" << endl;
            }
        if(stack.pop(dataItem)){
                cout << "Popped: ";
                cout << dataItem.id << ": " << dataItem.information << endl;
        } else { 
                cout << "Pop underflow error: stack is empty" << endl;
            }


        int id = rand()%2 ? -(stack.getSize() + 1) : stack.getSize()+1; 
        rand_string(&strtemp);
        if(stack.push(id, strtemp)){
                cout << "Pushed: " << id << ": " << strtemp << endl;
        } else {
                cout << "Error: Item not pushed: " << id << ": " << strtemp << endl;
            }


    /* ******** Generating Random Tests ******* */
    cout << endl;
    cout << "Generating Random Tests" << endl;

    for (int i = 0; i < stack.getSize()*RANDOM_MULTIPLIER; i++) {
        int choice = rand() % CHOICES + 1;
        int id = rand()%2 ? -(i + 1) : i+1;
        rand_string(&strtemp);

        switch (choice) {
            case 1:
            case 2:
            case 3:
                //PUSH
                if(stack.push(id, strtemp)){
                    cout << "Pushed: " << id << ": " << strtemp << endl;
                } else {
                    cout << "Error: Item not pushed: " << id << ": " << strtemp << endl;
                }
                break;
            case 4:
            case 5:
            case 6:
                // POP
                if(stack.pop(dataItem)){
                    cout << "Popped: ";
                    cout << dataItem.id << ": " << dataItem.information << endl;
                } else { 
                    cout << "Pop error: Unable to pop" << endl;
                }
                break;
            case 7:
                // PEEK
                if(stack.peek(dataItem)){
                    cout << "Peeked: ";
                    cout << dataItem.id << ": " << dataItem.information << endl;
                    } else {
                        cout << "Peek underflow error: stack is empty" << endl;
                    }
                break;
            case 8:
                // isEmpty
                if (stack.isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is NOT empty" << endl;
                }
                break;
            case 9:
                //Get Size
                try {
                    cout << "Stack size: " << stack.getSize() << endl;
                } catch (...) {
                    cout << "Error: Unable to get size" << endl;
                }
                break;
            }
        }

    cout << endl;
    } // Close if statement
 return exitCode;
}

