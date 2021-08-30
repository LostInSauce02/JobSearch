Circles: main.o CircleDriver.o Circle.o
	g++ -std=c++11 -g -Wall main.o CircleDriver.o Circle.o -o Circles

main.o: main.cpp CircleDriver.h Circle.h
	g++ -std=c++11 -g -Wall -c main.cpp

Circle.o: Circle.h Circle.cpp
	g++ -std=c++11 -g -Wall -c Circle.cpp

CircleDriver.o: CircleDriver.h CircleDriver.cpp
	g++ -std=c++11 -g -Wall -c CircleDriver.cpp

clean:
	rm *.o Circles
