#include <iostream>
#include "BST.h"

using namespace std;

// ============ Public Method Implementations ============
// Constructor for creating an empty BST
BST::BST(){
  value = 0;
  left = NULL;
  right = NULL;
};

// Constructor for creating a BST with one value
BST::BST(int value){
  this->value = value;
  left = NULL;
  right = NULL;
};

int BST::successor(int value){
  return successor_helper(this, value);
}

int BST::predecessor(int value){
  return predecessor_helper(this, value);
}

void BST::insert(int value){
  insert_helper(this, value);
}

void BST::remove(int value){
  remove_helper(this, value);
}

int BST::min(){
  return min_helper(this);
}
// =======================================================

// ============ Private Method Implementations ===========
int BST::successor_helper(BST* root , int data){   
  return -1;
}

int BST::predecessor_helper(BST* root , int data){   
  return -1;
}

void BST::insert_helper(BST* root, int data){   
  // left BST is empty, create a new BST and insert into left
  if ((data <= root->value) && (root->left == NULL)){
    root->left = new BST(data);
    return;
  }
  
  // insert recursively into left BST
  if ((data <= root->value) && (root->left !=NULL)){
    insert_helper(root->left, data);
    return;
  }

  // right BST is empty, create a new BST and insert into right
  if (root->right == NULL){
    root->right = new BST(data);
    return;
  }

  // insert recursively into right BST
  insert_helper(root->right, data);
}

void BST::remove_helper(BST* root , int data){  
 
}

int BST::min_helper(BST* root){ 
  if (root->left == NULL){
    return root->value;
  }

  return min_helper(root->left);
}

