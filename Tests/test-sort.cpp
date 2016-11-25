#include <ctime>
#include <iostream>
#include <vector>
#include "utils.h"
#include "../Algorithms/sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/VEB.h"

using namespace std;

int main(){
  print_header("SORTING BENCHMARK");

  // generate a sample vector of numbers for testing
  vector<int> numbers = generate_numbers();
  if (numbers.empty()){
    print_footer();
    return 0;
  }

  // declare variables
  vector<int> sorted_numbers;
  int start_time; 
  int stop_time;
  double elapsed_time;

  // benchmark sorting with the binary heap
  start_time = clock();
  BinaryHeap * heap = new BinaryHeap(numbers);
  sorted_numbers = sort(heap);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the Binary Heap: " << elapsed_time << "ms" << endl;

  // benchmark sorting with the vEB tree method 1
  start_time = clock();
  VEB vEB_1 = VEB(numbers);
  sorted_numbers = sort(&vEB_1, 1);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the vEB Tree, method 1: " << elapsed_time << "ms" << endl;

  // benchmark sorting with the vEB tree method 2
  start_time = clock();
  VEB vEB_2 = VEB(numbers);
  sorted_numbers = sort(&vEB_2, 2);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the vEB Tree, method 2: " << elapsed_time << "ms" << endl;

  print_footer();
  return 0;
}

