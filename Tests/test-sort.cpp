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
  cout << endl;

  // declare benchmarking variables
  vector<unsigned int> sorted_numbers;
  unsigned int start_time; 
  unsigned int stop_time;
  double elapsed_time;

  // benchmark building the binary heap
  start_time = clock();
  BinaryHeap heap = BinaryHeap(numbers);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Time to build the binary heap: " << elapsed_time << "ms" << endl;

  // benchmark building the vEB tree
  start_time = clock();
  VEB vEB = VEB();
  for (unsigned int i=0; i<numbers.size(); i++){
    vEB.insert(numbers[i]);
  }
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Time to build the vEB tree: " << elapsed_time << "ms" << endl;

  cout << endl;

  // benchmark sorting with the binary heap
  start_time = clock();
  sorted_numbers = sort(&heap);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the binary heap: " << elapsed_time << "ms" << endl;

  // display the sorted numbers
  if (display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl;
  }

  // benchmark sorting with the vEB tree
  start_time = clock();
  sorted_numbers = sort(&vEB);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the vEB tree: " << elapsed_time << "ms" << endl;

  // display the sorted numbers
  if (display){
    cout << "Sorted numbers: ";
    for (unsigned int i=0; i<sorted_numbers.size(); i++){
      cout << sorted_numbers[i] << " ";
    }
    cout << endl;
  }

  print_footer();
  return 0;
}

