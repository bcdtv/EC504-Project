#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
 
// Because a binary heap is a complete binary tree, it 
// can be represented using an array. In this case, we
// use the std::vector container in order to allow for
// dynamic size.

class BinaryHeap{
  // public methods
  public:
    BinaryHeap(std::vector<int> numbers);
    void insert(int value);
    void remove(int value);
    int extract();
    bool isEmpty();
    int successor(int value);
    int predecessor(int value);
    std::vector<int> getNodes();

  // private fields
  private:
    std::vector<int> nodes;

  // private methods
  private:
    void minHeapify(int i);
};

#endif
