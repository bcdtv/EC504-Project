#include "sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/vEB.h"
#include <vector>

vector<int> sort(BinaryHeap* heap)
{
	vector<int> result;
	
	while(!(heap->IsEmpty()))
		result.push_back(heap->ExtractMin());

	return result;
}

vector<int> sort(vEB* vebTree)
{
	vector<int> result;

	while(!(vebTree->IsEmpty()))
		result.push_back(vebTree->ExtractMin());

	return result;
}
