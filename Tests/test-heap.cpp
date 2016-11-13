#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "../DataStructures/BinaryHeap.h"

using namespace std;

void print_header();
void print_footer();

int main(){
  print_header();

  // request inputs
  int N;
  int MIN_INT;
  int MAX_INT;

  // print inputs
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
  for (int i=0; i<N; i++){
    numbers[i] = MIN_INT + (rand() % (MAX_INT-MIN_INT+1));
  }

  // print input array
  cout << "Input Array: " << endl;
  for (int i=0; i<N; i++){
    cout << numbers[i] << endl;
  }

  // build the binary heap
  BinaryHeap heap = BinaryHeap(numbers);

  // print the binary heap
  cout << "Binary Heap Nodes: " << endl;
  vector<int> heap_nodes = heap.getNodes();
  for (int i=0; i<N; i++){
    cout << heap_nodes[i] << endl;
  }

  // extract and print until heap is empty
  cout << "Extract and print: " << endl;
  while(!heap.isEmpty()){
    cout << heap.extract() << endl;
  }

  print_footer();
  return 0;
}

void print_header(){
  cout << "=============== BINARY HEAP TESTS ===============" << endl;
}

void print_footer(){
  cout << "=================================================" << endl;
  cout << endl;
}



