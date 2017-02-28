lab5: main.o PrecondViolatedExcep.o BinarySearchTree.o Node.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o BinarySearchTree.o Node.o -o lab5

main.o: QNode.h QNode.hpp Queue.h Queue.hpp main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
    
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

clean:
	rm *.o lab5
	echo clean done