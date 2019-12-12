#include "hashTable.h"

/* Node */
Node::Node() {
  key = -1;
  value = "";
}

void Node::setNode (const int key, const std::string value) {
  Node::key = key;
  Node::value = value;
}

int Node::getKey () const { return key; }

std::string Node::getValue () const { return value; }

/* HashMap */
HashMap::HashMap(int tableSize) {
  hashTable = new Node[tableSize];
  HashMap::tableSize = tableSize;
  currentSize = 0;
}

bool HashMap::isFull() const { return currentSize == tableSize; }

void HashMap::insertHash(const int key, const std::string value) {
  if ( !isFull() ) {
    int index = hash1( key );
    if ( hashTable[index].getKey() != -1 && hashTable[index].getKey() != key ) {
      int index2 = hash2( key );
      int counter = 1;
      while ( true ) {
        int newIndex = (index + counter * index2) % tableSize;
        if ( hashTable[index].getKey() == -1 ) {
          hashTable[newIndex].setNode(key, value);
          break;
        }
        ++counter;
      }
    } else {
      hashTable[index].setNode(key, value);
    }
    ++currentSize;
  }
}

void HashMap::removeHash(int key) {
  int index = 0;
  while ( index < currentSize && true ) {
    if ( hashTable[index].getKey() == key ) {
      hashTable[index].setNode(-1, "");
      break;
    }
    ++index;
  }
}

int HashMap::hash1(int key) const { return key % tableSize; }

int HashMap::hash2(int key) const { return 11 - key % 11; }

void HashMap::displayHash() {
  std::cout << "Bucket --> Key - Value\n";
  for (int i = 0; i < tableSize; ++i) {
    if ( hashTable[i].getKey() != -1 )
      std::cout << i << "--> " << hashTable[i].getKey() << " - " << hashTable[i].getValue() << '\n';
    else
      std::cout << i << '\n';
  }
  std::cout << '\n';
}
