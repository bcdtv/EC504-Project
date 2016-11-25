#ifndef V_EB_H
#define V_EB_H

#include <vector>

using namespace std;

class VEB{
  // public fields
  public:
    int min;

  // public methods
  public:
    VEB();
    VEB(vector<int> numbers);
    int successor(int value);
    int predecessor(int value);
    void insert(int value);
    void remove(int value);
    int max();
    bool empty();
    int size();

  // private fields
  private:
    vector<int> summary;
    vector<VEB> clusters;
    vector<int> raw_data;
};

#endif
