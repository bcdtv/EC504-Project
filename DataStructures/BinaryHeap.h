#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>

using namespace std;

// Because a binary heap is a complete binary tree, it 
// can be represented using an array. In this case, we
// use the vector container in order to allow for dynamic size.

class BinaryHeap{
  // public methods
  public:
    BinaryHeap();
    BinaryHeap(vector<int> numbers);
    void insert(int value);
    void remove(int value);
    int extract_min();  
    bool empty();
    int size();
    void display();
    bool valid();

  // private fields
  private:
    vector<int> nodes;

  // private methods
  private:
    void heapify_down(int current_i);
    void heapify_up(int current_i);
    int get_index(int value); 
    bool valid_subheap(int current_i);
};

#endif
