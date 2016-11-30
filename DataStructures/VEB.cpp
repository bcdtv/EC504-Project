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
  is_empty = true;
  n = 0;
  summary = NULL;
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
  n++;
}

// Remove a value from within the vEB tree.
// This is done using recursion because the vEB
// tree is a recursive data structure. Look at
// the helper method for implementation.
void VEB::remove(unsigned int value){
  if (remove_helper(this, value, 1)){
    n--;
  }
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

// Returns the number of elements stored
// in the vEB tree.
unsigned int VEB::size(){
  return n;
}

// Returns the elements stored in the
// vEB tree. This is done using recursion
// because the vEB tree is a recursive data
// structure. Look at the helper method
// for implemenentation.
vector<unsigned int> VEB::elements(){
  count = 0;
  vector<unsigned int> result(n);
  elements_helper(this, 0, &result);
  return result;
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
  is_empty = true;
  summary = NULL;
}

unsigned int VEB::successor_helper(VEB* vEB, unsigned int value){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // handle empty vEB tree
  if (vEB->is_empty){
    return 0;
  }

  // return min if value is less than vEB min
  if (value < vEB->min_value){
    return vEB->min_value;
  }

  // if value hits limit, return universe size
  if (value >= vEB->max_value){
    return vEB->u;
  }

  // calculate the cluster this value would belong to
  unsigned int cluster_i =  value / ((unsigned int) sqrt(vEB->u));

  // calculate the position of this value within its cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

  // check if that cluster even exists
  bool exists;
  try{
    (vEB->clusters).at(cluster_i);
    exists = true;
  }
  catch (exception out_of_range){
    exists = false;
  }

  // successor is within the cluster this value would belong to
  if (exists && position < ((vEB->clusters)[cluster_i]).max_value){
    unsigned int base = value - position;
    return base + successor_helper(&((vEB->clusters)[cluster_i]), position);
  }

  // successor is min value of next non empty cluster
  unsigned int next_cluster = successor_helper(vEB->summary, cluster_i);
  unsigned int base = ((vEB->clusters)[next_cluster]).u * next_cluster;
  return base + ((vEB->clusters)[next_cluster]).min_value;
}

unsigned int VEB::predecessor_helper(VEB* vEB, unsigned int value){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // handle empty vEB tree
  if (vEB->is_empty){
    return 0;
  }

  // return max if value is greater than vEB max
  if (value > vEB->max_value){
    return vEB->max_value;
  }

  // calculate the cluster this value would belong to
  unsigned int cluster_i =  value / ((unsigned int) sqrt(vEB->u));

  // calculate the position of this value within its cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

  // check if that cluster even exists
  bool exists;
  try{
    (vEB->clusters).at(cluster_i);
    exists = true;
  }
  catch (exception out_of_range){
    exists = false;
  }

  // predecessor is within the cluster this value would belong to
  if (exists && position > ((vEB->clusters)[cluster_i]).min_value){
    unsigned int base = value - position;
    return base + predecessor_helper(&((vEB->clusters)[cluster_i]), position);
  }

  // get the previous cluster
  unsigned int previous_cluster = predecessor_helper(vEB->summary, cluster_i);

  // there is no previous cluster
  if (cluster_i == previous_cluster){
    if (exists){
      return ((vEB->clusters)[cluster_i]).min_value;
    }
    else{
      return 0;
    }
  }

  // predecessor is max value of previous non empty cluster 
  unsigned int base = ((vEB->clusters)[previous_cluster]).u * previous_cluster;
  return base + ((vEB->clusters)[previous_cluster]).max_value;
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
    vEB->is_empty = false;
    return;
  }

  // value equals min, simply increment min count
  if (value == vEB->min_value){
    vEB->min_count = vEB->min_count + count;
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

  // if required, update max value
  if (value > vEB->max_value){
    vEB->max_value = value;
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

unsigned int VEB::remove_helper(VEB* vEB, unsigned int value, unsigned int count){
  return 0;
}

void VEB::elements_helper(VEB* vEB, unsigned int base, vector<unsigned int>* result){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // vEB is guaranteed to not be empty
  for (unsigned int i=0; i<vEB->min_count; i++){
    result->at(count) = base + vEB->min_value;
    count++;
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

  // get elements of each cluster
  for (unsigned int i=0; i<keys.size(); i++){
    unsigned int new_base = ((vEB->clusters)[keys[i]]).u * keys[i] + base;
    elements_helper(&((vEB->clusters)[keys[i]]), new_base, result);
  }
}

void VEB::display_helper(VEB* vEB, unsigned int base){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // vEB is guaranteed to not be empty
  for (unsigned int i=0; i<vEB->min_count; i++){
    cout << base + vEB->min_value << " ";
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




