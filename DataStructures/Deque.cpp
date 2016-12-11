#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deque.h"

using namespace std;

// ============ Public Method Implementations ============
// create an empty deque
Deque::Deque(){
  nodes = new deque<int>();
}

// construct a deque from an input vector
Deque::Deque(vector<unsigned int> numbers){
  nodes = new deque<int>();
  for(int i = 0; i < numbers.size(); i++){
    nodes->push_back(numbers[i]);
  }
}

// copy constructor
Deque::Deque(const Deque& other){
  nodes = new deque<int>();
  for (int i=0; i<other.nodes->size(); i++){
    push_back(other.nodes->at(i));
  }
}

// destructor
Deque::~Deque(){
  delete nodes;
}

// copy assignment operator
Deque& Deque::operator=(const Deque& other){
  delete nodes;
  nodes = new deque<int>();
  for (int i=0; i<other.nodes->size(); i++){
    push_back(other.nodes->at(i));
  }
  return *this;
}

// get the next number greater than value (does not pop)
int Deque::successor(int value){
  int successor = INT_MAX;

  for(int i=0; i<nodes->size(); i++){
    if((nodes->at(i) > value) && (nodes->at(i) < successor) ){
      successor = nodes->at(i);
    }
  }

  if (successor == INT_MAX){
    return value;
  }

  return successor;
}

// get the next number less than value (does not pop)
int Deque::predecessor(int value){
  int predecessor = INT_MIN;

  for(int i=0; i<nodes->size(); i++){
    if((nodes->at(i) < value) && (nodes->at(i) > predecessor)){
      predecessor = nodes->at(i);
    }
  }

  if (predecessor == INT_MIN){
    return value;
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
  int min = INT_MAX;
  int min_index = 0;
  for(int i=0; i<nodes->size(); i++){
    if(nodes->at(i) < min){
      min = nodes->at(i);
      min_index = i;
    }
  }
  nodes->erase(nodes->begin() + min_index);
  return min;
}

// get if the deque is empty
bool Deque::empty(){
  return nodes->size() == 0;
}

// get the number of elements in the deque
int Deque::size(){
  return nodes->size();
}

// get all the nodes in a vector
vector<int> Deque::elements(){
  vector<int> result;
  for(int i=0; i<nodes->size(); i++){
    result.push_back(nodes->at(i));
  }
  return result;
}

void Deque::display(){
  cout << "Deque: ";
  for (int i=0; i<nodes->size(); i++){
    cout << nodes->at(i) << " ";
  }
  cout << endl;
}
// =======================================================

