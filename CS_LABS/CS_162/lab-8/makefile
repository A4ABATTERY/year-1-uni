CC = g++
EXE = a.out

$(EXE): try_vectors.cpp vectors.o
	g++ try_vectors.cpp vectors.hpp -o $(EXE)
vectors.o: vectors.hpp
	g++ vectors.hpp -c
