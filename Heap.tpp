#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>  // for floor
#include <stdexcept> // for std::out_of_range
#include <algorithm> // for std::swap

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);
  void heapifyUp(int index);
  void heapifyDown(int index);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
  values.push_back(value);
  heapifyUp(values.size() - 1);
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  if (values.empty()) {
    throw std::out_of_range("Heap is empty");
  }

  auto it = std::find(values.begin(), values.end(), value);
  if (it == values.end()) {
    throw std::invalid_argument("Value not found in heap");
  }

  int index = std::distance(values.begin(), it);
  values[index] = values.back();
  values.pop_back();

  if (index < values.size()) {
    heapifyUp(index);
    heapifyDown(index);
  }
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  if (values.empty()) {
    throw std::out_of_range("Heap is empty");
  }
  return values.front();
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  if (parent_index < 0 || parent_index >= values.size()) return;

  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;
  int index_of_smallest = parent_index;

  if (left_child_index < values.size() && values[left_child_index] < values[index_of_smallest]) {
    index_of_smallest = left_child_index;
  }

  if (right_child_index < values.size() && values[right_child_index] < values[index_of_smallest]) {
    index_of_smallest = right_child_index;
  }

  if (index_of_smallest != parent_index) {
    std::swap(values[parent_index], values[index_of_smallest]);
    heapify(index_of_smallest);
  }
}

template <typename T>
void Heap<T>::heapifyUp(int index) {
  while (index > 0) {
    int parentIndex = (index - 1) / 2;
    if (values[index] >= values[parentIndex]) {
      break;
    }
    std::swap(values[index], values[parentIndex]);
    index = parentIndex;
  }
}

template <typename T>
void Heap<T>::heapifyDown(int index) {
  int size = values.size();
  while (index < size) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && values[leftChild] < values[smallest]) {
      smallest = leftChild;
    }
    if (rightChild < size && values[rightChild] < values[smallest]) {
      smallest = rightChild;
    }
    if (smallest == index) {
      break;
    }
    std::swap(values[index], values[smallest]);
    index = smallest;
  }
}

#endif // HEAP_H
