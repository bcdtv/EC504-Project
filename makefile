test-sort:	Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/vEB.cpp Tests/test-sort.cpp 
		mkdir -p Tests/results
		g++ -o test-sort Algorithms/sort.cpp DataStructures/BinaryHeap.cpp DataStructures/vEB.cpp Tests/test-sort.cpp 
