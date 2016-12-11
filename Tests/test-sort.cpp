#include <ctime>
#include <iostream>
#include <vector>
#include "utils.h"
#include "../Algorithms/sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/BST.h"
#include "../DataStructures/Deque.h"
#include "../DataStructures/VEB.h"

using namespace std;

int main(){
  print_header("SORTING BENCHMARK");

  // request display boolean
  bool display;
  cout << "display? (0/1): ";
  cin >> display;

  // user determines which data structures to test
  bool test_heap;
  cout << "Test the binary heap? (0/1): ";
  cin >> test_heap;
  bool test_bst;
  cout << "Test the binary search tree? (0/1): ";
  cin >> test_bst;
  bool test_deque;
  cout << "Test the deque? (0/1): ";
  cin >> test_deque;
  bool test_vEB;
  cout << "Test the vEB tree? (0/1): ";
  cin >> test_vEB;

  // generate a sample vector of numbers for testing
  vector<unsigned int> numbers = generate_numbers(display);
  if (numbers.empty()){
    print_footer();
    return 0;
  }
  cout << endl;

  // declare benchmarking variables
  vector<unsigned int> sorted_numbers;
  unsigned int start_time; 
  unsigned int stop_time;
  double elapsed_time;
  BinaryHeap heap;
  BST bst;
  Deque deque;
  VEB vEB;

  // benchmark building the binary heap
  if (test_heap){
    start_time = clock();
    heap = BinaryHeap(numbers);
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Time to build the binary heap: " << elapsed_time << "ms" << endl;
  }

  // benchmark building the BST
  if (test_bst){
    start_time = clock();
    bst = BST();
    for (unsigned int i=0; i<numbers.size(); i++){
      bst.insert(numbers[i]);
    }
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Time to build the binary search tree: " << elapsed_time << "ms" << endl;
  }

  // benchmark building the deque
  if (test_deque){
    start_time = clock();
    deque = Deque(numbers);
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Time to build the deque: " << elapsed_time << "ms" << endl;
  }

  // benchmark building the vEB tree
  if (test_vEB){
    start_time = clock();
    vEB = VEB();
    for (unsigned int i=0; i<numbers.size(); i++){
      vEB.insert(numbers[i]);
    }
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Time to build the vEB tree: " << elapsed_time << "ms" << endl;
  }

  cout << endl;

  // benchmark sorting with the binary heap
  if (test_heap){
    start_time = clock();
    sorted_numbers = sort(&heap);
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Sorting time with the binary heap: " << elapsed_time << "ms" << endl;
  }

  // display the sorted numbers
  if (test_heap && display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl << endl;
  }

  // benchmark sorting with the binary search tree
  if (test_bst){
    start_time = clock();
    sorted_numbers = sort(&bst);
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Sorting time with the binary search tree: " << elapsed_time << "ms" << endl;
  }

  // display the sorted numbers
  if (test_bst && display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl << endl;
  }

  // benchmark sorting with the deque
  if (test_deque){
    start_time = clock();
    sorted_numbers = sort(&deque);
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Sorting time with the deque: " << elapsed_time << "ms" << endl;
  }

  // display the sorted numbers
  if (test_deque && display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl << endl;
  }

  // benchmark sorting with the vEB
  if (test_vEB){
    start_time = clock();
    sorted_numbers = sort(&vEB);
    stop_time = clock();
    elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
    cout << "Sorting time with the vEB tree: " << elapsed_time << "ms" << endl;
  }

  // display the sorted numbers
  if (test_vEB && display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl << endl;
  }

  print_footer();
  return 0;
}

