#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/BinaryHeap.h"

using namespace std;

void validate(BinaryHeap heap);
BinaryHeap test_constructor(vector<int> numbers);
void test_insert(vector<int> numbers);
void test_remove(BinaryHeap heap, vector<int> numbers);
void test_extract_min(BinaryHeap heap);

int main(){
  print_header("BINARY HEAP TESTS");

  // generate a sample vector of numbers for testing
  vector<int> numbers = generate_numbers();
  if (numbers.empty()){
    print_footer();
    return 0;
  }

  // test the binary heap methods
  BinaryHeap heap = test_constructor(numbers);
  test_insert(numbers);
  test_remove(heap, numbers);
  test_extract_min(heap);

  print_footer();
  return 0;
}

void validate(BinaryHeap heap){
  bool valid = heap.valid();
  if (valid){
    cout << "VALID ";
  }
  else{
    cout << "INVALID ";
  }
}

BinaryHeap test_constructor(vector<int> numbers){
  cout << endl << "BUILD HEAP USING VECTOR" << endl;

  // build a binary heap directly with the passed numbers
  BinaryHeap heap = BinaryHeap(numbers);

  // check validity and display the heap
  validate(heap);
  heap.display();

  return heap;
}

void test_insert(vector<int> numbers){
  cout << endl << "INSERT" << endl;

  // declare empty heap
  BinaryHeap heap;

  // check validity and display the initial heap
  validate(heap); 
  heap.display();

  // insert, check validity, and display
  for (int i=0; i<numbers.size(); i++){
    heap.insert(numbers[i]);
    validate(heap);
    heap.display();
  }
}

void test_remove(BinaryHeap heap, vector<int> numbers){
  cout << endl << "REMOVE" << endl;

  // check validity and display the initial heap
  validate(heap);
  heap.display();

  // remove, check validity, and display
  for (int i=0; i<numbers.size(); i++){
    cout << "Removing " << numbers[i] << ":" << endl;
    heap.remove(numbers[i]);
    validate(heap);
    heap.display();
  }
}

void test_extract_min(BinaryHeap heap){
  cout << endl << "EXTRACT MIN" << endl; 

  // check validity and display the initial heap
  heap.display();

  // extract, check validity, and display
  while(!heap.empty()){
    heap.extract_min();
    validate(heap);
    heap.display();
  }
}



