#include <climits>
#include <vector>
#include "sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/VEB.h"

using namespace std;

// To return a sorted list of numbers that
// are stored in a binary heap, simply call
// extract min until the heap is empty.
vector<int> sort(BinaryHeap* heap){
  vector<int> result(heap->size());
  while(!(heap->empty())){
    result.push_back(heap->extract_min());
  }
  return result;
}

// There are two possible ways to return a
// sorted list of numbers from a vEB tree.
// One way is to get the min and then call 
// remove(min) until the tree is empty.
// Another way is to continously call
// successor. Both will be tested for
// performance.
vector<int> sort(VEB* vEB, int method){
  vector<int> result(vEB->size());

  if (method == 1){
    while(!(vEB->empty())){
      result.push_back(vEB->min);
      vEB->remove(vEB->min);
    }
  }

  if (method == 2){
    int value = INT_MIN;
    for (int i=0; i<vEB->size(); i++){
      value = vEB->successor(value);
      result.push_back(value);
    }
  }

  return result;
}
