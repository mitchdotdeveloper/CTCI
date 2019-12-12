#include "hashTable.h"

int main () {

  HashMap myMap(10);

  myMap.insertHash(42, "Hey");
  myMap.insertHash(10, "Hi");
  myMap.displayHash();

  return 0;
}
