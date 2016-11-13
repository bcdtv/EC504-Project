#include <climits>
#include <math.h>
#include <vector>
#include <iostream>
#include "BinaryHeap.h"

#define NOT_FOUND -1

using namespace std;

// ============ Public Method Implementations ============

BinaryHeap::BinaryHeap() {
  cout << "Creating a default empty Binary Heap" << endl;
}

BinaryHeap::~BinaryHeap() {
  cout << "Deleting the Binary Heap" << endl;
}
// This constructor builds a binary heap by 
// treating an input array as a complete binary 
// tree and calling minHeapify on each node.
BinaryHeap::BinaryHeap(vector<int> numbers){
  cout << "Creating a Binary Heap initalized with an array of length: ";
  cout << numbers.size() << endl;
  this->nodes = numbers;
  for(int i=nodes.size()-1; i>=0; i--){
    minHeapify(i);
  }
  
}

void BinaryHeap::insert(int value) {
  // place value into the end of the heap 
  nodes.push_back(value);

  // get current value and index and find the parent. 
  int curr_value = value;
  int curr_index = nodes.size()-1;
  int parent = floor((curr_index - 1) / 2);
  
  // heapify upwards. 
  while (parent>=0 && curr_value < nodes[parent]) {
    // swap values around
    int temp = nodes[parent];
    nodes[parent] = curr_value;
    nodes[curr_index] = temp; 

    //update current index, value, and parent. 
    curr_index = parent; 
    curr_value = nodes[curr_index];
    parent = floor((curr_index - 1) / 2);
  };
}

void BinaryHeap::remove(int value){
  int index = this->getIndex(value);
  cout << index << endl;
  this->nodes.at(index) = INT_MIN;
  minHeapify(0);
  this->extract();
}


int BinaryHeap::getIndex(int value) {
  for (int i=0; i < nodes.size(); i++) {
      if (this->nodes.at(i) == value) {
        return i;
      } 
    }
  return NOT_FOUND;
}

void BinaryHeap::display() {
  cout << nodes.size() << endl;
    for(int i = 0; i < nodes.size(); i++) {
      cout << "anything " << i << endl;
      cout << nodes.at(i) << " ";
    }
    cout << endl;
}
// Returns the current value at the root
// of the heap. To maintain the min heap
// property, the last value becomes the new
// root and minHeapify is called on it.
int BinaryHeap::extract(){
  // get the root value
  int root = nodes[0];

  // make the last value the root
  nodes[0] = nodes[nodes.size()-1];

  // delete the obsolete last value
  nodes.pop_back();

  // heapify the new root
  minHeapify(0);

  // return the old root value
  return root;
}

// Returns whether or not the heap is empty.
bool BinaryHeap::isEmpty() {
  return nodes.size() == 0;
}


// This method is used to access the heap
// nodes for testing purposes.
vector<int> BinaryHeap::getNodes(){
  return nodes;
}
// =======================================================

// ============ Private Method Implementations ===========
void BinaryHeap::minHeapify(int current_i){
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
    minHeapify(smallest_i);
  }
}
// =======================================================



