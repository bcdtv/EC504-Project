# EC504-Project

## Code Style
Having some consistancy within the code makes modifying and reading code soo much easier so some guidelines have been listed below. Feel free to code however you like but don't be surprised if modifications are made afterwards in order to comply to guidelines below.  

**Names**  
classes: CapitalizedCamelCase  
variables: underscore_case  
methods: underscore_case  
_reasoning:_ The C++ standard library uses underscore case so we should as well to give the code a consistant look. However, our custom classes are special so those breaking C++ convention make them easier to spot.

**Curly Braces**
int example_method(){
  return 0; 
}
_reasoning:_ Simply preference. Most, if not all, have been changed to this style.

---

## Running Tests
make test-heap
 - test validity of binary heap construction
 - test extract method
 - asks for inputs N, INT_MIN, and INT_MAX
 - prints results to stdout

make test-sort
 - benchmark data structures with sorting algorithm
 - asks for inputs N, INT_MIN, and INT_MAX
 - stores results in Tests/results folder

---
 
## Data Structure API's
### Binary Heap
```c++
// create an empty binary heap
BinaryHeap::BinaryHeap()

// construct a binary heap from an input vector
BinaryHeap::BinaryHeap(std::vector<int> numbers)

// insert a number
void BinaryHeap::insert(int value)

// remove a number
void BinaryHeap::remove(int value)

// extract the minimum element
int BinaryHeap::extractMin()

// get if the heap is empty
bool BinaryHeap::isEmpty()

// get all the nodes in a vector
std::vector<int> BinaryHeap::getNodes()

// destructor
BinaryHeap::~BinaryHeap()
```

### vEB Tree
```c++
// create an empty vEB tree
vEB::vEB()

// construct a vEB Tree from an input vector
vEB::vEB(std::vector<int> numbers)

// insert a number
void vEB::insert(int value)

// remove a number
void vEB::remove(int value)

// extract the minimum element
int vEB::extractMin()

// get if the vEB Tree is empty
bool vEB::isEmpty()

// get the next number greater than value
int vEB::successor(int value)

// get the next number less than value
int vEB::predecessor(int value)

// get all the nodes in a vector
std::vector<int> vEB::getNodes()

// destructor
vEB::~vEB()
```

### Binary Search Tree
```c++
// create an empty Binary Search Tree
BST::BST()

// construct a BST from an input vector
BST::BST(std::vector<int> numbers)

// insert a number
void BST::insert(int value)

// remove a number
void BST::remove(int value)

// extract the minimum element
int BST::extractMin()

// get if the BST is empty
bool BST::isEmpty()

// get the next number greater than value
int BST::successor(int value)

// get the next number less than value
int BST::predecessor(int value)

// get all the nodes in a vector
std::vector<int> BST::getNodes()

// destructor
BST::~BST()
```

### Deque
```c++
// create an empty deque
Deque::Deque()

// construct a Deque from an input vector
Deque::Deque(std::vector<int> numbers)

// insert a number
void Deque::insert(int value)

// remove a number
void Deque::remove(int value)

// extract the minimum element
int Deque::extractMin()

// get if the Deque is empty
bool Deque::isEmpty()

// get the next number greater than value
int Deque::successor(int value)

// get the next number less than value
int Deque::predecessor(int value)

// get all the nodes in a vector
std::vector<int> Deque::getNodes()

// destructor
Deque::~Deque()
```
---






