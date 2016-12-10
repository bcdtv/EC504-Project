#ifndef DEQUE_H
#define DEQUE_H

#include <deque>
#include <vector>

using namespace std;

class Deque{
  // public methods
  public:
    Deque();
    Deque(vector<int> numbers);
    ~Deque();
    int successor(int value);
    int predecessor(int value);
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int extract_min();
    bool empty();
    vector<int> elements();

  // private fields
  private:
    deque<int>* nodes;
};
#endif
