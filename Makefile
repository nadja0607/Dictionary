all: main.o functions.o 
	g++ main.o functions.o -o mydictionary
main.o: main.cpp
	g++ -c main.cpp
functions.o: functions.h functions.cpp
	g++ -c functions.cpp
clean:
	rm *.o output

