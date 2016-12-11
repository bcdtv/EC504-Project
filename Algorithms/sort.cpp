#include <climits>
#include <vector>
#include "sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/BST.h"
#include "../DataStructures/Deque.h"
#include "../DataStructures/VEB.h"

using namespace std;

// To return a sorted list of numbers that
// are stored in a binary heap, simply call
// extract min until the heap is empty.
vector<unsigned int> sort(BinaryHeap* heap){
  unsigned int i = 0;
  vector<unsigned int> result(heap->size());
  while(!(heap->empty())){
    result[i] = heap->extract_min();
    i++;
  }
  return result;
}

vector<unsigned int> sort(BST* bst){
  return vector<unsigned int>();
}

// Because a deque does not contain a 
// natural way to retreive a sorted list,
// an extract min method was implemented
// to make it simpler code-wise.
vector<unsigned int> sort(Deque* deque){
  unsigned int i = 0;
  vector<unsigned int> result(deque->size());
  while(!(deque->empty())){
    result[i] = deque->extract_min();
    i++;
  }
  return result;
}

// To return a sorted list of numbers
// from a vEB tree, simply retrieve 
// the elements stored in the tree.
// This is possible because a vEB tree
// stores elements in sorted order.
vector<unsigned int> sort(VEB* vEB){
  return vEB->elements();
}
