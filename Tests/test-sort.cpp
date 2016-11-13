#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "../Algorithms/sort.h"
#include "../DataStructures/BinaryHeap.h"
//#include "../DataStructures/VEB.h"
using namespace std;

void print_header();
void print_footer();

int main(){
  print_header();

  // request inputs
  int N;
  int MIN_INT;
  int MAX_INT;
  

  cout << "N: ";
  cin >> N;
  cout << "MIN_INT: ";
  cin >> MIN_INT;
  cout << "MAX_INT: ";
  cin >> MAX_INT;

  // validate inputs
  if (MIN_INT >= MAX_INT){
    cout << "Error: MIN_INT is not less than MAX_INT" << endl;
    print_footer();
    return 0;
  }
  
  // initialize input array
  vector<int> numbers(N);
  srand(time(NULL));
  cout << "Test data contains: ";
  for (int i=0; i<N; i++){
    numbers[i] = MIN_INT + (rand() % (MAX_INT-MIN_INT+1));
    cout << numbers[i] << " ";
  }
  cout << endl;
  // benchmark sorting with the binary heap
  int start_time = clock();
  BinaryHeap * heap = new BinaryHeap(numbers);
  vector<int> sorted_numbers = sort(heap);
  int stop_time = clock();
  double elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the Binary Heap: " << elapsed_time << "ms" << endl;

  // benchmark sorting with the vEB tree
  start_time = clock();
  //VEB vEB = VEB(numbers);
  //int sorted_numbers = sort(&vEB);
  stop_time = clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  cout << "Sorting time with the vEB Tree: " << elapsed_time << "ms" << endl;
  delete heap;
  print_footer();
  return 0;
}

void print_header(){
  cout << "=============== SORTING BENCHMARK ===============" << endl;
}

void print_footer(){
  cout << "=================================================" << endl;
  cout << endl;
}

