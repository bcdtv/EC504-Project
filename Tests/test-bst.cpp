#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/BST.h"

using namespace std;

void validate(BST* bst, bool display);
BST test_constructor(int value, bool display);
void test_insert(vector<unsigned int> numbers, BST* bst, bool display);
void test_remove(vector<unsigned int> numbers, BST bst, bool display);
void test_successor(vector<unsigned int> numbers, BST* bst, bool display);
void test_predecessor(vector<unsigned int> numbers, BST* bst, bool display);
void test_min_max(BST* bst, bool display);

int main(){
  print_header("BINARY SEARCH TREE TESTS");

  // request display boolean
  bool display;
  cout << "display? (0/1): ";
  cin >> display;

  // generate a sample vector of numbers for testing
  vector<unsigned int> numbers = generate_numbers(display);
  if (numbers.empty()){
    print_footer();
    return 0;
  }

  // create a copy excluding the first element
  vector<unsigned int> copy(numbers.begin()+1, numbers.end());

  // test the BST methods
  BST bst = test_constructor(numbers[0], display);
  test_insert(copy, &bst, display);
  test_remove(numbers, bst, display);
  test_successor(numbers, &bst, display);
  test_predecessor(numbers, &bst, display);
  test_min_max(&bst, display);

  print_footer();
  return 0;
}

void validate(BST* bst, bool display){
  bool valid = bst->valid();
  if (display){
    if (valid){
      cout << "VALID ";
    }
    else{
      cout << "INVALID ";
    }
  }
}

BST test_constructor(int value, bool display){
  cout << endl << "BUILD BST USING SINGLE VALUE" << endl;

  // build a BST with the passed value
  BST bst = BST(value);

  // display the BST
  if (display){
    bst.display();
  }

  return bst;
}

void test_insert(vector<unsigned int> numbers, BST* bst, bool display){
  cout << endl << "INSERT" << endl;

  // validate and display the initial tree
  validate(bst, display); 
  if (display){
    bst->display();
  }

  // insert, validate, and display
  for (unsigned int i=0; i<numbers.size(); i++){
    bst->insert(numbers[i]);
    validate(bst, display); 
    if (display){
      bst->display();
    }
  }
}

void test_remove(vector<unsigned int> numbers, BST bst, bool display){
  cout << endl << "REMOVE" << endl;

  // validate and display the initial tree
  validate(&bst, display); 
  if (display){
    bst.display();
  }

  // remove, validate, and display
  for (unsigned int i=0; i<numbers.size(); i++){
    bst.remove(numbers[i]);
    validate(&bst, display); 
    if (display){
      bst.display();
    }
  }
}

void test_successor(vector<unsigned int> numbers, BST* bst, bool display){
  cout << endl << "SUCCESSOR" << endl;

  // display the given BST
  if (display){
    bst->display();
  }

  // retrieve and display successor of each number
  unsigned int successor;
  for (unsigned int i=0; i<numbers.size(); i++){
    successor = bst->successor(numbers[i]);
    if (display){
      cout << "Successor of " << numbers[i] << ": ";
      cout << successor << endl; 
    }
  }
}

void test_predecessor(vector<unsigned int> numbers, BST* bst, bool display){
  cout << endl << "PREDECESSOR" << endl;

  // display the given BST
  if (display){
    bst->display();
  }

  // retrieve and display predecessor of each number
  unsigned int predecessor;
  for (unsigned int i=0; i<numbers.size(); i++){
    predecessor = bst->predecessor(numbers[i]);
    if (display){
      cout << "Predecessor of " << numbers[i] << ": ";
      cout << predecessor << endl;
    }
  }
}

void test_min_max(BST* bst, bool display){
  cout << endl << "MIN & MAX" << endl;

  // display the initial tree
  if (display){
    bst->display();
  }

  // display the min and max
  if (display){
    cout << "Mininum value: " << bst->min() << endl;
    cout << "Maximum value: " << bst->max() << endl;
  }
}


