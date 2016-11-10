test-sort:	test-sort.cpp
		mkdir -p results
		g++ -o test-sort test-sort.cpp ../DataStructures/BinaryHeap.cpp
		./test-sort >> results/test-sort.txt
		rm -f test-sort

test-heap:	test-heap.cpp
		g++ -o test-heap test-heap.cpp ../DataStructures/BinaryHeap.cpp
		./test-heap
		rm -f test-heap
