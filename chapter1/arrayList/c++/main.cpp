#include "arrayList.h"

int main () {
  ArrayList<int> *myList = new ArrayList<int>;

  myList->push(1);
  myList->push(2);
  myList->push(3);
  myList->push(99);
  myList->print();

  myList->pop();
  myList->pop();
  myList->print();

  myList->push(99);
  myList->print();

  return 0;
}
