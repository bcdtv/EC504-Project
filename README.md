# EC504-Project

### BinaryHeap
```c++
// construct a binary heap from an input array
void BinaryHeap::BinaryHeap(vector<int> numbers)

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
```

### vEB Tree
```c++
// default constructor
vEB::vEB()

// insert a number into vEB
// param value: number to insert
void vEB::Insert(int value)
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




