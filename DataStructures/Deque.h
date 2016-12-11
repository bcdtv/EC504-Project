#ifndef DEQUE_H
#define DEQUE_H

#include <list>
#include <vector>

using namespace std;

class Deque{
  // public methods
  public:
    Deque();
    Deque(vector<unsigned int> numbers);
    int successor(int value);
    int predecessor(int value);
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int extract_min();
    bool empty();
    int size();
    vector<int> elements();
    void display();

  // private fields
  private:
    list<int> nodes;
};
#endif
