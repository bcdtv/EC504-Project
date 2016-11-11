#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
 
// Because a binary heap is a complete binary tree, it 
// can be represented using an array. In this case, we
// use the std::vector container in order to allow for
 // dynamic size.
 // dynamic size.
class BinaryHeap{
  // public methods
  public:
    BinaryHeap();
    ~BinaryHeap();
    BinaryHeap(std::vector<int> numbers);
    void insert(int value); // Vera
    void remove(int value); // Dor
    int getIndex(int value); 
    int extract();  
    bool isEmpty();
    // int successor(int value); // Dor
    // int predecessor(int value); // Dor
    void display(); // Dor
    std::vector<int> getNodes();
    int min;

  // private fields
  private:
    std::vector<int> nodes;
    int size;

  // private methods
  private:
    void minHeapify(int current_i);
};

#endif
