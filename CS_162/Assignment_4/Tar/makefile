CC=g++


a.out: driver.cpp game.o Bug.hpp.gch Bee.hpp.gch Ant.hpp.gch Ants.hpp.gch
	g++ driver.cpp game.o Bug.hpp Bee.hpp Ant.hpp Ants.hpp -g

game.o: game.cpp
	g++ game.cpp -g -c

Bug.hpp.gch: Bug.hpp
	g++ Bug.hpp -g -c

Bee.hpp.gch: Bee.hpp
	g++ Bee.hpp -g -c

Ant.hpp.gch: Ant.hpp
	g++ Ant.hpp -g -c

Ants.hpp.gch: Ants.hpp
	g++ Ants.hpp -g -c

clean:
	rm -rf *.o *.gch a.out
