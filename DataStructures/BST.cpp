#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

// ============ Public Method Implementations ============
// Constructor for creating a BST with default value 0.
BST::BST(){
  value = 0;
  count = 1;
  left = NULL;
  right = NULL;
};

// Constructor for creating a BST with a specified value.
BST::BST(int value){
  this->value = value;
  count = 1;
  left = NULL;
  right = NULL;
};

// Retrieve the next value greater than the passed value.
int BST::successor(int value){
  // handle max case
  if (value >= this->max()){
    return value;
  }

  // initialize vector to store path to this value
  vector<int> path;

  // find the node that holds this value
  BST* current = this;
  while (current->value != value){
    if ((value < current->value) && (current->left != NULL)){
      path.push_back(current->value);
      current = current->left;
      continue;
    }
    if ((value > current->value) && (current->right != NULL)){
      path.push_back(current->value);
      current = current->right;
      continue;
    } 
    break;
  }

  // return early if value is not found
  if (current->value != value){
    return value;
  }

  // if this value has no right tree, look upwards
  if (current->right == NULL){
    for (int i=path.size()-1; i>=0; i--){
      if (path[i] > value){
        return path[i];
      }
    }
  }

  // go to right tree
  current = current->right;

  // go to left most element within right tree
  while (current->left != NULL){
    current = current->left;
  }

  // return that value
  return current->value;
}

// Retrieve the previous value less than the passed value.
int BST::predecessor(int value){
  // handle min case
  if (value <= this->min()){
    return value;
  }

  // initialize vector to store path to this value
  vector<int> path;

  // find the node that holds this value
  BST* current = this;
  while (current->value != value){
    if ((value < current->value) && (current->left != NULL)){
      path.push_back(current->value);
      current = current->left;
      continue;
    }
    if ((value > current->value) && (current->right != NULL)){
      path.push_back(current->value);
      current = current->right;
      continue;
    } 
    break;
  }

  // return early if value is not found
  if (current->value != value){
    return value;
  }

  // if this value has no left tree, look upwards
  if (current->left == NULL){
    for (int i=path.size()-1; i>=0; i--){
      if (path[i] < value){
        return path[i];
      }
    }
  }

  // go to left tree
  current = current->left;

  // go to right most element within left tree
  while (current->right != NULL){
    current = current->right;
  }

  // return that value
  return current->value;
}

// Insert a value into the BST. This is done using
// recursion because the BST is a recursive data
// structure.
void BST::insert(int value){
  insert_helper(this, value);
}


// Remove a value into the BST. This is done using
// recursion because the BST is a recursive data
// structure.
void BST::remove(int value){
  remove_helper(this, value);
}


// Retrieve the minimum value in the BST. This is
// done using recursion because the BST is a 
// recursive data structure.
int BST::min(){
  return min_helper(this);
}

// Retrieve the maximum value in the BST. This is
// done using recursion because the BST is a
// recursive data structure.
int BST::max(){
  return max_helper(this);
}

// Display the contents of the BST. This is done 
// in pre-order using recursion.
void BST::display(){
  cout << "BST: ";
  display_helper(this);
  cout << endl;
}

// Return whether the BST is indeed valid or not.
// This is useful for testing correctness.
bool BST::valid(){
  return valid_helper(this);
}
// =======================================================

// ============ Private Method Implementations ===========
void BST::insert_helper(BST* root, int value){   
  // value is equal to root value, increment count
  if (value == root->value){
    root->count++;
    return;
  }

  // left BST is empty, create a new BST and insert into left
  if ((value < root->value) && (root->left == NULL)){
    root->left = new BST(value);
    return;
  }
  
  // insert recursively into left BST
  if ((value < root->value) && (root->left != NULL)){
    insert_helper(root->left, value);
    return;
  }

  // right BST is empty, create a new BST and insert into right
  if (root->right == NULL){
    root->right = new BST(value);
    return;
  }

  // insert recursively into right BST
  insert_helper(root->right, value);
}

void BST::remove_helper(BST* root , int value){
 
}

int BST::min_helper(BST* root){ 
  // method has hit the left most leaf
  if (root->left == NULL){
    return root->value;
  }

  // otherwise, keep traversing to the left
  return min_helper(root->left);
}

int BST::max_helper(BST* root){
  // method has hit the right most leaf
  if (root->right == NULL){
    return root->value;
  }

  // otherwise, keep traversing to the right
  return max_helper(root->right);
}

void BST::display_helper(BST* root){
  // print out the root value
  for (int i=0; i<root->count; i++){
    cout << root->value << " ";
  }

  // print out the left tree
  if (root->left != NULL){
    display_helper(root->left);
  }

  // print out the right tree
  if (root->right != NULL){
    display_helper(root->right);
  }
}

bool BST::valid_helper(BST* root){
  // ensure the left node is valid
  if ((root->left != NULL) && (root->left->value > root->value)){
    return false;
  }

  // ensure the right node is valid
  if ((root->right != NULL) && root->right->value <= root->value){
    return false;
  }

  // declare result variables
  bool result_left = true;
  bool result_right = true;

  // validate the left tree
  if(root->left != NULL){
    result_left = valid_helper(root->left);
  }

  // validate the right tree
  if (root->right != NULL){
    result_right = valid_helper(root->right);
  }

  // return the results
  return result_left && result_right;
}
// =======================================================



