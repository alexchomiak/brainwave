test: main.o
	g++ -o test main.o -std=c++11
main.o: main.cpp
	g++ -c main.cpp -std=c++11
clean:
	rm test main.o
