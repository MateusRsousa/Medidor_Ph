
#include <Arduino.h>


class Node {

    float val;
    Node* next;
   String timestamp;
   
  public:
         
    Node(float dat,const String& time, Node* nxt);
    float getVal();
    String getTimestamp();
    Node* getNext();
    void setNext(Node* nxt);
};