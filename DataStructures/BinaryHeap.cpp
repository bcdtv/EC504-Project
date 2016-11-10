#include <algorithm>
#include <vector>
#include "BinaryHeap.h"

// ============ Public Method Implementations ============

// This method builds a binary heap by treating
// an input array as a complete binary tree and
// calling minHeapify on each node.
BinaryHeap::BinaryHeap(std::vector<int> numbers){
  nodes = numbers;
  for(int i=nodes.size()-1; i>0; i--){
    minHeapify(i);
  }
}

void BinaryHeap::insert(int value){

}

void BinaryHeap::remove(int value){

}

int BinaryHeap::extract(){

}

// Simply returns whether or not the heap
// is empty.
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

// This method ensures that the min heap property is held
// at a particular spot within the heap.
void BinaryHeap::minHeapify(int current_i){ 
  // check if parent already satisfies min heap condition
  if (nodes[(current_i-1)/2] <= nodes[current_i]){
    return;
  }

  // calculate index for all subtree nodes
  int parent_i = (current_i-1)/2;
  int left_i = parent_i*2+1;
  int right_i = parent_i*2+2;

  // get value of all subtree nodes
  int parent = nodes[parent_i];
  int left = nodes[left_i];
  int right = nodes[right_i];

  // swap nodes until min heap condition is met
  if (left < parent){
    nodes[parent_i] = left;
    nodes[left_i] = parent;
    parent = nodes[parent_i];
  }
  if (right < parent){
    nodes[parent_i] = right;
    nodes[right_i] = parent;
  }

  // if not the root, call min heap on the new parent
  if (parent_i != 0){
    minHeapify(parent_i);
  }
}
// =======================================================



