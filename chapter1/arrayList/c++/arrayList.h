#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList {
  T *list;
  int size;
  int capacity;
public:
  ArrayList();
  void push (T item);
  T pop ();
  void reserve (int size);
  T& operator[] (int index);
  void print ();
};

template <typename T>
ArrayList<T>::ArrayList () {
  capacity = 4;
  size = 0;
  list = new T[capacity];
}

template <typename T>
void ArrayList<T>::push (T item) {
  if ( size >= capacity / 2 ) {
    reserve(2*capacity);
  }
  list[size++] = item;
}

template <typename T>
T ArrayList<T>::pop () {
  T *newList = new T[capacity];
  T poppedItem = list[size];
  for (int i = 0; i < size - 1; ++i)
    newList[i] = list[i];
  delete[] list;
  list = newList;
  --size;
  return poppedItem;
}

template <typename T>
T& ArrayList<T>::operator [](int index) { return list[index]; }

template <typename T>
void ArrayList<T>::reserve (int _capacity) {
  T *newList = new T[_capacity];
  for (int i = 0; i < _capacity; ++i)
    newList[i] = list[i];

  delete[] list;
  list = newList;
  capacity = _capacity;
}

template <typename T>
void ArrayList<T>::print () {
  std::cout << "[ ";
  for (int i = 0; i < size; ++i) {
    if ( i < size - 1 ) std::cout << list[i] << ", ";
    else std::cout << list[i] << " ]\n\n";
  }
}

#endif /* ARRAYLIST_H_ */
