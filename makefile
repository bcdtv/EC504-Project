test-sort:	Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/vEB.cpp Tests/test-sort.cpp 
		mkdir -p Tests/results
		g++ -o test-sort Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/vEB.cpp Tests/test-sort.cpp 
		./test-sort >> Tests/results/test-sort.txt
		rm -f test-sort

test-heap:	Tests/test-heap.cpp DataStructures/BinaryHeap.cpp
		g++ -o test-heap Tests/test-heap.cpp DataStructures/BinaryHeap.cpp
		./test-heap
		rm -f test-heap
