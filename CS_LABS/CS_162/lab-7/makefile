CC = g++

EXE = a.out

$(EXE): Driver.cpp Class.o
	g++ Driver.cpp Class.o -o $(EXE)
Class.o: Class.cpp Class.h
	g++ Class.cpp -c
clean:
	rm -rf *.o $(EXE)
