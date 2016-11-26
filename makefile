test-sort:	Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/VEB.cpp Tests/test-sort.cpp 
		mkdir -p Tests/results
		g++ -o test-sort Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/VEB.cpp Tests/test-sort.cpp

test-heap:	DataStructures/BinaryHeap.cpp Tests/test-heap.cpp
		g++ -o test-heap DataStructures/BinaryHeap.cpp Tests/test-heap.cpp 

test-veb:	DataStructures/VEB.cpp Tests/test-veb.cpp
		g++ -o test-veb DataStructures/VEB.cpp Tests/test-veb.cpp

clean:
	rm -f test-sort
	rm -f test-heap
	rm -f test-veb
