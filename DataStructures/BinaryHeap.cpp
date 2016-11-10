#include <vector>
#include "BinaryHeap.h"

// ============ Public Method Implementations ============

// This method builds a binary heap by treating
// an input array as a complete binary tree and
// calling minHeapify on each node.
BinaryHeap::BinaryHeap(std::vector<int> numbers){
  nodes = numbers;
  for(int i=nodes.size()-1; i>=0; i--){
    minHeapify(i);
  }
}

void BinaryHeap::insert(int value){

}

void BinaryHeap::remove(int value){

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
bool BinaryHeap::isEmpty(){
  return nodes.size() == 0;
}

int BinaryHeap::successor(int value){

}

int BinaryHeap::predecessor(int value){

}

// This method is used to access the heap
// nodes for testing purposes.
std::vector<int> BinaryHeap::getNodes(){
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
  if ((left_i < size) && (nodes[left_i] < nodes[smallest_i])){
    smallest_i = left_i;
  }
  if ((right_i < size) && (nodes[right_i] < nodes[smallest_i])){
    smallest_i = right_i;
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



