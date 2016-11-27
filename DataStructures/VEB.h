#ifndef V_EB_H
#define V_EB_H

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
    int min();
    int max();
    bool empty();
    void display();

  // private fields
  private:
    int min_value;
    int max_value;
    bool is_empty;
    vector<int> summary;
    map<int, VEB> clusters;

  // private methods
  private:
    int get_cluster(int value);
    void insert_helper(VEB* vEB, int value);
    void display_helper(VEB* vEB);
};

#endif
