# EC504-Project

### BinaryHeap
```c++
// construct a binary heap from an input vector
void BinaryHeap::BinaryHeap(std::vector<int> numbers)

// insert a number
void BinaryHeap::insert(int value)

// remove a number
void BinaryHeap::remove(int value)

// extract the minimum element
int BinaryHeap::extract()

// get if the heap is empty
bool BinaryHeap::isEmpty()

// get the next number greater than value
int BinaryHeap::successor(int value)

// get the next number less than value
int BinaryHeap::predecessor(int value)

// get all the nodes in a vector
std::vector<int> BinaryHeap::getNodes()
```

### vEB Tree
```c++
// // construct a vEB Tree from an input vector
void vEB::vEB(std::vector<int> numbers)

// insert a number
void vEB::insert(int value)

// remove a number
void vEB::remove(int value)

// extract the minimum element
int vEB::extract()

// get if the heap is empty
bool vEB::isEmpty()

// get the next number greater than value
int vEB::successor(int value)

// get the next number less than value
int vEB::predecessor(int value)

// get all the nodes in a vector
std::vector<int> vEB::getNodes()
```
### Running Tests
make test-heap
 - test validity of binary heap construction
 - test extract method
 - asks for inputs N, INT_MIN, and INT_MAX
 - prints results to stdout

make test-sort
 - benchmark data structures with sorting algorithm
 - asks for inputs N, INT_MIN, and INT_MAX
 - stores results in Tests/results folder




