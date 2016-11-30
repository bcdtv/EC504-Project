#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/BinaryHeap.h"

using namespace std;

void validate(BinaryHeap heap, bool display);
BinaryHeap test_constructor(vector<unsigned int> numbers, bool display);
void test_insert(vector<unsigned int> numbers, bool display);
void test_remove(BinaryHeap heap, vector<unsigned int> numbers, bool display);
void test_extract_min(BinaryHeap heap, bool display);

int main(){
  print_header("BINARY HEAP TESTS");

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

  // test the binary heap methods
  BinaryHeap heap = test_constructor(numbers, display);
  test_insert(numbers, display);
  test_remove(heap, numbers, display);
  test_extract_min(heap, display);

  print_footer();
  return 0;
}

void validate(BinaryHeap heap, bool display){
  bool valid = heap.valid();
  if (display){
    if (valid){
      cout << "VALID ";
    }
    else{
      cout << "INVALID ";
    }
  }
}

BinaryHeap test_constructor(vector<unsigned int> numbers, bool display){
  cout << endl << "BUILD HEAP USING VECTOR" << endl;

  // build a binary heap directly with the passed numbers
  BinaryHeap heap = BinaryHeap(numbers);

  // check validity and display the heap
  validate(heap, display);
  if (display){
    heap.display();
  }

  return heap;
}

void test_insert(vector<unsigned int> numbers, bool display){
  cout << endl << "INSERT" << endl;

  // declare empty heap
  BinaryHeap heap;

  // check validity and display the initial heap
  validate(heap, display); 
  if (display){
    heap.display();
  }

  // insert, check validity, and display
  for (unsigned int i=0; i<numbers.size(); i++){
    heap.insert(numbers[i]);
    validate(heap, display);
    if (display){
      heap.display();
    }
  }
}

void test_remove(BinaryHeap heap, vector<unsigned int> numbers, bool display){
  cout << endl << "REMOVE" << endl;

  // check validity and display the initial heap
  validate(heap, display);
  if (display){
    heap.display();
  }

  // remove, check validity, and display
  for (unsigned int i=0; i<numbers.size(); i++){
    if (display){
      cout << "Removing " << numbers[i] << ":" << endl;
    }
    heap.remove(numbers[i]);
    validate(heap, display);
    if (display){
      heap.display();
    }
  }
}

void test_extract_min(BinaryHeap heap, bool display){
  cout << endl << "EXTRACT MIN" << endl; 

  // check validity and display the initial heap
  validate(heap, display);
  if (display){
    heap.display();
  }

  // extract, check validity, and display
  while(!heap.empty()){
    heap.extract_min();
    validate(heap, display);
    if (display){
      heap.display();
    }
  }
}



