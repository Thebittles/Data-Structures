
bool LinkedList::addNode(int id, string *data) {
    bool added = false;

    if(id > 0 && *data!=""){
        Node *current = head;
        Node *previous = head;

        // find position to add
        while(current && id > current->data.id){
            previous = current;
            current = current->next;
        }
        
        if(!head || (current == head && head->data.id != id)){
            added = addHead(id, data);
        } else if(!current){
            added = addTail(id, data, previous);
        } else if(current->data.id != id){
            added = addMiddle(id, data, current);
        }
    }
    return added;
}



bool LinkedList::addHead(int id, string *str) {
    Node *newNode = makeNode(id, str);
    if(!head){
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    return newNode ? true : false;
}




bool LinkedList::deleteNode(int id) {
    Node *current = head;
    bool deleted = false;

    //find node to delete
    while (current && id != current->data.id) {
        current = current->next;
    }

    if (current) {
        if (head == current) {
            delHead();
        } else if (current->next == NULL) {
            delTail(current);
        } else {
            delMiddle(current);
        }
        deleted = true;
    }

    return deleted;
}

void LinkedList::delHead() {
    if (head->next) {
        head = head->next;
        delete head->prev;
    } else {
        delete head;
        head = NULL;
    }
}

