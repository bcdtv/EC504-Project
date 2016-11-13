#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include <vector>

using namespace std;

/*
Because a binary heap is a complete binary tree, it 
can be represented using an array. In this case, we
use the std::vector container in order to allow for dynamic size.
*/

class BinaryHeap{
  // public methods
  public:
    BinaryHeap();
    ~BinaryHeap();
    BinaryHeap(std::vector<int> numbers);
    void insert(int value);
    void remove(int value);
    int extract();  
    bool isEmpty();
    void display();
    std::vector<int> getNodes();
    int min;

  // private fields
  private:
    int getIndex(int value); 
    vector<int> nodes;

  // private methods
  private:
    void minHeapify(int current_i);
};

#endif
