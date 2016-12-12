#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deque.h"

using namespace std;

// ============ Public Method Implementations ============
// Default constructor for creating an
// empty deque.
Deque::Deque(){
}

// Construct a deque from an input vector.
Deque::Deque(vector<unsigned int> numbers){
  for(int i = 0; i < numbers.size(); i++){
    nodes.push_back(numbers[i]);
  }
}

// Get the next number within the deque that
// is greater than the passed value.
int Deque::successor(int value){
  int successor = INT_MAX;

  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    if(*it > value && *it < successor){
      successor = *it;
    }
  }

  if (successor == INT_MAX){
    return value;
  }

  return successor;
}

// Get the next number within the deque that
// is less than the passed value.
int Deque::predecessor(int value){
  int predecessor = INT_MIN;

  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    if(*it < value && *it > predecessor){
      predecessor = *it;
    }
  }

  if (predecessor == INT_MIN){
    return value;
  }

  return predecessor;
}

// Push a number onto the front of the deque.
void Deque::push_front(int value){
  nodes.push_front(value);
}

// Push a number onto the back of the deque.
void Deque::push_back(int value){
  nodes.push_back(value);
}

// Pop a number from the front of the deque.
int Deque::pop_front(){
  if(nodes.size() == 0){
    throw -1;
  }
  int result = nodes.front();
  nodes.pop_front();
  return result;
}

// Pop a number from the back of the deque.
int Deque::pop_back(){
  if(nodes.size() == 0){
    throw -1;
  }
  int result = nodes.back();
  nodes.pop_back();
  return result;
}

// Extract the minimum element from the deque.
int Deque::extract_min(){
  int min = INT_MAX;
  int min_index = 0, i = 0;
  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    if(*it < min){
      min = *it;
      min_index = i;
    }
    i++;
  }
  list<int>::iterator position = nodes.begin();
  advance(position, min_index);
  nodes.erase(position);
  return min;
}

// Returns true if the deque is empty.
bool Deque::empty(){
  return nodes.size() == 0;
}

// Get the number of elements in the deque.
int Deque::size(){
  return nodes.size();
}

// Get all the values stored in the deque.
vector<int> Deque::elements(){
  vector<int> result;
  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    result.push_back(*it);
  }
  return result;
}

// Print all the values in the deque to stdout.
void Deque::display(){
  cout << "Deque: ";
  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    cout << *it << " ";
  }
  cout << endl;
}
// =======================================================


