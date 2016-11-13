#ifndef SORT_H
#define SORT_H

#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/vEB.h"
#include <vector>

using namespace std;

vector<int> sort(BinaryHeap* heap);
void display(vector<int>);


// vEB not yet implemented
//std::vector<int> sort(vEB* vebTree);

#endif
