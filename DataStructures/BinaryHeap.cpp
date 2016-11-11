#include <climits>
#include <vector>
#include <iostream>
#include "BinaryHeap.h"

#define NOT_FOUND -1

using namespace std;

// ============ Public Method Implementations ============

BinaryHeap::BinaryHeap() {
  cout << "hello" << endl;
}

BinaryHeap::~BinaryHeap() {
  cout << "bye" << endl;
}
// This constructor builds a binary heap by 
// treating an input array as a complete binary 
// tree and calling minHeapify on each node.
BinaryHeap::BinaryHeap(std::vector<int> numbers){
  cout << "hello" << endl;
  this->nodes = numbers;
  for(int i=nodes.size()-1; i>=0; i--){
    minHeapify(i);
  }
  this->size = numbers.size();
  this-> min = this->nodes.at(0);
}

void BinaryHeap::insert(int value){

}

void BinaryHeap::remove(int value){
  int index = this->getIndex(value);

  this->nodes.at(index) = INT_MIN;
  minHeapify(index);
  this->extract();
  // int root = nodes[0];

  // // make the last value the root
  // nodes[0] = nodes[nodes.size()-1];

  // // delete the obsolete last value
  // nodes.pop_back();

  // // heapify the new root
  // minHeapify(0);

  // // return the old root value
  // return root;  
}

int BinaryHeap::getIndex(int value) {
  for (int i=0; i < this->nodes.size(); i++) {
      if (this->nodes.at(i) == value) {
        return i;
      } 
    }
  return NOT_FOUND;
}

void BinaryHeap::display() {

    for(int i=0;i<this->getNodes().size();i++) {

      cout << this->nodes[i] << " ";
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
bool BinaryHeap::isEmpty(){
  return nodes.size() == 0;
}

// int BinaryHeap::successor(int value){
//   int current_num = this->min;
//   int left_i = 1;
//   while(current_num < value && left_i < this->size) {
//     if(this->nodes.at(left_i) < )
//     int left_i = current_i*2+1;
//     current_num
//   }



// }

// int BinaryHeap::predecessor(int value){
//   if (value <= this->min) {
//     return  NOT_FOUND;
//   }
//   return 3;

// }

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



