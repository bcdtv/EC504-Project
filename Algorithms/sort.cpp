#include <iostream>
#include "sort.h"
#include "../DataStructures/BinaryHeap.h"
#include "../DataStructures/vEB.h"
#include <vector>

using namespace std;

vector<int> sort(BinaryHeap* heap)
{
	vector<int> result;
	
	while(!(heap->isEmpty()))
		result.push_back(heap->extract());

	return result;
}

void display(vector<int> sorted_array) {
    cout << "Sorted array contains: ";
    for(int i = 0; i < sorted_array.size(); i++) {
        cout << sorted_array.at(i) << " ";
    }
    cout << endl;
}

// vEB not yet implemented
/*vector<int> sort(vEB* vebTree)
{
	vector<int> result;

	while(!(vebTree->IsEmpty()))
		result.push_back(vebTree->ExtractMin());

	return result;
}
*/
