#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/VEB.h"

using namespace std;

VEB test_constructor();
void test_insert(VEB* vEB, vector<int> numbers);
void test_successor(VEB vEB, vector<int> numbers);
void test_predecessor(VEB vEB, vector<int> numbers);

int main(){
  print_header("VEB TREE TESTS");

  // generate a sample vector of numbers for testing
  vector<int> numbers = generate_numbers();
  if (numbers.empty()){
    print_footer();
    return 0;
  }

  // test the vEB tree methods
  VEB vEB = test_constructor();
  test_insert(&vEB, numbers);
  test_successor(vEB, numbers);
  //test_predecessor(vEB, numbers);

  print_footer();
  return 0;
}

VEB test_constructor(){
  cout << endl << "BUILD EMPTY VEB TREE" << endl;

  // initialize an empty vEB tree
  VEB vEB = VEB();

  // display the vEB tree
  vEB.display();

  return vEB;
}

void test_insert(VEB* vEB, vector<int> numbers){
  cout << endl << "INSERT" << endl;

  // display the initial heap
  vEB->display();

  // insert and display
  for (int i=0; i<numbers.size(); i++){
    vEB->insert(numbers[i]);
    vEB->display();
  }
}

void test_successor(VEB vEB, vector<int> numbers){
  cout << endl << "SUCCESSOR" << endl;

  // display vEB tree
  vEB.display();

  // print successor of each number
  for (int i=0; i<numbers.size(); i++){
    cout << "Successor of " << numbers[i] << ": ";
    cout << vEB.successor(numbers[i]) << endl;
  }
}

void test_predecessor(VEB vEB, vector<int> numbers){
  cout << endl << "PREDECESSOR" << endl;

  // display vEB tree
  vEB.display();

  // print predecessor of each number
  for (int i=0; i<numbers.size(); i++){
    cout << "Predecessor of " << numbers[i] << ": ";
    cout << vEB.predecessor(numbers[i]) << endl;
  }
}





