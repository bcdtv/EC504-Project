#include <cstdlib>
#include <ctime>
#include <iostream>
//#include "../DataStructures/Heap.h"
//#include "../DataStructures/VEB.h"

void print_header();
void print_footer();

int main(){
  print_header();

  // request inputs
  int N;
  std::cin >> N;
  int MIN_INT;
  std::cin >> MIN_INT;
  int MAX_INT;
  std::cin >> MAX_INT;

  // print inputs
  std::cout << "N: " << N << std::endl;
  std::cout << "MIN_INT: " << MIN_INT << std::endl;
  std::cout << "MAX_INT: " << MAX_INT << std::endl;

  // validate inputs
  if (MIN_INT >= MAX_INT){
    std::cout << "Error: MIN_INT is not less than MAX_INT" << std::endl;
    print_footer();
    return 0;
  }
  
  // initialize input integer array
  int numbers[N];
  std::srand(std::time(NULL));
  for (int i=0; i<N; i++){
    numbers[i] = MIN_INT + (std::rand() % (MAX_INT-MIN_INT+1));
  }

  // benchmark sorting with the binary heap
  int start_time = std::clock();
  /*Heap heap = Heap(numbers);
  int sorted_numbers = sort(heap);*/
  int stop_time = std::clock();
  double elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  std::cout << "Sorting time with the Binary Heap: " << elapsed_time << "ms" << std::endl;

  // benchmark sorting with the vEB tree
  start_time = std::clock();
  /*VEB vEB = VEB(numbers);
  int sorted_numbers = sort(vEB);*/
  stop_time = std::clock();
  elapsed_time = (stop_time - start_time) / (double)(CLOCKS_PER_SEC/1000);
  std::cout << "Sorting time with the vEB Tree: " << elapsed_time << "ms" << std::endl;

  print_footer();
  return 0;
}

void print_header(){
  std::cout << "=============== SORTING BENCHMARK ===============" << std::endl;
}

void print_footer(){
  std::cout << "=================================================" << std::endl;
  std::cout << std::endl;
}

