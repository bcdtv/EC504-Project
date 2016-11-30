#include <climits>
#include <iostream>
#include <math.h>
#include <vector>
#include "BinaryHeap.h"

#define NOT_FOUND -1

using namespace std;

// ============ Public Method Implementations ============
// A constructor for creating an empty binary heap.
BinaryHeap::BinaryHeap(){
}

// This constructor builds a binary heap by 
// treating an input array as a complete binary 
// tree and calling heapify down on each node.
BinaryHeap::BinaryHeap(vector<unsigned int> numbers){
  this->nodes = vector<int>(numbers.size());
  for (int i=0; i<numbers.size(); i++){
    this->nodes[i] = (int) numbers[i];
  }
  for(int i=nodes.size()-1; i>=0; i--){
    heapify_down(i);
  }
}

// Insert a new value into the heap. This is done
// by first adding the new value to the end of the
// heap. Afterwards, heapify up is called on the 
// new node to ensure the min heap property is held.
void BinaryHeap::insert(int value){
  nodes.push_back(value);
  heapify_up(nodes.size()-1);
}

// Removes a selected value from the heap by first
// finding the value within the heap. Then, it sets
// the nodes value to negative infinity. Afterwards,
// heapify up is called on the node to move it to
// the root. Lastly, extract min is called to pop
// the node off of the heap.
void BinaryHeap::remove(int value){
  // find the value within the heap
  int index = this->get_index(value);

  // exit early if value not found
  if (index == NOT_FOUND){
    return;
  }

  // set node to negative infinity
  this->nodes.at(index) = INT_MIN;

  // heapify the node up to the root
  heapify_up(index);

  // extract the node from the heap
  this->extract_min();
}

// Returns and removes the current value at the root
// of the heap. To maintain the min heap property, 
// the last value becomes the new root and heapify 
// down is called on it.
int BinaryHeap::extract_min(){
  // get the root value
  int root = nodes[0];

  // make the last value the root
  nodes[0] = nodes[nodes.size()-1];

  // delete the obsolete last value
  nodes.pop_back();

  // heapify the new root
  heapify_down(0);

  // return the old root value
  return root;
}

// Returns whether or not the heap is empty.
bool BinaryHeap::empty(){
  return nodes.size() == 0;
}

// Returns the amount of data stored in the heap.
int BinaryHeap::size(){
  return nodes.size();
}

// Display all the nodes within the heap. This
// is useful for testing purposes.
void BinaryHeap::display(){
  cout << "Binary Heap: ";
  for(int i = 0; i < nodes.size(); i++){
    cout << nodes.at(i) << " ";
  }
  cout << endl;
}

// Checks if the binary heap maintains the
// min heap property.
bool BinaryHeap::valid(){
  return valid_subheap(0);
}
// =======================================================

// ============ Private Method Implementations ===========
void BinaryHeap::heapify_down(int current_i){
  // get the size of the heap
  int size = nodes.size();

  // calculate index for left and right children
  int left_i = current_i*2+1;
  int right_i = current_i*2+2;

  // find the index for the smallest value
  int smallest_i = current_i;
  if (left_i < size) {
    if (nodes[left_i] < nodes[smallest_i]){
      smallest_i = left_i;
    } 
  }
  if (right_i < size) {
    if(nodes[right_i] < nodes[smallest_i]) {
      smallest_i = right_i;
    }
  } 

  // swap and call recursively if necessary
  if (smallest_i != current_i){
    int temp = nodes[current_i];
    nodes[current_i] = nodes[smallest_i];
    nodes[smallest_i] = temp;
    heapify_down(smallest_i);
  }
}

void BinaryHeap::heapify_up(int current_i){
  // get current value and index and find the parent 
  int curr_value = nodes[current_i];
  int curr_index = current_i;
  int parent = floor((curr_index - 1) / 2);
  
  // heapify upwards
  while (parent>=0 && curr_value < nodes[parent]){
    // swap values around
    int temp = nodes[parent];
    nodes[parent] = curr_value;
    nodes[curr_index] = temp; 

    // update current index, value, and parent
    curr_index = parent; 
    curr_value = nodes[curr_index];
    parent = floor((curr_index - 1) / 2);
  }
}

int BinaryHeap::get_index(int value){
  for (int i=0; i < nodes.size(); i++){
    if (this->nodes.at(i) == value){
      return i;
    } 
  }
  return NOT_FOUND;
}

bool BinaryHeap::valid_subheap(int current_i){
  // get the size of the total heap
  int size = nodes.size();

  // calculate index for left and right children
  int left_i = current_i*2+1;
  int right_i = current_i*2+2;

  // find the index for the smallest value
  int smallest_i = current_i;
  if (left_i < size) {
    if (nodes[left_i] < nodes[smallest_i]){
      smallest_i = left_i;
    } 
  }
  if (right_i < size) {
    if(nodes[right_i] < nodes[smallest_i]) {
      smallest_i = right_i;
    }
  } 

  // stop if the min heap property is violated
  if (smallest_i != current_i){
    return false;
  }

  // otherwise, check both children
  bool left = true;
  bool right = true;
  if (left_i < size){
    left = valid_subheap(left_i);
  }
  if (right_i < size){
    right = valid_subheap(right_i);
  }
  return left && right;
}
// =======================================================



