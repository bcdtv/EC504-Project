#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "../DataStructures/BinaryHeap.h"

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
  
  // initialize input array
  std::vector<int> numbers(N);
  std::srand(std::time(NULL));
  for (int i=0; i<N; i++){
    numbers[i] = MIN_INT + (std::rand() % (MAX_INT-MIN_INT+1));
  }

  // print input array
  std::cout << "Input Array: " << std::endl;
  for (int i=0; i<N; i++){
    std::cout << numbers[i] << std::endl;
  }

  // build the binary heap
  BinaryHeap heap = BinaryHeap(numbers);

  // print the binary heap
  std::cout << "Binary Heap Nodes: " << std::endl;
  std::vector<int> heap_nodes = heap.getNodes();
  for (int i=0; i<N; i++){
    std::cout << heap_nodes[i] << std::endl;
  }

  print_footer();
  return 0;
}

void print_header(){
  std::cout << "=============== BINARY HEAP TESTS ===============" << std::endl;
}

void print_footer(){
  std::cout << "=================================================" << std::endl;
  std::cout << std::endl;
}



