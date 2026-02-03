#include "Node.h"
#include "Display.h"
#include "Clock.h"



class List  {

  Node* head;

public:
  List();
  ~List();
  void insertAfterLast(float dat, const String& timestamp);
  void removeAll();
  void listAll(Display &display, Clock &clock);
};