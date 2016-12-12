#include <iostream>
#include <vector>
#include "utils.h"
#include "../DataStructures/Deque.h"

using namespace std;

Deque test_constructor(vector<unsigned int> numbers, bool display);
void test_push_front(vector<unsigned int> numbers, bool display);
void test_push_back(vector<unsigned int> numbers, bool display);
void test_successor(vector<unsigned int> numbers, Deque* deque, bool display);
void test_predecessor(vector<unsigned int> numbers, Deque* deque, bool display);
void test_pop_front(Deque deque, bool display);
void test_pop_back(Deque deque, bool display);
void test_extract_min(Deque deque, bool display);

int main(){
  print_header("DEQUE TESTS");

  // request display boolean
  bool display;
  cout << "display? (0/1): ";
  cin >> display;

  // generate a sample vector of numbers for testing
  vector<unsigned int> numbers = generate_numbers(display);
  if (numbers.empty()){
    print_footer();
    return 0;
  }

  // test the deque methods
  Deque deque = test_constructor(numbers, display);
  test_push_front(numbers, display);
  test_push_back(numbers, display);
  test_successor(numbers, &deque, display);
  test_predecessor(numbers, &deque, display);
  test_pop_front(deque, display);
  test_pop_back(deque, display);
  test_extract_min(deque, display);

  print_footer();
  return 0;
}

Deque test_constructor(vector<unsigned int> numbers, bool display){
  cout << endl << "BUILD DEQUE USING VECTOR" << endl;

  // build a deque with the passed vector
  Deque deque = Deque(numbers);

  // display the deque
  if (display){
    deque.display();
  }

  return deque;
}

void test_push_front(vector<unsigned int> numbers, bool display){
  cout << endl << "PUSH FRONT" << endl;

  // initialize and display an empty deque
  Deque deque = Deque();
  if (display){
    deque.display();
  }

  // push and display
  for (int i=0; i<numbers.size(); i++){
    deque.push_front(numbers[i]);
    if (display){
      deque.display();
    }
  }
}

void test_push_back(vector<unsigned int> numbers, bool display){
  cout << endl << "PUSH BACK" << endl;

  // initialize and display an empty deque
  Deque deque = Deque();
  if (display){
    deque.display();
  }

  // push and display
  for (int i=0; i<numbers.size(); i++){
    deque.push_back(numbers[i]);
    if (display){
      deque.display();
    }
  }
}

void test_successor(vector<unsigned int> numbers, Deque* deque, bool display){
  cout << endl << "SUCCESSOR" << endl;

  // display the given deque
  if (display){
    deque->display();
  }

  // retrieve and display successor of each number
  unsigned int successor;
  for (unsigned int i=0; i<numbers.size(); i++){
    successor = deque->successor(numbers[i]);
    if (display){
      cout << "Successor of " << numbers[i] << ": ";
      cout << successor << endl; 
    }
  }
}

void test_predecessor(vector<unsigned int> numbers, Deque* deque, bool display){
  cout << endl << "PREDECESSOR" << endl;

  // display the given deque
  if (display){
    deque->display();
  }

  // retrieve and display predecessor of each number
  unsigned int predecessor;
  for (unsigned int i=0; i<numbers.size(); i++){
    predecessor = deque->predecessor(numbers[i]);
    if (display){
      cout << "Predecessor of " << numbers[i] << ": ";
      cout << predecessor << endl;
    }
  }
}

void test_pop_front(Deque deque, bool display){
  cout << endl << "POP FRONT" << endl;

  // display the given deque
  if (display){
    deque.display();
  }

  // pop and display
  while(!deque.empty()){
    deque.pop_front();
    if (display){
      deque.display();
    }
  }
}

void test_pop_back(Deque deque, bool display){
  cout << endl << "POP BACK" << endl;

  // display the given deque
  if (display){
    deque.display();
  }

  // pop and display
  while(!deque.empty()){
    deque.pop_back();
    if (display){
      deque.display();
    }
  }
}

void test_extract_min(Deque deque, bool display){
  cout << endl << "EXTRACT MIN" << endl;

  // display the given deque
  if (display){
    deque.display();
  }

  // extract and display
  while(!deque.empty()){
    deque.extract_min();
    if (display){
      deque.display();
    }
  }
}




