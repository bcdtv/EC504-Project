#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deque.h"

using namespace std;

// ============ Public Method Implementations ============
// create an empty deque
Deque::Deque(){

}

// construct a deque from an input vector
Deque::Deque(vector<unsigned int> numbers){
  for(int i = 0; i < numbers.size(); i++){
    nodes.push_back(numbers[i]);
  }
}

// get the next number greater than value (does not pop)
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

// get the next number less than value (does not pop)
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

// push a number onto the front
void Deque::push_front(int value){
  nodes.push_front(value);
}

// push a number onto the back
void Deque::push_back(int value){
  nodes.push_back(value);
}

// pop a number from the front
int Deque::pop_front(){
  if(nodes.size() == 0){
    throw -1;
  }
  int result = nodes.front();
  nodes.pop_front();
  return result;
}

// pop a number from the back
int Deque::pop_back(){
  if(nodes.size() == 0){
    throw -1;
  }
  int result = nodes.back();
  nodes.pop_back();
  return result;
}

// extract the minimum element
int Deque::extract_min(){
  int min = INT_MAX;
  int min_index = 0;
  int i = 0;
  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    if(*it < min)
    {
      min = *it;
      min_index = i;
    }
    i++;
  }
  list<int>::iterator position = nodes.begin();
  advance(position, i - 1);
  nodes.erase(position);
  return min;
}

// get if the deque is empty
bool Deque::empty(){
  return nodes.size() == 0;
}

// get the number of elements in the deque
int Deque::size(){
  return nodes.size();
}

// get all the nodes in a vector
vector<int> Deque::elements(){
  vector<int> result;
  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    result.push_back(*it);
  }
  return result;
}

void Deque::display(){
  cout << "Deque: ";
  for(list<int>::iterator it = nodes.begin(); it != nodes.end(); it++){
    cout << *it << " ";
  }
  cout << endl;
}
// =======================================================


