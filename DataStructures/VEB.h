#ifndef V_EB_H
#define V_EB_H

#include <cmath>
#include <map>
#include <vector>

using namespace std;

class VEB{
  // public methods
  public:
    VEB();
    VEB(vector<int> numbers);
    int successor(int value);
    int predecessor(int value);
    void insert(int value);
    void remove(int value);
    bool empty();
    int size();
    void display();

  // private fields
  private:
    int min;
    int max;
    bool is_empty;
    int size;
    vector<int> summary;
    map<int, VEB> clusters;

  // private methods
  private:
    int low(int value);
    int high(int value);
    void insert_helper(VEB* vEB, int value);
    void display_helper(VEB* vEB);
};

#endif
