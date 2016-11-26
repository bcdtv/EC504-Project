#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include "VEB.h"

using namespace std;

// ============ Public Method Implementations ============
VEB::VEB(){
  // initialize summary bit vector
  summary.resize(sqrt(INT_MAX), 0);

  // raise empty flag
  is_empty = true;
}

VEB::VEB(vector<int> numbers){

}

int VEB::successor(int value){
  return 0;
}

int VEB::predecessor(int value){
  return 0;
}

void VEB::insert(int value){ 
  // use the helper method for recursion
  insert_helper(this, value);
}

void VEB::remove(int value){

}

// Returns true if the vEB tree is empty.
bool VEB::empty(){
  return is_empty; 
}

int VEB::size(){
  return size;
}

// Display all the values within the vEB tree,
// this is useful for testing purposes.
void VEB::display(){
  cout << "VEB Tree: ";

  // use the helper method for recursion
  if (!is_empty){
    display_helper(this);
  }

  cout << endl;
}
// =======================================================

// ============ Private Method Implementations ===========
int VEB::low(int value){
  return (value % (int) sqrt(INT_MAX));
}

int VEB::high(int value){
  return (value / (int) sqrt(INT_MAX));
}

void VEB::insert_helper(VEB* vEB, int value){
  // increment size
  vEB->size++;

  // calculate cluster this value belongs to
  int cluster = high(value);
  
  // calculate position within cluster
  int position = low(value);

  // if cluster is empty, update the summary structure
  if ((vEB->summary)[cluster] == 0){
    (vEB->summary)[cluster] = 1;
  }

  // tree was empty so simply set min and max values
  if (vEB->is_empty){
    vEB->min = position;
    vEB->max = position;
    vEB->is_empty = false;
    return;
  }

  // inserted value is less than current min
  if (position < vEB->min){
    // passed value is new min, old min needs to be inserted
    int temp = vEB->min;
    vEB->min = position;
    position = temp;
  }

  // update max value if required
  if (position > vEB->max){
    vEB->max = position;
  }

  // finally, insert value into the cluster
  insert_helper(&(vEB->clusters[cluster]), position);
}

void VEB::display_helper(VEB* vEB){
  // vEB is guaranteed to not be empty
  cout << vEB->min << " ";

  // iterate over the summary vector
  for (int i=0; i<(vEB->summary).size(); i++){
    // recursively display non empty clusters
    if ((vEB->summary)[i] > 0){
      display_helper(&((vEB->clusters)[i]));
    }
  }
}

// =======================================================




