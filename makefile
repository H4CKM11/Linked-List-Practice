a.exe: main.o linked-list.o node.o
	g++ main.o linked-list.o node.o -o a.exe

linked-list.o: linked-list.cpp linked-list.h
	g++ -c linked-list.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	delete *.o a.exe
	