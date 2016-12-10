#include <cstdlib>
#include <limits>
#include "deque.h"

using namespace std;

// ============ Public Method Implementations ============
// create an empty deque
Deque::Deque(){
  nodes = new deque<int>();
}

// construct a deque from an input vector
Deque::Deque(vector<int> numbers){
  nodes = new deque<int>();

  for(int i = 0; i < numbers.size(); i++){
    nodes->push_back(numbers[i]);
  }
}

// destructor
Deque::~Deque(){
  delete(nodes);
}

// get the next number greater than value (does not pop)
int Deque::successor(int value){
  int successor = value;
  int minDiff = numeric_limits<int>::max();

  for(int i = 0; i < nodes->size(); i++){
    if((*nodes)[i] > value){
      int diff = (*nodes)[i] - value;
      if(diff < minDiff){
        minDiff = diff;
        successor = (*nodes)[i];
      }
    }
  }

  if(successor == value){
    throw -1;
  }

  return successor;
}

// get the next number less than value (does not pop)
int Deque::predecessor(int value){
  int predecessor = value;
  int minDiff = numeric_limits<int>::max();

  for(int i = 0; i < nodes->size(); i++){
    if((*nodes)[i] < value){
      int diff = value - (*nodes)[i];
      if(diff < minDiff){
        minDiff = diff;
        predecessor = (*nodes)[i];
      }
    }
  }

  if(predecessor == value){
    throw -1;
  }

  return predecessor;
}

// push a number onto the front
void Deque::push_front(int value){
  nodes->push_front(value);
}

// push a number onto the back
void Deque::push_back(int value){
  nodes->push_back(value);
}

// pop a number from the front
int Deque::pop_front(){
  if(nodes->size() == 0){
    throw -1;
  }

  int result = nodes->front();

  nodes->pop_front();

  return result;
}

// pop a number from the back
int Deque::pop_back(){
  if(nodes->size() == 0){
    throw -1;
  }

  int result = nodes->back();

  nodes->pop_back();

  return result;
}

// extract the minimum element
int Deque::extract_min(){
  int min = numeric_limits<int>::min();
  int minIndex = 0;

  // not necessarily sorted, linear search
  for(int i = 0; i < nodes->size(); i++){
    if((*nodes)[i] < min){
      min = (*nodes)[i];
      minIndex = 0;
    }
  }

  nodes->erase(nodes->begin() + minIndex);

  return min;
}

// get if the deque is empty
bool Deque::empty(){
  return nodes->size() == 0;
}

// get all the nodes in a vector
vector<int> Deque::elements(){
  vector<int> result;

  for(int i = 0; i < nodes->size(); i++){
    result.push_back(nodes->front());
    nodes->pop_front();
  }

  return result;
}
// =======================================================


