#include "sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/vEB.h"
#include <vector>

std::vector<int> sort(BinaryHeap* heap)
{
	std::vector<int> result;
	
	while(!(heap->isEmpty()))
		result.push_back(heap->extract());

	return result;
}

// vEB not yet implemented
/*std::vector<int> sort(vEB* vebTree)
{
	std::vector<int> result;

	while(!(vebTree->IsEmpty()))
		result.push_back(vebTree->ExtractMin());

	return result;
}
*/
