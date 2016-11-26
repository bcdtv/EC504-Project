#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/VEB.h"

using namespace std;

VEB test_empty_constructor();
void test_insert(vector<int> numbers);

int main(){
  print_header("VEB TREE TESTS");

  // generate a sample vector of numbers for testing
  vector<int> numbers = generate_numbers();
  if (numbers.empty()){
    print_footer();
    return 0;
  }

  // test the vEB tree methods
  VEB vEB = test_empty_constructor();
  test_insert(numbers);

  print_footer();
  return 0;
}

VEB test_empty_constructor(){
  cout << endl << "BUILD EMPTY VEB TREE" << endl;

  // initialize an empty vEB tree
  VEB vEB = VEB();

  // display the vEB tree
  vEB.display();

  return vEB;
}

void test_insert(vector<int> numbers){
  cout << endl << "INSERT" << endl;

  // declare empty vEB tree
  VEB vEB;

  // display the initial heap
  vEB.display();

  // insert and display
  for (int i=0; i<numbers.size(); i++){
    vEB.insert(numbers[i]);
    vEB.display();
  }
}





