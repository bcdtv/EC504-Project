#ifndef DEQUE_H
#define DEQUE_H

#include <deque>
#include <vector>

using namespace std;

class Deque{
  // public methods
  public:
    Deque();
    Deque(vector<unsigned int> numbers);
    Deque(const Deque& other);
    ~Deque();
    Deque& operator=(const Deque& other);
    int successor(int value);
    int predecessor(int value);
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int extract_min();
    bool empty();
    vector<int> elements();
    void display();

  // private fields
  private:
    deque<int>* nodes;
};
#endif
