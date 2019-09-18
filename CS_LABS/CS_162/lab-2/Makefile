CC = G++

EXE = a.out

$(EXE): student_db.o driver.cpp
	g++ student_db.o driver.cpp -o $(EXE)

student_db.o: student_db.cpp student_db.h
	g++ student_db.cpp -c

clear:
	rm -rf *.o $(EXE)
