#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/VEB.h"

using namespace std;

VEB test_constructor(bool display);
void test_insert(VEB* vEB, vector<unsigned int> numbers, bool display);
void test_successor(VEB vEB, vector<unsigned int> numbers, bool display);
void test_predecessor(VEB vEB, vector<unsigned int> numbers, bool display);
void test_remove(VEB* vEB, vector<unsigned int> numbers, bool display);

int main(){
  print_header("VEB TREE TESTS");

  // request display boolean
  bool display;
  /*cout << "display? (0/1): ";
  cin >> display;*/
  display = true;

  // generate a sample vector of numbers for testing

  // removes correctly
  // end
  // removes correctly BUT inserts a number
  // static const int arr[] = {5,18,29,38,44,49,55,70,85};
  // static const int arr[] = {32,35,44,49,73,74,76,84,91};
  static const int arr[] = {2,31,90,64,64,72,79,54,86};
  // static const int arr[] = {7,7,9,22,32,45,66,80,85};
  // end
  // infinite loop
  // static const int arr[] = {68, 47, 29, 60, 26, 51, 22, 47, 89};
  // end
  vector<unsigned int> numbers (arr, arr + sizeof(arr) / sizeof(arr[0]) );

  /*vector<unsigned int> numbers = generate_numbers(display);
  if (numbers.empty()){
    print_footer();
    return 0;
  }*/

  // test the vEB tree methods
  VEB vEB = test_constructor(display);
  test_insert(&vEB, numbers, display);
  test_remove(&vEB, numbers, display);
  cout << "done" << endl;
  test_successor(vEB, numbers, display);
  test_predecessor(vEB, numbers, display);
  print_footer();
  return 0;
}

VEB test_constructor(bool display){
  cout << endl << "BUILD EMPTY VEB TREE" << endl;

  // initialize an empty vEB tree
  VEB vEB = VEB();

  // display the vEB tree
  if (display){
    vEB.display();
  }

  return vEB;
}

void test_insert(VEB* vEB, vector<unsigned int> numbers, bool display){
  cout << endl << "INSERT" << endl;

  // display the initial heap
  if (display){
    vEB->display();
  }

  // insert and display
  for (unsigned int i=0; i<numbers.size(); i++){
    vEB->insert(numbers[i]);
    if (display){
      vEB->display();
    }
  }
}

void test_successor(VEB vEB, vector<unsigned int> numbers, bool display){
  cout << endl << "SUCCESSOR" << endl;

  // display vEB tree
  if (display){
    vEB.display();
  }

  // retrieve and display successor of each number
  unsigned int successor;
  for (unsigned int i=0; i<numbers.size(); i++){
    successor = vEB.successor(numbers[i]);
    if (display){
      cout << "Successor of " << numbers[i] << ": ";
      cout << successor << endl; 
    }
  }
}

void test_predecessor(VEB vEB, vector<unsigned int> numbers, bool display){
  cout << endl << "PREDECESSOR" << endl;

  // display vEB tree
  if (display){
    vEB.display();
  }

  // retrieve and display predecessor of each number
  unsigned int predecessor;
  for (unsigned int i=0; i<numbers.size(); i++){
    predecessor = vEB.predecessor(numbers[i]);
    if (display){
      cout << "Predecessor of " << numbers[i] << ": ";
      cout << predecessor << endl;
    }
  }
}

void test_remove(VEB* vEB, vector<unsigned int> numbers, bool display){
  cout << endl << "REMOVE" << endl;

  // display vEB tree
  if (display){
    vEB->display();
  }

  // remove single element and display
  cout << "Removing: " << numbers[1] << endl;
  vEB->remove(numbers[1]);
  cout << "Removing: " << numbers[5] << endl;
  vEB->remove(numbers[5]);
  // vEB->remove(numbers[9]);
  // display vEB tree
  if (display){
    vEB->display();
  }  
  
  // remove all 
  /*for (unsigned int i=0; i<numbers.size(); i++){
    cout << "Removing: " << numbers[i] << endl;
    vEB->remove(numbers[i]);
    if (display){
      vEB->display();
    }
  }*/
}

