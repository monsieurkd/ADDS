#include "LinkedList.h"

#include <limits>
#include <iostream>

//constructor
LinkedList::LinkedList() {
head = nullptr;
}

//constructor with param
LinkedList::LinkedList(int* array, int len){
    head = new Node(array[0], nullptr);
    Node* currNode = head;
    
    for (unsigned int i = 1; i < len; i++){
        currNode->link = new Node(array[i], nullptr);
        currNode = currNode->link;
    }
};


//destructor
LinkedList::~LinkedList() {
while(head != nullptr) {
deleteFromFront();
}
}

//insert at position
void LinkedList::insertPosition(int pos, int newNum) {
// if adding in front of the current head (including if the list is empty)
if (pos <=  1) {
head = new Node(newNum, head);
return;
}
// if inserting between two nodes; i.e. [A, C] -> [A, B, C]
Node *prevNode = traverse(pos-1);
Node *currNode = traverse(pos);
// if inserting out of bounds, abort
if (currNode== nullptr) {
currNode= new Node(newNum, nullptr );
return;
}   
Node *newNode = new Node(newNum, prevNode->link);
prevNode->link = newNode;
}

bool LinkedList::deletePosition(int pos){  
    // Node * currNode = LinkedList::traverse(pos);
    // Node * preNode = LinkedList::traverse(pos -1);

    // if(currNode == nullptr){
    //     return false;
    // }
    // preNode = currNode->link;
    // delete currNode;
    // return true;
        if (pos < 0 || !head) {
        return false; // Invalid position or empty list
    }

    if (pos == 0) { // Special case: deleting the head
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    }

    Node* preNode = LinkedList::traverse(pos -1);
    Node* currNode = LinkedList::traverse(pos);
    int count = LinkedList::get(pos);


    if (!currNode) {
        return false; // Position out of bounds
    }

    // Link the previous node to the next one, skipping the current node
    preNode->link = currNode->link;
    delete currNode;
    return true;
};



//traverse to position
Node* LinkedList::traverse(unsigned int index) {
unsigned int position = 1;
Node* currNode = head;
while (currNode != nullptr && position < index) {
currNode = currNode->link;
position++;
}

return currNode;
}

//get data
int LinkedList::get(int pos){
    Node * currNode = LinkedList::traverse(pos);
    if (currNode == nullptr) {
        return std::numeric_limits<int>::max();
    }
    return currNode->data; 
}

//search
int LinkedList::search(int target){
    unsigned int position = 0;
Node* currNode = head;
while (currNode != nullptr) {

if (currNode->data == target) {
return position;
}
currNode = currNode->link;

position++;
}
return -1;
};



//print list

void LinkedList::printList() {
Node* currNode = head;
std::cout << "[";
while (currNode != nullptr) {
std::cout << currNode->data << " " ;
currNode = currNode->link;
}
std::cout <<  "]" << std::endl;
}

//delete from head
void LinkedList::deleteFromFront() {
//no node
if (head == nullptr) {
return;
}
//make head point to the next node, delete the head node
Node* temp = head;
head = head->link;
delete temp;
}