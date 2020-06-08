main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o

tests: tests.o List.o Node.o
	g++ -o tests tests.o List.o Node.o

tests.o: tests.cpp
	g++ -c tests.cpp

List.o: List.cpp
	g++ -c List.cpp

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.cpp
	g++ -c Node.cpp
