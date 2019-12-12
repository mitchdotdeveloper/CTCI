#include "hashTable.h"

int main () {

  HashMap myMap(10);

  myMap.insertHash(42, "a");
  myMap.insertHash(20, "b");
  myMap.insertHash(10, "c");
  myMap.insertHash(11, "d");
  myMap.insertHash(41, "e");
  myMap.insertHash(63, "f");
  myMap.insertHash(45, "g");
  myMap.insertHash(17, "h");
  myMap.insertHash(74, "i");
  myMap.insertHash(373, "j");

  myMap.insertHash(456, "k"); //6
  myMap.insertHash(4, "l"); //4
  myMap.insertHash(5, "m"); //5
  myMap.insertHash(345, "n"); //5
  myMap.insertHash(85, "o"); //5
  myMap.displayHash();

  return 0;
}
