#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>
#include <vector>
#include "utils.h"
#include "../Algorithms/sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/BST.h"
#include "../DataStructures/Deque.h"
#include "../DataStructures/VEB.h"

using namespace std;

int main(){
  const char* PR_STR = "us";

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

  using namespace std::chrono;
  high_resolution_clock::time_point t_start;
  high_resolution_clock::time_point t_stop;

  double elapsed_time;
  BinaryHeap heap;
  BST bst;
  Deque deque;
  VEB vEB;

  // benchmark building the vEB tree
  if (test_vEB){
    t_start = high_resolution_clock::now();
    vEB = VEB();
    for (unsigned int i=0; i<numbers.size(); i++){
      vEB.insert(numbers[i]);
    }
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Time to build the vEB tree: " << elapsed_time << PR_STR << endl;
  }

  // benchmark building the binary heap
  if (test_heap){
    t_start = high_resolution_clock::now();
    heap = BinaryHeap(numbers);
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Time to build the binary heap: " << elapsed_time << PR_STR << endl;
  }

  // benchmark building the BST
  if (test_bst){
    t_start = high_resolution_clock::now();
    bst = BST(numbers[0]);
    for (unsigned int i=1; i<numbers.size(); i++){
      bst.insert(numbers[i]);
    }
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Time to build the binary search tree: " << elapsed_time << PR_STR << endl;
  }

  // benchmark building the deque
  if (test_deque){
    t_start = high_resolution_clock::now();
    deque = Deque(numbers);
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Time to build the deque: " << elapsed_time << PR_STR << endl;
  }

  cout << endl;

  // benchmark sorting with the vEB
  if (test_vEB){
    t_start = high_resolution_clock::now();
    sorted_numbers = sort(vEB);
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Sorting time with the vEB tree: " << elapsed_time << PR_STR << endl;
  }
  
  // display the sorted numbers
  if (test_vEB && display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl << endl;
  }

  // benchmark sorting with the binary heap
  if (test_heap){
    t_start = high_resolution_clock::now();
    sorted_numbers = sort(heap);
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Sorting time with the binary heap: " << elapsed_time << PR_STR << endl;
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
    t_start = high_resolution_clock::now();
    sorted_numbers = sort(bst);
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(t_stop - t_start).count();
    cout << "Sorting time with the binary search tree: " << elapsed_time << PR_STR << endl;
  }

  // display the sorted numbers
  if (test_bst && display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl << endl;
  }

  // benchmark sorting with the deque ****THIS IS IN BIGGER UNITS BECAUSE IT'S SLOW*****
  if (test_deque){
    t_start = high_resolution_clock::now();
    sorted_numbers = sort(deque);
    t_stop = high_resolution_clock::now();
    elapsed_time = duration_cast<milliseconds>(t_stop - t_start).count();
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

  print_footer();
  return 0;
}

