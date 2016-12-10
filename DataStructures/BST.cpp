#include <iostream>
#include "BST.h"

using namespace std;

// ============ Public Method Implementations ============
// Constructor for creating a BST with default value 0.
BST::BST(){
  value = 0;
  left = NULL;
  right = NULL;
};

// Constructor for creating a BST with a specified value.
BST::BST(int value){
  this->value = value;
  left = NULL;
  right = NULL;
};

// Retrieve the next value greater than the passed
// value. This is done using recursion because the
// BST is a recursive data structure.
int BST::successor(int value){
  return successor_helper(this, value);
}

// Retrieve the previous value less than the passed
// value. This is done using recursion because the 
// BST is a recursive data structure.
int BST::predecessor(int value){
  return predecessor_helper(this, value);
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
int BST::successor_helper(BST* root , int value){   
  return -1;
}

int BST::predecessor_helper(BST* root , int value){   
  return -1;
}

void BST::insert_helper(BST* root, int value){   
  // left BST is empty, create a new BST and insert into left
  if ((value <= root->value) && (root->left == NULL)){
    root->left = new BST(value);
    return;
  }
  
  // insert recursively into left BST
  if ((value <= root->value) && (root->left != NULL)){
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
  cout << root->value << " ";

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



