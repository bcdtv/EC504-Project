test-sort:	Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/VEB.cpp \
		DataStructures/BST.cpp DataStructures/Deque.cpp Tests/test-sort.cpp
		mkdir -p Tests/results
		g++ -std=c++0x -o test-sort Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/VEB.cpp \
		DataStructures/BST.cpp DataStructures/Deque.cpp Tests/test-sort.cpp

test-heap:	DataStructures/BinaryHeap.cpp Tests/test-heap.cpp
		g++ -std=c++0x -o test-heap DataStructures/BinaryHeap.cpp Tests/test-heap.cpp 

test-veb:	DataStructures/VEB.cpp Tests/test-veb.cpp
		g++ -std=c++0x -o test-veb DataStructures/VEB.cpp Tests/test-veb.cpp

test-bst:	DataStructures/BST.cpp Tests/test-bst.cpp
		g++ -std=c++0x -o test-bst DataStructures/BST.cpp Tests/test-bst.cpp

test-deque:	DataStructures/Deque.cpp Tests/test-deque.cpp
		g++ -std=c++0x -o test-deque DataStructures/Deque.cpp Tests/test-deque.cpp

clean:
	rm -f test-sort
	rm -f test-heap
	rm -f test-veb
	rm -f test-bst
	rm -f test-deque
