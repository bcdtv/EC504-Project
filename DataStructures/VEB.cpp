#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include "VEB.h"

using namespace std;

// ============ Public Method Implementations ============
// A constructor for creating an empty vEB tree.
VEB::VEB(){
  // initialize summary bit vector
  summary.resize(2*sqrt(INT_MAX), 0);

  // raise empty flag
  is_empty = true;
}

int VEB::successor(int value){

  // use the helper method for recursion
  return successor_helper(this, value);
}

int VEB::predecessor(int value){
  return 0;
}

// Insert a new value into the vEB tree. This
// is done using recursion because the vEB tree
// is a recursive data structure. Look at the
// helper function for implementation.
void VEB::insert(int value){ 
  // make sure value is supported
  int universe = (int) sqrt(INT_MAX) * (int) sqrt(INT_MAX);
  if (abs(value) > universe-1){
    return;
  } 

  // use the helper method for recursion
  insert_helper(this, value);
}

int VEB::min(){
  return min_value;
}

int VEB::max(){
  return max_value;
}

void VEB::remove(int value){

}

// Returns true if the vEB tree is empty.
bool VEB::empty(){
  return is_empty; 
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
int VEB::get_cluster(int value){
  int cluster;
  if (value >= 0){
    cluster = (value / (int) sqrt(INT_MAX)) + sqrt(INT_MAX);
  }
  else {
    cluster = (value + INT_MAX) / sqrt(INT_MAX);
  }
  return cluster;
}

int VEB::get_position(int value){
  int position;
  if (value >= 0){
    position = value % (int) sqrt(INT_MAX);
  }
  else{
    position = abs((int) abs(value) % (int) sqrt(INT_MAX) - (int) sqrt(INT_MAX));
  }
  return position;
}

int VEB::successor_helper(VEB* vEB, int value){
  // return min if value is less
  if (value < vEB->min_value){
    return vEB->min_value;
  }

  // calculate the cluster this value would belong to
  int cluster = get_cluster(value);

  // calculate the position of this value within that cluster
  int position = value % (int) sqrt(INT_MAX);

  // position is less than max of cluster it would belong to
  if (value < ((vEB->clusters)[cluster]).max_value){
    // call successor on that cluster
    return successor_helper(&((vEB->clusters)[cluster]), position);
  }

  // position is higher, successor is in next non empty cluster
  else{
    return 0;
  }
}

void VEB::insert_helper(VEB* vEB, int value){
  // tree was empty so simply set min and max values
  if (vEB->is_empty){
    vEB->min_value = value;
    vEB->max_value = value;
    vEB->is_empty = false;
    return;
  }

  // inserted value is less than current min
  if (value < vEB->min_value){
    // passed value is new min, old min needs to be inserted
    int temp = vEB->min_value;
    vEB->min_value = value;
    value = temp;
  }

  // update max value if required
  if (value > vEB->max_value){
    vEB->max_value = value;
  }

  // calculate cluster this value belongs to
  int cluster = get_cluster(value);

  // calculate position within cluster
  int position = get_position(value);

  // if cluster is empty, update the summary structure
  if ((vEB->summary)[cluster] == 0){
    (vEB->summary)[cluster] = 1;
  }

  // finally, insert value into the cluster
  insert_helper(&((vEB->clusters)[cluster]), value);
}

void VEB::display_helper(VEB* vEB){
  // vEB is guaranteed to not be empty
  cout << vEB->min_value << " ";

  // iterate over the summary vector
  for (int i=0; i<(vEB->summary).size(); i++){
    // recursively display non empty clusters
    if ((vEB->summary)[i] > 0){
      display_helper(&((vEB->clusters)[i]));
    }
  }
}
// =======================================================




