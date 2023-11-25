output: main.o flighthashtable.o mylist.o flightticket.o
	g++ main.o flighthashtable.o flightticket.o mylist.o -o output
main.o: main.cpp flighthashtable.h flightticket.h mylist.h
	g++ -c main.cpp
flighthashtable.o: flighthashtable.h flighthashtable.cpp
	g++ -c flighthashtable.cpp
mylist.o: mylist.cpp mylist.h
	g++ -c mylist.cpp
flightticket.o: flightticket.cpp flightticket.h
	g++ -c flightticket.cpp
clean:
	rm *.o output