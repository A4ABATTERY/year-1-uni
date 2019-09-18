CC = g++
EXE = a.out
$(EXE): Functions.o driver.cpp
	g++ Functions.o driver.cpp -o $(EXE)
Functions.o: Functions.cpp Functions.h
	g++ Functions.cpp -c
clean:
	rm -rf *.o $(EXE)
