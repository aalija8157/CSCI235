main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

main.o: main.cpp Node.h
	g++ -c main.cpp

BSTree.o: BSTree.cpp Node.h
	g++ -c BSTree.cpp
