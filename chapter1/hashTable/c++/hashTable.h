#ifndef HASHMAP_H_
#define HASHMAP_H_
#include <iostream>

class Node {
  int key;
  std::string value;
  Node *neighbor;
public:
  Node ();
  Node (const int key, const std::string value);
  void setNode (const int key, const std::string value);
  void setNeighbor (const int key, const std::string value);
  int getKey () const;
  std::string getValue () const;
  Node getNeighbor ();
  bool hasNeighbor () const;
};

class HashMap {
  Node *hashTable;
  int tableSize;
  int currentSize;
public:
  HashMap (int tableSize);
  bool isFull () const;
  void insertHash (const int key, const std::string value);
  void removeHash (int key);
  int hash1 (int key) const;
  int hash2 (int key) const;
  void displayHash ();
};

#endif /* HASHMAP_H_ */
