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

// Copy constructor required for deep copying 
// the summary structure in dynamic memory.
VEB::VEB(const VEB& other){
  // copy simple fields using assignment
  u = other.u;
  min_value = other.min_value;
  min_count = other.min_count;
  max_value = other.max_value;
  is_empty = other.is_empty;
  n = other.n;
  clusters = other.clusters;

  // deep copy the summary structure
  if (other.summary == NULL){
    summary = NULL;
  }
  else{
    summary = new VEB();
    vector<unsigned int> elements = other.summary->elements();
    for (unsigned int i=0; i<elements.size(); i++){
      summary->insert(elements[i]);
    }
  }
}

// An explicit destructor is required to 
// destroy the summary structure which is
// stored in dynamic memory.
VEB::~VEB(){
  delete summary;
  summary = NULL;
}

// Copy assignment operator required for 
// deep copying the summary structure in 
// dynamic memory.
VEB& VEB::operator=(const VEB& other){
  // copy simple fields using assignment
  u = other.u;
  min_value = other.min_value;
  min_count = other.min_count;
  max_value = other.max_value;
  is_empty = other.is_empty;
  n = other.n;
  clusters = other.clusters;

  // destroy current summary structure
  delete summary;

  // deep copy the summary structure
  if (other.summary == NULL){
    summary = NULL;
  }
  else{
    summary = new VEB();
    vector<unsigned int> elements = other.summary->elements();
    for (unsigned int i=0; i<elements.size(); i++){
      summary->insert(elements[i]);
    }
  }

  return *this;
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
  vector<unsigned int> result;
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

  // handle min case
  if (value < vEB->min_value){
    return vEB->min_value;
  }

  // handle max case
  if (value >= vEB->max_value){
    return vEB->u;
  }

  // calculate the cluster this value would belong to
  unsigned int cluster_i =  value / ((unsigned int) sqrt(vEB->u));

  // calculate the position of this value within its cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

  // check if that cluster even exists
  bool exists = true;
  if ((vEB->clusters)[cluster_i].is_empty){
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

  // handle min case
  if (value <= vEB->min_value){
    return vEB->min_value;
  }

  // handle max case
  if (value > vEB->max_value){
    return vEB->max_value;
  }

  // calculate the cluster this value would belong to
  unsigned int cluster_i =  value / ((unsigned int) sqrt(vEB->u));

  // calculate the position of this value within its cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

  // check if that cluster even exists
  bool exists = true;
  if ((vEB->clusters)[cluster_i].is_empty){
    exists = false;
  }

  // predecessor is within the cluster this value would belong to
  if (exists && position > ((vEB->clusters)[cluster_i]).min_value){
    unsigned int base = ((vEB->clusters)[cluster_i]).u * cluster_i;
    return base + predecessor_helper(&((vEB->clusters)[cluster_i]), position);
  }

  // cluster doesn't exist, get the previous non empty cluster
  unsigned int previous_cluster = predecessor_helper(vEB->summary, cluster_i);

  // there is no previous non empty cluster, predecessor is min of this vEB tree
  if (previous_cluster == cluster_i){
    return vEB->min_value;
  }

  // otherwise, predecessor is max value of previous non empty cluster 
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
  if ((vEB->clusters)[cluster_i].is_empty){
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

bool VEB::remove_helper(VEB* vEB, unsigned int value, unsigned int count){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // handle empty vEB tree
  if (vEB->is_empty){
    return false;
  }

  // removing the last element
  if ((value == vEB->min_value) && (vEB->min_value == vEB->max_value)){
    vEB->is_empty = true;
    return true;
  }

  // vEB holds two values, removing min so replace min with max
  if (value == vEB->min_value && vEB->summary->is_empty){
      vEB->min_value = vEB->max_value;
      return true;
  }

  // replace min with next smallest value, remove next smallest value
  if (value == vEB->min_value){
    value = (vEB->clusters)[vEB->summary->min_value].min_value;
    vEB->min_value = value;
  }

  // vEB holds two values, removing max so replace max with min
  if (value == vEB->max_value && vEB->summary->is_empty){
    vEB->max_value = vEB->min_value;
    return true;
  }

  // replace max with next largest value
  if (value == vEB->max_value){
    vEB->max_value = (vEB->clusters)[vEB->summary->max_value].max_value;
  }

  // if value is not min or max and summary is empty, value is not in vEB
  if (summary->is_empty){
    return false;
  }

  // calculate cluster this value belongs to
  unsigned int cluster_i =  value / ((unsigned int) sqrt(vEB->u));

  // calculate position within cluster
  unsigned int position = value % ((unsigned int) sqrt(vEB->u));

  // remove value from this cluster
  remove_helper(&((vEB->clusters)[cluster_i]), position, count);

  // if cluster is now empty, update summary structure
  if ((vEB->clusters)[cluster_i].is_empty){
    remove_helper(vEB->summary, cluster_i, 1);
  }

  return true;
}

void VEB::elements_helper(VEB* vEB, unsigned int base, vector<unsigned int>* result){
  // make sure the summary structure is initialized
  if (vEB->summary == NULL){
    vEB->summary = new VEB(sqrt(vEB->u));
  }

  // vEB is guaranteed to not be empty
  for (unsigned int i=0; i<vEB->min_count; i++){
    result->push_back(base + vEB->min_value);
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




