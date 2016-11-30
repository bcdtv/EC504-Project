#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include "VEB.h"

using namespace std;

// ============ Public Method Implementations ============
// A constructor for creating an empty vEB tree.
VEB::VEB(){
  u = UINT_MAX;
  summary = NULL;
  is_empty = true;
}

// Retrieve the next value within the vEB tree.
// This is done using recursion because the vEB
// tree is a recursive data structure. Look at
// the helper method for implementation.
unsigned int VEB::successor(unsigned int value){
  return successor_helper(this, value);
}

// Retrieve the previous value within the vEB tree.
// This is done using recursion because the vEB
// tree is a recursive data structure. Look at
// the helper method for implementation.
unsigned int VEB::predecessor(unsigned int value){
  return predecessor_helper(this, value);
}

// Insert a new value into the vEB tree. This
// is done using recursion because the vEB tree
// is a recursive data structure. Look at the
// helper method for implementation.
void VEB::insert(unsigned int value){
  insert_helper(this, value, 1);
}

// Remove a value from within the vEB tree.
// This is done using recursion because the vEB
// tree is a recursive data structure. Look at
// the helper method for implementation.
void VEB::remove(unsigned int value){
  remove_helper(this, value, 1);
}

// Return the minimum value stored.
unsigned int VEB::min(){
  return min_value;
}

// Return the maximum value stored.
unsigned int VEB::max(){
  return max_value;
}

// Returns true if the vEB tree is empty.
bool VEB::empty(){
  return is_empty; 
}

// Display all the values within the vEB tree.
// This is done using recursion because the
// vEB tree is a recursive data structure. Look
// at the helper method for implementation.
void VEB::display(){
  cout << "VEB Tree: ";
  if (!is_empty){
    display_helper(this, 0);
  }
  cout << endl;
}
// =======================================================

// ============ Private Method Implementations ===========
VEB::VEB(unsigned int u){
  this->u = u;
  summary = NULL;
  is_empty = true;
}

unsigned int VEB::successor_helper(VEB* vEB, unsigned int value){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // return min if value is less
  if (value < vEB->min_value){
    return vEB->min_value;
  }

  // calculate the cluster this value would belong to
  unsigned int cluster =  value / ((unsigned int) sqrt(vEB->u));

  // calculate the position of this value within its cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

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

unsigned int VEB::predecessor_helper(VEB* vEB, unsigned int value){
  return 0;
}

void VEB::insert_helper(VEB* vEB, unsigned int value, unsigned int count){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // vEB tree was empty, simply set min and max values
  if (vEB->is_empty){
    vEB->min_value = value;
    vEB->min_count = count;
    vEB->max_value = value;
    vEB->max_count = count;
    vEB->is_empty = false;
    return;
  }

  // value equals min, simply increment min count
  if (value == vEB->min_value){
    (vEB->min_count)++;
    return;
  }

  // terminate recursion if at base vEB tree
  if (vEB->u <= 1){
    return;
  }

  // if required, swap passed value and current min
  if (value < vEB->min_value){
    unsigned int temp = vEB->min_value;
    vEB->min_value = value;
    value = temp;
    temp = vEB->min_count;
    vEB->min_count = count;
    count = temp;
  }

  // if required, increment max count
  if (value == vEB->max_value){
    (vEB->max_count)++;
  }

  // if required, update max value
  if (value > vEB->max_value){
    vEB->max_value = value;
    vEB->max_count = count;
  }

  // calculate cluster this value belongs to
  unsigned int cluster_i =  value / ((unsigned int) sqrt(vEB->u));

  // calculate position within cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

  // if required, create the cluster
  try{
    VEB cluster = (vEB->clusters).at(cluster_i);
  }
  catch (exception out_of_range){
    VEB cluster = VEB(sqrt(vEB->u));
    (vEB->clusters)[cluster_i] = cluster;
  }

  // insert position value into the cluster
  insert_helper(&((vEB->clusters)[cluster_i]), position, count);

  // if cluster was previously empty, update the summary structure
  if ((vEB->clusters)[cluster_i].min_value == (vEB->clusters)[cluster_i].max_value){
    insert_helper(vEB->summary, cluster_i, 1);
  }
}

void VEB::remove_helper(VEB* vEB, unsigned int value, unsigned int count){

}

void VEB::display_helper(VEB* vEB, unsigned int base){
  // vEB is guaranteed to not be empty
  for (unsigned int i=0; i<vEB->min_count; i++){
    cout << base + vEB->min_value << " ";
  }

  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // get the iterators for the clusters map
  map<unsigned int, VEB>::iterator it = vEB->clusters.begin();
  map<unsigned int, VEB>::iterator end = vEB->clusters.end();

  // retrieve the keys of non empty clusters
  vector<unsigned int> keys;
  for (it; it != end; ++it){
    keys.push_back(it->first);
  } 

  // sort the keys to ensure values are printed in order
  sort(keys.begin(), keys.end());

  // display each cluster
  for (unsigned int i=0; i<keys.size(); i++){
    unsigned int new_base = ((vEB->clusters)[keys[i]]).u * keys[i] + base;
    display_helper(&((vEB->clusters)[keys[i]]), new_base);
  }
}
// =======================================================




