#include <algorithm>
#include <vector>
#include "BinaryHeap.h"

// Node implementation
BinaryHeap::Node::Node(){
  parent = NULL;
  left = NULL;
  right = NULL;
}

BinaryHeap::Node::Node(int value){
  this->value = value;
  parent = NULL;
  left = NULL;
  right = NULL;
}

// BinaryHeap implementation
BinaryHeap::BinaryHeap(){
  root = NULL;
}

BinaryHeap::BinaryHeap(vector<int> numbers){
  /*
     By treating the vector as a complete binary tree,
     we can simply call minHeapify on each subtree starting
     from the bottom subtree in order to create a binary 
     heap. This runs in O(n).
     https://en.wikipedia.org/wiki/Binary_heap
  */
}

BinaryHeap::BinaryHeap(BinaryHeap& other){
  /*
    Here we need to traverse the given tree
    and create a copy of all nodes in this tree.
    The copied nodes need to be created using the
    new keyword in order to make it a deep copy.
  */
}

BinaryHeap::~BinaryHeap(){
  /*
    Traverse the tree and delete every node along 
    the way from dynaminc memory using the delete 
    keyword. As we traverse, we create a nondynamic 
    copy of the current node so that we can continue 
    traversing.
  */
}

BinaryHeap& BinaryHeap::operator=(const BinaryHeap& other){
  /*
    Here we do not make a deep copy but rather a soft copy
    which points to the same memory address. This means we
    just need to point our root node to the passed heap's root
    node. The swap function from the algorithm library makes 
    this easy. This requires a functioning copy constructor.
  */

  BinaryHeap temp = BinaryHeap(other);
  std::swap(temp.root, root);
  return *this;
}

int BinaryHeap::extract(){
  /*

  */ 
}

void BinaryHeap::insert(int value){
  /*
    Create node, add to end of heap, then call minHeapify 
    recursively until the min heap property is held.
  */
} 

void BinaryHeap::minHeapify(Node* node){
  if (node.parent == NULL){
    return;
  }

  if (node.parent.value <= node.value){
    return;
  }

  // swap code goes here
}



