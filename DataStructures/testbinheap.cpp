#include <iostream>
#include <vector>

#include "BinaryHeap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(70);
    v.push_back(60);
    v.push_back(80);
    BinaryHeap b(v);

    b.display();
    cout << b.min << endl;

    return 0;
}