CC = g++

EXE = a.out

$(EXE): driver.cpp business.o apartment.o house.o building.o Player.o
	g++ driver.cpp  business.o apartment.o house.o building.o Player.o -g -o $(EXE)

apartment.o: apartment.cpp
	g++ apartment.cpp -g -c

house.o: house.cpp
	g++ house.cpp -g -c

business.o: business.cpp
	g++ business.cpp -g -c

building.o: building.cpp
	g++ building.cpp -g -c

Player.o: Player.cpp
	g++ Player.cpp -g -c

clean:
	rm -rf *.o $(EXE)
