# EC504-Project

## Code Style
Code style consistency makes modifying and reading code soo much easier. Therefore, some guidelines have been listed below. Feel free to code however you like but don't be surprised if modifications are made afterwards in order to comply to the guidelines below.  

**Indentations**  
two spaces  
_reasoning:_ Two, because keeping code width small makes it more readable. Spaces, because tabs are platform dependent and also wider.

**Names**  
classes: CapitalizedCamelCase  
variables: underscore_case  
methods: underscore_case  
_reasoning:_ The C++ standard library uses underscore case so we should as well in order to give the code a consistent look. However, our custom classes are special, so those breaking C++ convention make them easier to spot.

**Curly Braces**
```c++
int example_method(){
  return 0; 
}
```
_reasoning:_ Simply preference. Most, if not all, have been changed to this style.

---

## Running Tests
**Binary Heap**  
command: make test-heap  
 - asks for inputs N, INT_MIN, and INT_MAX
 - tests binary heap methods for correctness
 - each method is tested seperately
 - prints results to stdout

**Sorting Benchmarks**  
command: make test-sort  
 - asks for inputs N, INT_MIN, and INT_MAX
 - times how long it takes to sort an array of numbers
 - repeated for each data structure
 - stores results in Tests/results folder

---
 
## Data Structure API's
### Binary Heap
```c++
// create an empty binary heap
BinaryHeap();

// construct a binary from an input vector
BinaryHeap(vector<int> numbers);

// insert a number
void insert(int value);

// remove a number
void remove(int value);

// extract the minimum element
int extract_min();

// returns true if the heap is empty
bool empty();

// returns the size of the heap
int size();

// prints the heap values to stdout
void display();

// checks if the heap maintains the min heap property
bool valid();
```

### vEB Tree
```c++
// construct an empty vEB tree
VEB();

// construct a vEB tree from an input vector
VEB(vector<int> numbers);

// get the next number greater than value
int successor(int value);

// get the next number less than value
int predecessor(int value);

// insert a number
void insert(int value);

// remove a number
void remove(int value);

// get the min value within the vEB tree
int min();

// get the max value within the vEB tree
int max();

// returns true if the vEB tree is empty
bool empty();

// prints the vEB tree values to stdout
void display();
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






