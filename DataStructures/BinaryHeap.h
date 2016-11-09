#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>

/* 
   The class creates nodes in dynamic memory using the new keyword.
   Therefore, the class requires a destructor in order to clean up
   the nodes with the delete keyword. Because the class requires 
   a destructor, in order to follow the "C++ Rule of Three", the 
   class also defines a copy constructor and a copy assignment
   operator.
*/

class BinaryHeap{
  // inner classes
  private:
    class Node{
      // public fields
      public:
        int value;
        Node* parent;
        Node* left;
        Node* right;
      // public methods
      public:
        Node();
        Node(int value);
    };

  // public methods
  public:
    BinaryHeap();
    BinaryHeap(vector<int> numbers);
    BinaryHeap(BinaryHeap& other);
    ~BinaryHeap();
    BinaryHeap& operator=(const BinaryHeap& other);
    int extract();
    void insert(int value);

  // private fields
  private:
    Node* root;

  // private methods
  private:
    void minHeapify(Node* node);
};

#endif
