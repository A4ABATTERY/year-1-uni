CC = g++
EXE = a.out
$(EXE): functions.o class-restaurant.o class-menu.o class-pizza.o driver.cpp
	g++ functions.o class-restaurant.o class-menu.o class-pizza.o driver.cpp -o $(EXE)
functions.o: functions.cpp
	g++ functions.cpp -c
class-restaurant.o: class-restaurant.cpp
	g++ class-restaurant.cpp -c
class-menu.o: class-menu.cpp
	g++ class-menu.cpp -c
class-pizza.o: class-pizza.cpp
	g++ class-pizza.cpp -c
clean:
	rm -rf *.o $(EXE)
