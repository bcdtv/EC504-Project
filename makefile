test-sort:	Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/VEB.cpp Tests/test-sort.cpp 
		mkdir -p Tests/results
		g++ -o test-sort Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/VEB.cpp Tests/test-sort.cpp

test-heap:	DataStructures/BinaryHeap.cpp Tests/test-heap.cpp
		g++ -o test-heap DataStructures/BinaryHeap.cpp Tests/test-heap.cpp 

test-veb:	DataStructures/VEB.cpp Tests/test-veb.cpp
		g++ -o test-veb DataStructures/VEB.cpp Tests/test-veb.cpp

test-bst:	DataStructures/BST.cpp Tests/test-bst.cpp
		g++ -o test-bst DataStructures/BST.cpp Tests/test-bst.cpp

test-deque:	DataStructures/Deque.cpp Tests/test-deque.cpp
		g++ -o test-deque DataStructures/Deque.cpp Tests/test-deque.cpp

clean:
	rm -f test-sort
	rm -f test-heap
	rm -f test-veb
	rm -f test-bst
	rm -f test-deque
