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
**All**
command: make run-all
 - makes all test binaries
 - runs all test binaries in order below

**Binary Heap**  
command: make test-heap  
 - asks for display option, set display off for large values of N
 - asks for inputs N, MIN_INT, and MAX_INT to generate array of random numbers
 - tests binary heap methods for correctness
 - each method is tested seperately
 - prints results to stdout

**Binary Search Tree**  
command: make test-bst  
 - asks for display option, set display off for large values of N
 - asks for inputs N, MIN_INT, and MAX_INT to generate array of random numbers
 - tests binary search tree methods for correctness
 - each method is tested seperately
 - prints results to stdout

**Deque**  
command: make test-deque  
 - asks for display option, set display off for large values of N
 - asks for inputs N, MIN_INT, and MAX_INT to generate array of random numbers
 - tests deque methods for correctness
 - each method is tested seperately
 - prints results to stdout

**VEB Tree**  
command: make test-veb  
 - asks for display option, set display off for large values of N
 - asks for inputs N, MIN_INT, and MAX_INT to generate array of random numbers
 - tests vEB tree methods for correctness
 - each method is tested seperately
 - prints results to stdout

**Sorting Benchmarks**  
command: make test-sort  
 - asks for display option, set display off for large values of N
 - asks for data structures to be tested
 - asks for inputs N, MIN_INT, and MAX_INT to generate array of random numbers
 - times how long it takes to store the random numbers in each requested data structure
 - times how long it takes to return a sorted array from each requested data structure
 - prints results to stdout

---
 
## Data Structure API's
### Binary Heap
```c++
// create an empty binary heap
BinaryHeap();

// construct a binary from an input vector
BinaryHeap(vector<unsigned int> numbers);

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

### Binary Search Tree
```c++
// create a binary search tree with default value 0
BST()

// create a binary search tree with given value
BST(int value);

// copy constructor for deep copying another BST
BST(const BST& other);

// destructor for cleaning up dynamic memory
~BST();

// copy assignment operator for deep copying another BST
BST& operator=(const BST& other);

// get the next number greater than value
int successor(int value);

// get the next number less than value
int predecessor(int value);

// insert a number
void insert(int value); 

// remove a number
void remove(int value);

// get the minimum element within the tree
int min();

// get the maximum element within the tree
int max();

// print the tree elements to stdout
void display();

// checks if the tree is a proper binary search tree
bool valid();
```

### Deque
```c++
// create an empty deque
Deque();

// construct a deque from an input vector
Deque(vector<unsigned int> numbers);

// get the next number greater than value
int successor(int value);

// get the next number less than value
int predecessor(int value);

// push a number onto the front
void push_front(int value);

// push a number onto the back
void push_back(int value);

// pop a number from the front
int pop_front();

// pop a number from the back
int pop_back();

// extract the minimum element
int extract_min();

// get if the deque is empty
bool empty();

// returns the number of elements in the deque
int size();

// get all the elements stored in the deque
vector<int> elements();

// print the values within the deque to stdout
void display();
```

### vEB Tree
```c++
// construct an empty vEB tree
VEB();

// create a new vEB tree by copying another
VEB(const VEB& other);

// destroy a vEB tree
~VEB();

// replace a vEB tree with the values of another
VEB& operator=(const VEB& other);

// get the next number greater than value
unsigned int successor(unsigned int value);

// get the next number less than value
unsigned int predecessor(unsigned int value);

// insert a number
void insert(unsigned int value);

// get the min value within the vEB tree
unsigned int min();

// get the max value within the vEB tree
unsigned int max();

// returns true if the vEB tree is empty
bool empty();

// the number of elements stored in the vEB tree
unsigned int size();

// retrieve the elements stored in the vEB tree
vector<unsigned int> elements();

// prints the vEB tree values to stdout
void display();
```

---






