#ifndef SORT_H
#define SORT_H

#include <vector>
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/VEB.h"

using namespace std;

vector<int> sort(BinaryHeap* heap);
vector<int> sort(VEB* vEB, int method);

#endif
