#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
//#include "../DataStructures/binMinHeap.h"


int main(){
  // request N value
  int N;
  std::cout << "Enter value for N: ";
  std::cin >> N;

  // request MIN_INT value
  int MIN_INT;
  std::cout << "Enter value for MIN_INT: ";
  std::cin >> MIN_INT;

  // request MAX_INT value
  int MAX_INT;
  std::cout << "Enter value for MAX_INT: ";
  std::cin >> MAX_INT;
  
  // initialize input vector
  std::vector<int> numbers(N, 0);

  // fill vector with random integers
  std::srand(std::time(NULL));
  for (int i=0; i<N; i++){
    numbers[i] = MIN_INT + (std::rand() % (MAX_INT-MIN_INT+1));
  }
}

