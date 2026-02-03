

#include "Node.h"

// Constructor - initializes the node
//
Node::Node(float dat,const String& time, Node* nxt)
   : val(dat), timestamp(time), next(nxt) {}

// getVal returns the integer value stored in the node
//
float Node::getVal(){
     return val;
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

String Node::getTimestamp() {
    return timestamp;
}

void Node::setNext(Node* nxt){
       next = nxt;
}