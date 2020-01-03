#include "hashTable.h"

/* Node */
Node::Node () {
  key = -1;
  value = "";
  neighbor = nullptr;
}

Node::Node (const int key, const std::string value) {
  Node::key = key;
  Node::value = value;
  neighbor = nullptr;
}

void Node::setNode (const int key, const std::string value) {
  Node::key = key;
  Node::value = value;
}

void Node::setNeighbor (const int key, const std::string value) {
  if ( this->neighbor == nullptr ) this->neighbor = new Node(key, value);
  else {
    Node* neighbor = this->neighbor;
    while ( neighbor->neighbor != nullptr ) {
      neighbor = neighbor->neighbor;
    }
    neighbor->neighbor = new Node(key, value);
  }
}

int Node::getKey () const { return key; }

std::string Node::getValue () const { return value; }

Node Node::getNeighbor () { return *neighbor; }

bool Node::hasNeighbor () const { return !!this->neighbor; }

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
    if ( hashTable[index].getKey() != -1 && hashTable[index].getKey() != key) {
      hashTable[index].setNeighbor(key, value);
    } else {
      hashTable[index].setNode(key, value);
      ++currentSize;
    }
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
    if ( hashTable[i].getKey() != -1 ) {
      std::cout << i << "--> " << hashTable[i].getKey() << " - " << hashTable[i].getValue();
      if ( hashTable[i].hasNeighbor() ) {
        Node item = hashTable[i];
        while ( item.hasNeighbor() ) {
          item = item.getNeighbor();
          std::cout << " --> " << item.getKey() << " - " << item.getValue() << ' ';
        }
      }
      std::cout << '\n';
    } else
        std::cout << i << '\n';
  }
  std::cout << '\n';
}
