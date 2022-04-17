run: Source.o functions.o
	g++ Source.cpp functions.cpp -o run

functions.o: functions.cpp
	g++ -c functions.cpp

Source.o: Source.cpp
	g++ -c Source.cpp

clean: rm *.o run