#ifndef V_EB_H
#define V_EB_H

#include <map>

using namespace std;

class VEB{
  // public methods
  public:
    VEB();
    VEB(const VEB& other);
    ~VEB();
    VEB& operator=(const VEB& other);
    unsigned int successor(unsigned int value);
    unsigned int predecessor(unsigned int value);
    void insert(unsigned int value);
    void remove(unsigned int value);
    unsigned int min();
    unsigned int max();
    bool empty();
    unsigned int size();
    vector<unsigned int> elements();
    void display();

  // private fields
  private:
    unsigned int u;
    unsigned int min_value;
    unsigned int min_count;
    unsigned int max_value;
    bool is_empty;
    unsigned int n;
    VEB* summary;
    map<unsigned int, VEB> clusters;

  // private methods
  private:
    VEB(unsigned int u);
    unsigned int successor_helper(VEB* vEB, unsigned int value);
    unsigned int predecessor_helper(VEB* vEB, unsigned int value);
    void insert_helper(VEB* vEB, unsigned int value, unsigned int count);
    bool remove_helper(VEB* vEB, unsigned int value, unsigned int count);
    void elements_helper(VEB* vEB, unsigned int base, vector<unsigned int>* result);
    void display_helper(VEB* vEB, unsigned int base);
};

#endif
