#ifndef SORT_H
#define SORT_H

#include <vector>
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/VEB.h"

using namespace std;

vector<unsigned int> sort(BinaryHeap* heap);
vector<unsigned int> sort(VEB* vEB);

#endif
