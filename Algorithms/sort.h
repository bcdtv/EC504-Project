#ifndef SORT_H
#define SORT_H

#include <vector>
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/BST.h"
#include "../DataStructures/Deque.h"
#include "../DataStructures/VEB.h"

using namespace std;

vector<unsigned int> sort(BinaryHeap* heap);
vector<unsigned int> sort(BST* bst);
vector<unsigned int> sort(Deque* deque);
vector<unsigned int> sort(VEB* vEB);

#endif
