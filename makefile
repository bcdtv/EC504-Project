test-sort:	Tests/test-sort.cpp DataStructures/BinaryHeap.cpp
		mkdir -p Tests/results
		g++ -o test-sort Tests/test-sort.cpp DataStructures/BinaryHeap.cpp
		./test-sort >> Tests/results/test-sort.txt
		rm -f test-sort

test-heap:	Tests/test-heap.cpp DataStructures/BinaryHeap.cpp
		g++ -o test-heap Tests/test-heap.cpp DataStructures/BinaryHeap.cpp
		./test-heap
		rm -f test-heap
