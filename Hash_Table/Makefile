OBJ = hash_table.o Node.o person.o

main: main.o Node.o $(OBJ)
	g++ -o main main.o $(OBJ)

hash_table.o: hash_table.cpp
	g++ -c hash_table.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

person.o: person.cpp
	g++ -c person.cpp

tests: tests.o $(OBJ)
	g++ -o tests tests.o $(OBJ)

main.o: main.cpp
	g++ -c main.cpp

tests.o: tests.cpp


clean:
	rm -f main.o tests.o
